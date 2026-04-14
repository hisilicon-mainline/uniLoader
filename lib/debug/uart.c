/* SPDX-License-Identifier: GPL-2.0 */
/*
 * UART driver framework.
 * Copyright (c) 2026 Ben Grisdale <bengris32@protonmail.ch>
 */

#include <lib/uart.h>
#include <stddef.h>

const struct uart_ops *uart = NULL;

void generic_uart_puts(const char *s)
{
	while (*s != '\0') {
		uart->putc(*s);
		s++;
	}
}
