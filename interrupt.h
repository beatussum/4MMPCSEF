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

#include "cpu.h"
#include "inttypes.h"
#include "stdbool.h"
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

/*************/
/* CONSTANTS */
/*************/

/**
 * @brief The command used to acknowledge an interrupt
 */

static const uint8_t irq_cmd_ack = 0x20;

/**
 * @brief A pointer the first entry of the ISR vector
 */

static isr_entry *const isr_vector = (isr_entry *) 0x1000;

/* PORTS */

/**
 * @brief The port used to acknowledge an interrupt
 */

static const uint8_t irq_ack_port = 0x20;

static const uint8_t irq_mask_port = 0x21; ///< The port used to mask IRQ

/*************/
/* FUNCTIONS */
/*************/

/**
 * @brief Acknowledge an interrupt
 */

static inline void interrupt_acknowledge()
{
    outb(irq_cmd_ack, irq_ack_port);
}

/**
 * @brief Set an ISR to the given entry
 *
 * @param[in] __entry The entry
 * @param[in] __isr The ISR
 */

void init_isr(size_t __entry, isr __isr);

/**
 * @brief Mask or unmask the given IRQ
 *
 * @param[in] __irq The IRQ to mask or unmask
 *
 * @param[in] __mask If `true`, the IRQ is masked; otherwise, the IRQ is
 * unmasked
 */

void mask_irq(size_t __irq, bool __mask);

#endif // INTERRUPT_H
