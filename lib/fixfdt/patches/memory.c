// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2026 Ben Grisdale <bengris32@protonmail.ch>
 */

#include <lib/debug.h>
#include <lib/fixfdt/patches/memory.h>
#include <lib/libfdt/libfdt.h>

int memory_fdt_patch(const void *bootloader_fdt, void *fdt)
{
	int bl_memory, memory, len, ret;
	const void *val;

	printk(KERN_INFO, "copying /memory reg from bootloader...\n");

	memory = fdt_path_offset(fdt, "/memory");
	if (memory < 0) {
		printk(KERN_ERR, "Lookup /memory failed: %s.\n", fdt_strerror(memory));
		return -1;
	}

	bl_memory = fdt_path_offset(bootloader_fdt, "/memory");
	if (bl_memory < 0) {
		printk(KERN_ERR, "Lookup bootloader /memory failed: %s.\n",
			fdt_strerror(bl_memory));
		return -1;
	}

	val = fdt_getprop(bootloader_fdt, bl_memory, "reg", &len);
	if (!val) {
		printk(KERN_ERR, "Read bootloader /memory reg failed.\n");
		return -1;
	}

	if ((ret = fdt_setprop(fdt, memory, "reg", val, len)) < 0) {
		printk(KERN_ERR, "fdt_setprop() /memory reg failed: %s.\n",
			fdt_strerror(ret));
		return -1;
	}

	return 0;
}
