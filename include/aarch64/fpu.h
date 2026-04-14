/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2026, Tildeguy <tildeguy@mainlining.org>
 */

#ifndef AARCH64_FPU_H
#define AARCH64_FPU_H
static inline void aarch64_enable_fpu(void)
{
	unsigned long cpacr;
	__asm__ volatile ("mrs %0, cpacr_el1" : "=r" (cpacr));
	cpacr |= (3UL << 20);
	__asm__ volatile ("msr cpacr_el1, %0" :: "r" (cpacr));
}
#endif /* AARCH64_FPU_H*/
