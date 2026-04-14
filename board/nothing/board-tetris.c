/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2025, Igor Belwon <igor.belwon@mentallysanemainliners.org>
 */
#include <board.h>
#include <drivers/framework.h>
#include <lib/debug.h>
#ifdef CONFIG_UART_DEBUG
#include <lib/uart.h>
#include <drivers/uart/mtk-uart.h>
#endif

#define WDT_BASE		0x1c00a000
#define WDT_MODE_KEY	0x22000000
#define WDT_MODE_EN		(1 << 0)

#ifdef CONFIG_UART_DEBUG
static struct uart_info tetris_uart = {
	.address = (void *)0x11001000,
};
#endif

int tetris_drv(void)
{
#ifdef CONFIG_UART_DEBUG
	REGISTER_DRIVER("mtk-uart", mtk_uart_probe, &tetris_uart);
#endif
	return 0;
}

void tetris_disable_wdt(void)
{
	uint32_t reg;

	reg = readl((void*)WDT_BASE);
	if (reg & WDT_MODE_EN)
	{
		reg &= ~WDT_MODE_EN;
		reg |= WDT_MODE_KEY;
		writel(reg, (void*)WDT_BASE);
		printk(KERN_INFO, "%s: disabled watchdog timer.\n", __func__);
	}
	else
		printk(KERN_ERR, "%s: watchdog is already disabled.\n", __func__);

	return;
}

int tetris_late_init(void)
{
#ifdef CONFIG_NOTHING_TETRIS_DISABLE_WDT
	tetris_disable_wdt();
#endif
	return 0;
}

struct board_data board_ops = {
	.name = "cmf-phone-1",
	.ops = {
		.drivers_init = tetris_drv,
		.late_init = tetris_late_init,
	},
	.quirks = 0
};
