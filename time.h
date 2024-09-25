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

/**
 * @brief An integral type representing a time
 *
 * This time is in milliseconds.
 */

typedef uint32_t time_t;

/**
 * @brief Write the given time at the top right of the console
 *
 * The format is HHHH:MM:SS.
 *
 * @param[in] __time The time to write on the console
 */

void write_time(time_t __time);

#endif // TIME_H
