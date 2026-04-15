// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) 2026 Roger Ortiz <me@r0rt1z2.com>
 */

#include <aarch64/fpu.h>
#include <board.h>
#include <drivers/framework.h>
#include <drivers/simplefb.h>

#ifdef CONFIG_SIMPLE_FB
static struct video_info anne_fb = {
	.format = FB_FORMAT_ARGB8888,
	.width = 1080,
	.height = 2280,
	.stride = 4,
	.address = (void *)0x5d000000,
	.scale = 2
};
#endif

int anne_early_init(void)
{
	aarch64_enable_fpu();
	return 0;
}

int anne_drv(void)
{
#ifdef CONFIG_SIMPLE_FB
	REGISTER_DRIVER("simplefb", simplefb_probe, &anne_fb);
#endif
	return 0;
}

struct board_data board_ops = {
	.name = "huawei-anne",
	.ops = {
		.early_init = anne_early_init,
		.drivers_init = anne_drv
	},
};
