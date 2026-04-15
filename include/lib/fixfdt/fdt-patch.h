// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2026 Ben Grisdale <bengris32@protonmail.ch>
 */

#ifndef FDT_PATCH_H_
#define FDT_PATCH_H_

#include <lib/fixfdt/patches/memory.h>

#ifndef CONFIG_RAMDISK_NO_COPY
#include <lib/fixfdt/patches/ramdisk.h>
#define RAMDISK_PATCH ramdisk_fdt_patch,
#else
#define RAMDISK_PATCH
#endif

#define FDT_DEFAULT_PATCH_LIST \
	RAMDISK_PATCH \
	memory_fdt_patch

typedef int (*fdt_patch)(const void *bootloader_fdt, void *fdt);

#endif /* FDT_PATCH_H_ */
