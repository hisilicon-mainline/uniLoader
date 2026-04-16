// SPDX-License-Identifier: GPL-2.0-only
/*
 * Based on https://github.com/torvalds/linux/blob/master/lib/fonts/font_8x16.c
 */

#ifndef FONT_H_	/* Include guard */
#define FONT_H_

#define FONTW 8
#define FONTH 16

#define FONT_INDEX(a) (a - 32)

extern unsigned char letters[256][16];

#endif // FONT_H_
