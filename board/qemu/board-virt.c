/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2025, Igor Belwon <igor.belwon@mentallysanemainliners.org>
 */
#include <aarch64/fpu.h>
#include <board.h>
#include <drivers/framework.h>
#include <drivers/simplefb.h>
#ifdef CONFIG_UART_DEBUG
#include <lib/uart.h>
#include <drivers/uart/virt-uart.h>

static struct uart_info virt_uart = {
	.address = (void *)0x9000000,
};
#endif

int virt_drv(void)
{
#ifdef CONFIG_UART_DEBUG
	REGISTER_DRIVER("virt-uart", virt_uart_probe, &virt_uart);
#endif
	return 0;
}

int virt_init(void)
{
	// TODO: We can implement a framebuffer with QEMU. This would however
	// require more setup.
	aarch64_enable_fpu();
	return 0;
}

struct board_data board_ops = {
	.name = "qemu-virt",
	.ops = {
		.drivers_init = virt_drv,
		.early_init = virt_init,
	},
};
