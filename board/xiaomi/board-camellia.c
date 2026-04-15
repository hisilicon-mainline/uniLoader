/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Use the fw_camellian_miui_CAMELLIANGlobal_V14_0_6_0_TKSMIXM_65527e11f3_13
 *
 * Copyright (c) Ryo "evilMyQueen" Yamada <vernamjap@gmail.com>
 */

#include <board.h>
#include <drivers/framework.h>
#include <drivers/simplefb.h>
#ifdef CONFIG_UART_DEBUG
#include <lib/uart.h>
#include <drivers/uart/mtk-uart.h>

static struct uart_info camellia_uart = {
	.address = (void *)0x11002000,
};
#endif

static struct video_info camellia_fb = {
	.format = FB_FORMAT_ARGB8888,
	.width = 1088,
	.height = 2400,
	.stride = 4,
	.address = (void *)0x7ba10000
};

int camellia_drv(void)
{
#ifdef CONFIG_UART_DEBUG
	REGISTER_DRIVER("mtk-uart", mtk_uart_probe, &camellia_uart);
#endif
	REGISTER_DRIVER("simplefb", simplefb_probe, &camellia_fb);
	return 0;
}

struct board_data board_ops = {
	.name = "xiaomi-camellia",
	.ops = {
		.drivers_init = camellia_drv,
	},
};
