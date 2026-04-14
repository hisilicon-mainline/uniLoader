/* SPDX-License-Identifier: GPL-2.0 */
/*
 * IMX UART driver
 * Copyright (c) 2025, Ivaylo Ivanov <ivo.ivanov.ivanov1@gmail.com>
 */

#include <lib/uart.h>
#include <drivers/uart/imx-uart.h>
#include <string.h>

#define URTX0_OFFSET		0x40
#define IMX_UTS_OFFSET		0xB4
#define UTS_TXFULL		(1 << 4)

static struct uart_info *info;

static void imx_uart_putc(char ch)
{
	volatile uint32_t *uts_reg = (volatile
					  uint32_t *)(info->address +
						  IMX_UTS_OFFSET);
	volatile uint32_t *urtx0_reg = (volatile
					uint32_t *)(info->address +
							URTX0_OFFSET);

	while ((*uts_reg) & UTS_TXFULL) { }

	*urtx0_reg = (uint32_t)ch;
}

static const struct uart_ops imx_uart_ops = {
	.putc = imx_uart_putc,
	.puts = generic_uart_puts,
};

void imx_uart_probe(void *data)
{
	info = (struct uart_info *)data;
	uart = &imx_uart_ops;
}
