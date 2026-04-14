/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Board driver for Huawei Mediapad T5
 *
 * Copyright (c) 2026, Tildeguy <tildeguy@mainlining.org>
 */

#include <aarch64/fpu.h>
#include <board.h>
#include <drivers/framework.h>
#include <drivers/simplefb.h>

#ifdef CONFIG_SIMPLE_FB
static struct video_info agassi2_fb = {
	.format = FB_FORMAT_ARGB8888,
	.width = 1200,
	.height = 1920,
	.stride = 4,
	.address = (void *)0x5d000000,
	.scale = 2
};
#endif

int agassi2_early_init(void)
{
	aarch64_enable_fpu();
	return 0;
}

int agassi2_drv(void)
{
#ifdef CONFIG_SIMPLE_FB
	REGISTER_DRIVER("simplefb", simplefb_probe, &agassi2_fb);
#endif
	return 0;
}

struct board_data board_ops = {
	.name = "huawei-agassi2",
	.ops = {
		.early_init = agassi2_early_init,
		.drivers_init = agassi2_drv
	},
	.quirks = 0
};
