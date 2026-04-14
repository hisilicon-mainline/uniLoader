/* SPDX-License-Identifier: GPL-2.0 */
/*
 * UART driver framework.
 * Copyright (c) 2026 Ben Grisdale <bengris32@protonmail.ch>
 */

#ifndef LIB_UART_H
#define LIB_UART_H

#ifdef CONFIG_UART_DEBUG

struct uart_info {
	void *address;
};

struct uart_ops {
	void (*putc)(char ch);
	void (*puts)(const char *s);
};

extern const struct uart_ops *uart;

void generic_uart_puts(const char *s);

static inline void uart_putc(char ch)
{
	uart->putc(ch);
}

static inline void uart_puts(const char *s)
{
	uart->puts(s);
}

#endif /* CONFIG_UART_DEBUG */
#endif /* LIB_UART_H */
