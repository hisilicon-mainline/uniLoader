// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2026, Giovanni Ricca <giovanniricca@proton.me>
 */

#include <lib/debug.h>
#include <lib/fixfdt/patches/cmdline.h>
#include <lib/libfdt/libfdt.h>

int cmdline_fdt_patch(const void* bootloader_fdt, void *buf)
{
	int ret, dtb_chosen_offset;

	dtb_chosen_offset = fdt_path_offset(buf, "/chosen");
	if (dtb_chosen_offset < 0) {
		printk(KERN_ERR, "Could not find /chosen node: %s\n", fdt_strerror(dtb_chosen_offset));
		return dtb_chosen_offset;
	}

	printk(KERN_INFO, "adding bootargs...\n");
	ret = fdt_setprop_string(buf, dtb_chosen_offset, "bootargs", CMDLINE_STR);
	if (ret < 0) {
		printk(KERN_ERR, "failed to add bootargs: %s\n", fdt_strerror(ret));
		return ret;
	}

	return 0;
}
