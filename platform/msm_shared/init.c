/*
 * Copyright (c) 2008 Travis Geiselbrecht
 *
 * Copyright (c) 2014, The Linux Foundation. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include <err.h>
#include <debug.h>
#include <platform.h>
#include <platform/msm_shared/boot_stats.h>
#include <platform/iomap.h>
#include <assert.h>

/*
 * default implementations of these routines, if the platform code
 * chooses not to implement.
 */
__WEAK int platform_use_identity_mmu_mappings(void)
{
	return 1;
}

__WEAK void display_init(void)
{
}

__WEAK void display_shutdown(void)
{
}

__WEAK void platform_config_interleaved_mode_gpios(void)
{
}

__WEAK void uart_clock_init(void)
{
}

__WEAK void platform_uninit(void)
{
}

__WEAK int image_verify(unsigned char * image_ptr,
			unsigned char * signature_ptr,
			unsigned int image_size,
			unsigned hash_type)
{
	return 0;
}

__WEAK void ce_clock_init(void)
{
}

__WEAK addr_t get_bs_info_addr(void)
{
	return 0;
}

__WEAK uint32_t platform_get_sclk_count(void)
{
	return 0;
}

__WEAK void clock_config_cdc(uint8_t slot)
{
}

__WEAK int get_target_boot_params(const char *cmdline, const char *part,
				  char *buf, int buflen)
{
	return -1;
}

__WEAK uint32_t platform_get_smem_base_addr(void)
{
	return (uint32_t)MSM_SHARED_BASE;
}

__WEAK uint32_t platform_boot_dev_isemmc(void)
{
        return 1;
}

__WEAK uint32_t platform_get_boot_dev(void)
{
        return 0;
}
