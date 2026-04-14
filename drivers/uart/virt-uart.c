/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Virt (QEMU) UART driver
 * Copyright (c) 2025, Igor Belwon <igor.belwon@mentallysanemainliners.org>
 */

#include <lib/uart.h>
#include <drivers/uart/virt-uart.h>
#include <string.h>

static struct uart_info *info;

static void virt_uart_putc(char ch)
{
	writel(ch, info->address);
}

static const struct uart_ops virt_uart_ops = {
	.putc = virt_uart_putc,
	.puts = generic_uart_puts,
};

void virt_uart_probe(void *data)
{
	info = (struct uart_info *)data;
	uart = &virt_uart_ops;
}
