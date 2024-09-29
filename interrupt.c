/*
 * Copyright (C) 2024 Mattéo Rossillol‑‑Laruelle <beatussum@protonmail.com>
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <https://www.gnu.org/licenses/>.
 */


#include "interrupt.h"

#include "segment.h"

void init_isr(size_t __entry, isr __isr)
{
    isr_vector[__entry] = (isr_entry) {
        .first = (KERNEL_CS << 16) | ((intptr_t) __isr & 0xFFFF),
        .second = ((intptr_t) __isr & 0xFFFF0000) | 0x8E00
    };
}

void mask_irq(size_t __irq, bool __mask)
{
    uint8_t vector = inb(irq_mask_port);

    if (__mask) {
        vector |= 1 << __irq;
    } else {
        vector &= ~(1 << __irq);
    }

    outb(vector, irq_mask_port);
}
