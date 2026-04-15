#include <board.h>
#include <drivers/framework.h>
#include <drivers/simplefb.h>
#ifdef CONFIG_UART_DEBUG
#include <lib/uart.h>
#include <drivers/uart/mtk-uart.h>

static struct uart_info blossom_uart = {
	.address = (void *)0x11002000,
};
#endif

static struct video_info blossom_fb = {
	.format = FB_FORMAT_ARGB8888,
	.width = 736,
	.height = 1600,
	.stride = 4,
	.address = (void *)0x7ec50000
};

int blossom_drv(void)
{
#ifdef CONFIG_UART_DEBUG
	REGISTER_DRIVER("mtk-uart", mtk_uart_probe, &blossom_uart);
#endif
	REGISTER_DRIVER("simplefb", simplefb_probe, &blossom_fb);
	return 0;
}

struct board_data board_ops = {
	.name = "xiaomi-blossom",
	.ops = {
		.drivers_init = blossom_drv,
	},
};
