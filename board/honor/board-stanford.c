// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) 2026 Giovanni Ricca <giovanniricca@proton.me>
 */

#include <aarch64/fpu.h>
#include <board.h>
#include <drivers/framework.h>
#include <drivers/simplefb.h>

#ifdef CONFIG_SIMPLE_FB
static struct video_info stanford_fb = {
	.format = FB_FORMAT_ARGB8888,
	.width = 1080,
	.height = 1920,
	.stride = 4,
	.address = (void *)0x21000000,
	.scale = 2
};
#endif

int stanford_early_init(void)
{
	aarch64_enable_fpu();

	return 0;
}

int stanford_drv(void)
{
#ifdef CONFIG_SIMPLE_FB
	REGISTER_DRIVER("simplefb", simplefb_probe, &stanford_fb);
#endif
	return 0;
}

struct board_data board_ops = {
	.name = "honor-stanford",
	.ops = {
		.early_init = stanford_early_init,
		.drivers_init = stanford_drv
	},
};
