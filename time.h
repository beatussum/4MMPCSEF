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


#ifndef TIME_H
#define TIME_H

#include "inttypes.h"

/**
 * @file
 * @brief This file implements various time-related utilities
 */

/************/
/* TYPEDEFS */
/************/

/**
 * @brief An integral type representing a time
 *
 * This time is in milliseconds.
 */

typedef uint32_t time_t;

/*************/
/* CONSTANTS */
/*************/

/**
 * @brief The frequency of the quartz
 */

static const uint32_t clock_quartz_frequency = 0x1234DD;

/* COMMANDS */

/**
 * @brief The command used to set the new frequency
 */

static const uint8_t clock_cmd_set = 0x34;

/* PORTS */

/**
 * @brief The port used to send command to the clock
 */

static const uint8_t clock_cmd_port = 0x43;

/**
 * @brief The port used to send data to the clock
 */

static const uint8_t clock_data_port = 0x40;

/*************/
/* FUNCTIONS */
/*************/

/**
 * @brief Set the clock frequency
 *
 * @param[in] The frequency to set
 */

void set_clock_frequency(uint16_t __frequency);

/**
 * @brief The ISR used to update run time
 *
 * @note This function should not be used directly
 * @see update_run_time_isr_wrapper
 */

void update_run_time_isr();

void update_run_time_isr_wrapper(); ///< The ISR used to update run time

/**
 * @brief Write the run time at the top right of the console
 *
 * @see write_time
 */

void write_run_time();

/**
 * @brief Write the given time at the top right of the console
 *
 * The format is HHHH:MM:SS.
 *
 * @param[in] __time The time to write on the console
 */

void write_time(time_t __time);

#endif // TIME_H
