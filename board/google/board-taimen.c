/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2025, Ivaylo Ivanov <ivo.ivanov.ivanov1@gmail.com>
 */
#include <board.h>
#include <drivers/framework.h>
#include <drivers/simplefb.h>
#ifdef CONFIG_UART_DEBUG

#include <lib/uart.h>
#include <drivers/uart/qcom-uart.h>

static struct uart_info taimen_uart = {
	.address = (void *)0xc1b0000,
};
#endif

int taimen_drv(void)
{
#ifdef CONFIG_UART_DEBUG
	REGISTER_DRIVER("qcom-uart", qcom_uart_probe, &taimen_uart);
#endif
	return 0;
}

struct board_data board_ops = {
	.name = "google-taimen",
	.ops = {
		.drivers_init = taimen_drv,
	},
	.quirks = 0
};
