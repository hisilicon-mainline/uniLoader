/* SPDX-License-Identifier: GPL-2.0 */
/*
 * MediaTek UART Driver
 * Copyright (c) 2025 evilMyQueen <vernamjap@gmail.com>
 */

#include <lib/uart.h>
#include <drivers/uart/mtk-uart.h>
#include <string.h>

#define UART_LSR_BASE	0x14
#define UART_LSR_DR 	0x01 	/* Data ready */
#define UART_LSR_THRE 	0x20 	/* TX holding register empty */

static struct uart_info *info;

static void mtk_uart_putc(char ch)
{
	while (!(readl((void *)(info->address + UART_LSR_BASE)) & UART_LSR_THRE))
		;

	writel(ch, (void *)info->address);
}

static const struct uart_ops mtk_uart_ops = {
	.putc = mtk_uart_putc,
	.puts = generic_uart_puts,
};

void mtk_uart_probe(void *data)
{
	info = (struct uart_info *)data;
	uart = &mtk_uart_ops;
}
