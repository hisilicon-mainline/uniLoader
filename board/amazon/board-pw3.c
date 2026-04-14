/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2025, Ivaylo Ivanov <ivo.ivanov.ivanov1@gmail.com>
 */

#include <board.h>
#include <main/main.h>
#include <drivers/framework.h>

#ifdef CONFIG_UART_DEBUG
#include <lib/uart.h>
#include <drivers/uart/imx-uart.h>

static struct uart_info pw3_uart = {
	.address = (void *)0x02020000,
};
#endif

int pw3_drv(void)
{
#ifdef CONFIG_UART_DEBUG
	REGISTER_DRIVER("imx-uart", imx_uart_probe, &pw3_uart);
#endif
	return 0;
}

struct board_data board_ops = {
	.name = "amazon-paperwhite3",
	.ops = {
		.drivers_init = pw3_drv,
	},
	.quirks = 0
};
