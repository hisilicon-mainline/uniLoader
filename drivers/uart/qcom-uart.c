/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Qualcomm UART driver
 * Copyright (c) 2025, Ivaylo Ivanov <ivo.ivanov.ivanov1@gmail.com>
 */

#include <lib/uart.h>
#include <drivers/uart/qcom-uart.h>
#include <string.h>

#define UARTDM_SR		0xa4
#define UARTDM_SR_TX_EMPTY	(1 << 3)
#define UARTDM_SR_RX_READY	(1 << 0)
#define UARTDM_SR_UART_OVERRUN	(1 << 4)

#define UARTDM_CR		0xa8
#define UARTDM_CR_CMD_RESET_TX_READY	(3 << 8)
#define UARTDM_CR_CMD_RESET_ERR		(3 << 4)
#define UARTDM_CR_CMD_FORCE_STALE	(4 << 8)
#define UARTDM_CR_CMD_RESET_STALE_INT	(8 << 4)

#define UARTDM_NCF_TX		0x40
#define UARTDM_TF		0x100
#define UARTDM_RF		0x140
#define UARTDM_RXFS		0x50
#define UARTDM_DMRX		0x34

#define UARTDM_RXFS_BUF_SHIFT	7
#define UARTDM_RXFS_BUF_MASK	0x7

static struct uart_info *info;

static void qcom_uart_putc(char ch)
{
	/* wait until TX is ready */
	while (!(readl((void *)(info->address + UARTDM_SR)) & UARTDM_SR_TX_EMPTY))
		;

	writel(UARTDM_CR_CMD_RESET_TX_READY, (void *)(info->address + UARTDM_CR));

	writel(1, (void *)(info->address + UARTDM_NCF_TX));
	writel(ch, (void *)(info->address + UARTDM_TF));
}

static const struct uart_ops qcom_uart_ops = {
	.putc = qcom_uart_putc,
	.puts = generic_uart_puts,
};

void qcom_uart_probe(void *data)
{
	info = (struct uart_info *)data;
	uart = &qcom_uart_ops;
}
