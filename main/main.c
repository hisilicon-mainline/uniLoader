// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2022, Ivaylo Ivanov <ivo.ivanov.ivanov1@gmail.com>
 */

#include <board.h>
#include <main/boot.h>
#include <main/main.h>
#include <lib/debug.h>
#include <lib/fixfdt/patch-fdt.h>

extern struct board_data board_ops;

static void print_splash(void)
{
	printk(KERN_INFO, "             .__.____                     .___\n");
	printk(KERN_INFO, " __ __  ____ |__|    |    _________     __| _/___________\n");
	printk(KERN_INFO, "|  |  \\/    \\|  |    |   /  _ \\__  \\   / __ |/ __ \\_  __\\\n");
	printk(KERN_INFO, "|  |  /   |  \\  |    |__(  <_> ) __ \\_/ /_/ \\  ___/|  |\\/\n");
	printk(KERN_INFO, "|____/|___|  /__|_______ \\____(____  /\\____ |\\___  >__|\n");
	printk(KERN_INFO, "           \\/           \\/         \\/      \\/    \\/\n");

	printk(KERN_INFO, "passed board initialization\n");
	printk(KERN_INFO, "welcome to uniLoader %s on %s\n", VER_TAG, board_ops.name);
}

static void print_umbreon(void)
{
	printk(KERN_INFO, "\n");
	printk(KERN_INFO, "bree :3\n");
	printk(KERN_INFO, "\n");
	printk(KERN_INFO, "\n");
	printk(KERN_INFO, "\n");
	printk(KERN_INFO, "000000\n");
	printk(KERN_INFO, "000000\n");
	printk(KERN_INFO, "000 98000                     000000000\n");
	printk(KERN_INFO, "000      00              00000      007          000000000\n");
	printk(KERN_INFO, "000   882  000        000     8     007        00      000\n");
	printk(KERN_INFO, "000   8    000        000     882   000        00885   000\n");
	printk(KERN_INFO, "000   2    00000000000   288     000        000     88 000\n");
	printk(KERN_INFO, "   000    2        000     8  000        000           000\n");
	printk(KERN_INFO, "   000    5      8 000     6  000        000           000\n");
	printk(KERN_INFO, "      000 5888   5          00           00018888   000\n");
	printk(KERN_INFO, "   000    5   885     000000        00000        000\n");
	printk(KERN_INFO, "   000 8888   5  71   000000        00000        000\n");
	printk(KERN_INFO, "   000     888809   00   00000000000        00000\n");
	printk(KERN_INFO, "   000 8885      66600   00000           000\n");
	printk(KERN_INFO, "   000       7   66600   00000           800\n");
	printk(KERN_INFO, "   000       7666007     000             5  000\n");
	printk(KERN_INFO, "      000      7   000000                881000\n");
	printk(KERN_INFO, "         0000000000                 00028   1  00\n");
	printk(KERN_INFO, "         0000000000                 000 2   2  00\n");
	printk(KERN_INFO, "              000                   000  000   00\n");
	printk(KERN_INFO, "              000     000     000   00000      00\n");
	printk(KERN_INFO, "              000     000   5 000   00000      00\n");
	printk(KERN_INFO, "           000     000000  5  000000     000   00\n");
	printk(KERN_INFO, "         00      00      000  000        000   00\n");
	printk(KERN_INFO, "         00      00      000  000        000   00\n");
	printk(KERN_INFO, "         00000000        000  000        000000\n");
	printk(KERN_INFO, "                         000  000\n");
	printk(KERN_INFO, "                         000 4\n");
	printk(KERN_INFO, "                         00000\n");
	printk(KERN_INFO, "\n");
	printk(KERN_INFO, "\n");
	printk(KERN_INFO, "\n");
}

void main(void* dt, void* kernel, void* ramdisk, void *bootloader_fdt)
{
	INITCALL(board_ops.ops.early_init);
	INITCALL(board_ops.ops.drivers_init);

	print_splash();
	print_umbreon();

	INITCALL(board_ops.ops.late_init);

#ifdef CONFIG_LIBFDT
	dt = patch_fdt(&board_ops, dt, bootloader_fdt);
#endif

	printk(KERN_INFO, "Booting kernel...\n");
	arch_load_kernel(kernel, dt, ramdisk);

	// todo: reset the board?
	printk(KERN_EMERG, "Something wrong happened, we shouldn't be here. Hanging....\n");
	HANG();
}
