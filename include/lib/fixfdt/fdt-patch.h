// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2026 Ben Grisdale <bengris32@protonmail.ch>
 */

#ifndef FDT_PATCH_H_
#define FDT_PATCH_H_

typedef int (*fdt_patch)(const void *bootloader_fdt, void *fdt);

#endif /* FDT_PATCH_H_ */
