// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2025, Victor Paul <vipollmail@gmail.com>
 */

#ifndef RAMDISK_H_   /* Include guard */
#define RAMDISK_H_
#ifndef CONFIG_RAMDISK_NO_COPY

extern unsigned long ramdisk_size;

int ramdisk_fdt_patch(const void *bootloader_fdt, void *fdt);

#endif
#endif
