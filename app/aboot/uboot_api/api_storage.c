/*
 * (C) Copyright 2007-2008 Semihalf
 *
 * Written by: Rafal Jaworowski <raj@semihalf.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

//#include <config.h>
//#include <common.h>
#include <debug.h>
#include <api_public.h>
#include <lib/bio.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>
#include <printf.h>
#include "uboot_part.h"




#define ENUM_IDE	0
#define ENUM_USB	1
#define ENUM_SCSI	2
#define ENUM_MMC	3
#define ENUM_SATA	4
#define ENUM_MAX	5

struct stor_spec {
	int		max_dev;
	int		enum_started;
	int		enum_ended;
	int		type;		/* "external" type: DT_STOR_{IDE,USB,etc} */
	char		*name;
};

static struct stor_spec specs[ENUM_MAX] = { { 0, 0, 0, 0, "" }, };

static block_dev_desc_t* mmc_devices = NULL;

block_dev_desc_t *get_dev(const char *ifname, int dev) {
	if(strcmp(ifname, "mmc")==0) {
		if(dev>specs[ENUM_MMC].max_dev-1)
			return NULL;

		return &mmc_devices[dev];
	}

	return NULL;
}

static unsigned long dev_mmc_block_read(int dev, lbaint_t start, lbaint_t blkcnt, void *buffer) {
	block_dev_desc_t *ubootdev = get_dev("mmc", dev);
	if(!ubootdev || !ubootdev->biodev)
		return API_EIO;

	bio_read_block(ubootdev->biodev, buffer, start, blkcnt);

	return 0;
}

static unsigned long dev_mmc_block_write(int dev, lbaint_t start, lbaint_t blkcnt, const void *buffer) {
	block_dev_desc_t *ubootdev = get_dev("mmc", dev);
	if(!ubootdev || !ubootdev->biodev)
		return API_EIO;

	bio_write_block(ubootdev->biodev, buffer, start, blkcnt);

	return 0;
}

void bio_foreach_cb(const char* name) {
	int id = specs[ENUM_MMC].max_dev++;
	mmc_devices = realloc(mmc_devices, specs[ENUM_MMC].max_dev*sizeof(*mmc_devices));

	bdev_t* dev = bio_open(name);
	ASSERT(dev);

	mmc_devices[id].name = dev->name;
	mmc_devices[id].type = DEV_TYPE_HARDDISK;
	mmc_devices[id].blksz = dev->block_size;
	mmc_devices[id].lba = dev->size/mmc_devices[id].blksz;
	mmc_devices[id].biodev = NULL;
	mmc_devices[id].block_read = &dev_mmc_block_read;
	mmc_devices[id].block_write = &dev_mmc_block_write;

	bio_close(dev);
}

void dev_stor_init(void)
{
	specs[ENUM_MMC].max_dev = 0;
	specs[ENUM_MMC].enum_started = 0;
	specs[ENUM_MMC].enum_ended = 0;
	specs[ENUM_MMC].type = DEV_TYP_STOR | DT_STOR_MMC;
	specs[ENUM_MMC].name = "mmc";

	bio_foreach(&bio_foreach_cb, false);
}

void dev_stor_scan_devices(void)
{
	if(mmc_devices) {
		free(mmc_devices);
		mmc_devices = NULL;
	}

	dev_stor_init();
}


/*
 * Finds next available device in the storage group
 *
 * type:	storage group type - ENUM_IDE, ENUM_SCSI etc.
 *
 * first:	if 1 the first device in the storage group is returned (if
 *              exists), if 0 the next available device is searched
 *
 * more:	returns 0/1 depending if there are more devices in this group
 *		available (for future iterations)
 *
 * returns:	0/1 depending if device found in this iteration
 */
static int dev_stor_get(int type, int first, int *more, struct uboot_device_info *di)
{
	int found = 0;
	*more = 0;

	int i;

	block_dev_desc_t *dd;

	if (first) {
		di->cookie = (void *)get_dev(specs[type].name, 0);
		if (di->cookie == NULL)
			return 0;
		else {
			found = 1;
			if(1<specs[type].max_dev)
				*more = 1;
		}
	} else {
		for (i = 0; i < specs[type].max_dev; i++)
			if (di->cookie == (void *)get_dev(specs[type].name, i)) {
				/* previous cookie found -- advance to the
				 * next device, if possible */

				if (++i >= specs[type].max_dev) {
					/* out of range, no more to enum */
					di->cookie = NULL;
					break;
				}

				di->cookie = (void *)get_dev(specs[type].name, i);
				if (di->cookie == NULL)
					return 0;
				else
					found = 1;

				/* provide hint if there are more devices in
				 * this group to enumerate */
				if ((i + 1) < specs[type].max_dev)
					*more = 1;

				break;
			}
	}

	if (found) {
		di->type = specs[type].type;

		if (di->cookie != NULL) {
			dd = (block_dev_desc_t *)di->cookie;
			if (dd->type == DEV_TYPE_UNKNOWN) {
				dprintf(SPEW, "device instance exists, but is not active..");
				found = 0;
			} else {
				di->di_stor.block_count = dd->lba;
				di->di_stor.block_size = dd->blksz;
			}
		}

	} else
		di->cookie = NULL;

	return found;
}


/*
 * returns:	ENUM_IDE, ENUM_USB etc. based on block_dev_desc_t
 */
static int dev_stor_type(block_dev_desc_t *dd)
{
	int i, j;

	for (i = ENUM_IDE; i < ENUM_MAX; i++)
		for (j = 0; j < specs[i].max_dev; j++)
			if (dd == get_dev(specs[i].name, j))
				return i;

	return ENUM_MAX;
}


/*
 * returns:	0/1 whether cookie points to some device in this group
 */
static int dev_is_stor(int type, struct uboot_device_info *di)
{
	return (dev_stor_type(di->cookie) == type) ? 1 : 0;
}


static int dev_enum_stor(int type, struct uboot_device_info *di)
{
	int found = 0, more = 0;

	dprintf(SPEW, "called, type %d\n", type);

	/*
	 * Formulae for enumerating storage devices:
	 * 1. if cookie (hint from previous enum call) is NULL we start again
	 *    with enumeration, so return the first available device, done.
	 *
	 * 2. if cookie is not NULL, check if it identifies some device in
	 *    this group:
	 *
	 * 2a. if cookie is a storage device from our group (IDE, USB etc.),
	 *     return next available (if exists) in this group
	 *
	 * 2b. if it isn't device from our group, check if such devices were
	 *     ever enumerated before:
	 *     - if not, return the first available device from this group
	 *     - else return 0
	 */

	if (di->cookie == NULL) {

		dprintf(SPEW, "group%d - enum restart\n", type);

		/*
		 * 1. Enumeration (re-)started: take the first available
		 * device, if exists
		 */
		found = dev_stor_get(type, 1, &more, di);
		specs[type].enum_started = 1;

	} else if (dev_is_stor(type, di)) {

		dprintf(SPEW, "group%d - enum continued for the next device\n", type);

		if (specs[type].enum_ended) {
			dprintf(SPEW, "group%d - nothing more to enum!\n", type);
			return 0;
		}

		/* 2a. Attempt to take a next available device in the group */
		found = dev_stor_get(type, 0, &more, di);

	} else {

		if (specs[type].enum_ended) {
			dprintf(SPEW, "group %d - already enumerated, skipping\n", type);
			return 0;
		}

		dprintf(SPEW, "group%d - first time enum\n", type);

		if (specs[type].enum_started == 0) {
			/*
			 * 2b.  If enumerating devices in this group did not
			 * happen before, it means the cookie pointed to a
			 * device frome some other group (another storage
			 * group, or network); in this case try to take the
			 * first available device from our group
			 */
			specs[type].enum_started = 1;

			/*
			 * Attempt to take the first device in this group:
			 *'first element' flag is set
			 */
			found = dev_stor_get(type, 1, &more, di);

		} else {
			dprintf(SPEW, "group%d - out of order iteration\n", type);
			found = 0;
			more = 0;
		}
	}

	/*
	 * If there are no more devices in this group, consider its
	 * enumeration finished
	 */
	specs[type].enum_ended = (!more) ? 1 : 0;

	if (found)
		dprintf(SPEW, "device found, returning cookie 0x%08x\n",
			(uint32_t)di->cookie);
	else
		dprintf(SPEW, "no device found\n");

	return found;
}

void dev_enum_reset(void)
{
	int i;

	for (i = 0; i < ENUM_MAX; i ++) {
		specs[i].enum_started = 0;
		specs[i].enum_ended = 0;
	}
}

int dev_enum_storage(struct uboot_device_info *di)
{
	int i;

	/*
	 * check: ide, usb, scsi, mmc
	 */
	for (i = ENUM_IDE; i < ENUM_MAX; i ++) {
		if (dev_enum_stor(i, di))
			return 1;
	}

	return 0;
}

static int dev_stor_is_valid(int type, block_dev_desc_t *dd)
{
	int i;

	for (i = 0; i < specs[type].max_dev; i++)
		if (dd == get_dev(specs[type].name, i))
			if (dd->type != DEV_TYPE_UNKNOWN)
				return 1;

	return 0;
}


int dev_open_stor(void *cookie)
{
	int type = dev_stor_type(cookie);
	block_dev_desc_t* ubootdev = cookie;

	if (type == ENUM_MAX)
		return API_ENODEV;

	if (!dev_stor_is_valid(type, ubootdev))
		return API_ENODEV;

	ubootdev->biodev = bio_open(ubootdev->name);
	if(!ubootdev->biodev)
		return API_ENODEV;

	return 0;
}


int dev_close_stor(void *cookie)
{
	int type = dev_stor_type(cookie);
	block_dev_desc_t* ubootdev = cookie;

	if (type == ENUM_MAX)
		return API_ENODEV;

	if (!dev_stor_is_valid(type, ubootdev))
		return API_ENODEV;

	if(!ubootdev->biodev)
		return 0;

	bio_close(ubootdev->biodev);
	ubootdev->biodev = NULL;
	
	return 0;
}


static int dev_stor_index(block_dev_desc_t *dd)
{
	int i, type;

	type = dev_stor_type(dd);
	for (i = 0; i < specs[type].max_dev; i++)
		if (dd == get_dev(specs[type].name, i))
			return i;

	return (specs[type].max_dev);
}


lbasize_t dev_read_stor(void *cookie, void *buf, lbasize_t len, lbastart_t start)
{
	int type;
	block_dev_desc_t *dd = (block_dev_desc_t *)cookie;

	if ((type = dev_stor_type(dd)) == ENUM_MAX)
		return 0;

	if (!dev_stor_is_valid(type, dd))
		return 0;

	if ((dd->block_read) == NULL) {
		dprintf(SPEW, "no block_read() for device %p\n", cookie);
		return 0;
	}

	return (dd->block_read(dev_stor_index(dd), start, len, buf));
}
