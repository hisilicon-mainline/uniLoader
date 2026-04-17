// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2026, Giovanni Ricca <giovanniricca@proton.me>
 */

#ifndef CMDLINE_H_   /* Include guard */
#define CMDLINE_H_
#ifdef CMDLINE_STR

int cmdline_fdt_patch(const void* bootloader_fdt, void *buf);

#endif
#endif
