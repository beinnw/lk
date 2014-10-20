/*
 * Copyright (c) 2013 Grzegorz Kostka (kostka.grzegorz@gmail.com)
 *
 *
 * HelenOS:
 * Copyright (c) 2012 Martin Sucha
 * Copyright (c) 2012 Frantisek Princ
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - The name of the author may not be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/** @addtogroup lwext4
 * @{
 */
/**
 * @file  ext4_super.h
 * @brief Superblock operations.
 */

#include <ext4_config.h>
#include <ext4_super.h>


uint32_t ext4_block_group_cnt(struct ext4_sblock *s)
{
    uint64_t blocks_count = ext4_sb_get_blocks_cnt(s);
    uint32_t blocks_per_group = ext4_get32(s, blocks_per_group);

    uint32_t block_groups_count = blocks_count / blocks_per_group;

    if (blocks_count % blocks_per_group)
        block_groups_count++;

    return block_groups_count;
}

uint32_t ext4_blocks_in_group_cnt(struct ext4_sblock *s, uint32_t bgid)
{
    uint32_t block_group_count = ext4_block_group_cnt(s);
    uint32_t blocks_per_group = ext4_get32(s, blocks_per_group);
    uint64_t total_blocks = ext4_sb_get_blocks_cnt(s);

    if (bgid < block_group_count - 1)
        return blocks_per_group;


    return (total_blocks - ((block_group_count - 1) * blocks_per_group));
}

uint32_t ext4_inodes_in_group_cnt(struct ext4_sblock *s, uint32_t bgid)
{
    uint32_t block_group_count = ext4_block_group_cnt(s);
    uint32_t inodes_per_group  = ext4_get32(s, inodes_per_group);
    uint32_t total_inodes = ext4_get32(s, inodes_count);


    if (bgid < block_group_count - 1)
        return inodes_per_group;

    return (total_inodes - ((block_group_count - 1) * inodes_per_group));
}

int ext4_sb_write(struct ext4_blockdev *bdev, struct ext4_sblock *s)
{
    return ext4_block_writebytes(bdev, EXT4_SUPERBLOCK_OFFSET,
            s, EXT4_SUPERBLOCK_SIZE);
}

int ext4_sb_read(struct ext4_blockdev *bdev, struct ext4_sblock *s)
{
    return ext4_block_readbytes(bdev, EXT4_SUPERBLOCK_OFFSET,
            s, EXT4_SUPERBLOCK_SIZE);
}

bool ext4_sb_check(struct ext4_sblock *s)
{
    if (ext4_get16(s, magic) != EXT4_SUPERBLOCK_MAGIC)
        return false;

    if (ext4_get32(s, inodes_count) == 0)
        return false;

    if (ext4_sb_get_blocks_cnt(s) == 0)
        return false;

    if (ext4_get32(s, blocks_per_group) == 0)
        return false;

    if (ext4_get32(s, inodes_per_group) == 0)
        return false;

    if (ext4_get16(s, inode_size) < 128)
        return false;

    if (ext4_get32(s, first_inode) < 11)
        return false;

    if (ext4_sb_get_desc_size(s) < EXT4_MIN_BLOCK_GROUP_DESCRIPTOR_SIZE)
        return false;

    if (ext4_sb_get_desc_size(s) > EXT4_MAX_BLOCK_GROUP_DESCRIPTOR_SIZE)
        return false;

    return true;
}

/**
 * @}
 */
