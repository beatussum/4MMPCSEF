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


#ifndef INTERRUPT_H
#define INTERRUPT_H

#include "inttypes.h"
#include "stddef.h"

/**
 * @file
 * @brief This file implements interrupt-related utilities
 */

/**
 * @brief The type representing an ISR entry
 */

typedef struct {
    uint32_t first;  ///< The first word of the entry
    uint32_t second; ///< The second word of the entry
} isr_entry;

typedef void (*isr)(); ///< An interrupt service routine

/**
 * @brief A pointer the first entry of the ISR vector
 */

static isr_entry *const isr_vector = (isr_entry *) 0x1000;

/**
 * @brief Set an ISR to the given entry
 *
 * @param[in] __entry The entry
 * @param[in] __isr The ISR
 */

void init_isr(size_t __entry, isr __isr);

#endif // INTERRUPT_H
