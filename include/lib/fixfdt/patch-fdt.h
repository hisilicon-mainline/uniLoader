// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2026, Igor Belwon <igor.belwon@mentallysanemainliners.org>
 */

#ifndef PATCH_FDT_H_
#define PATCH_FDT_H_

void* patch_fdt(struct board_data *board, void* dt, void* bootloader_fdt);

#endif // PATCH_DTB_H_
