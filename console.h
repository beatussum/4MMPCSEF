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


#ifndef CONSOLE_H
#define CONSOLE_H

#include "inttypes.h"
#include "stddef.h"

/*************/
/* CONSTANTS */
/*************/

/**
 * @brief A pointer to the first cell
 */

static uint16_t *const first_cell = (uint16_t *) 0xB8000;

/* CURSOR PORTS */

static const uint16_t cursor_cmd_port  = 0x3D4; ///< The cursor command port
static const uint16_t cursor_data_port = 0x3D5; ///< The cursor data port

/* CURSOR COMMANDS */

/**
 * @brief Set the low byte of the cursor position
 */

static const uint8_t cursor_cmd_low = 0x0F;

/**
 * @brief Set the high byte of the cursor position
 */

static const uint8_t cursor_cmd_high = 0x0E;

/* CONSOLE DIMENSIONS */

static const uint32_t tab_width = 8; ///< The length of a tabulation character

static const uint32_t column_number = 80; ///< The number of columns
static const uint32_t line_number   = 25; ///< The number of lines

/**
 * @brief The number of cells
 */

static const uint32_t cell_number = column_number * line_number;

/*************/
/* FUNCTIONS */
/*************/

/**
 * @brief Clear the screen
 */

void clear_screen();

/**
 * @brief Get the cell at the given position
 *
 * @param[in] The line of the cell
 * @param[in] The column of the cell
 */

static inline uint16_t *ptr_mem(uint32_t __line, uint32_t __col)
{
    return first_cell + __line * column_number + __col;
}

/**
 * @brief Scroll the current page
 *
 * All content is moved up one line; the first line is discarded.
 */

void scroll();

/**
 * @brief Set the cursor position
 *
 * @param[in] __line The line of the cursor
 * @param[in] __col The column of the cursor
 */

void set_cursor(uint32_t __line, uint32_t __col);

/* PRINTING */

/**
 * @brief Put bytes after the cursor
 *
 * @param[in] __str The string to print
 * @param[in] __len The length (without the null character) of the string
 */

void console_putbytes(const char *__str, int __len);

/**
 * @brief Put a character after the cursor
 *
 * @param[in] __c The character to parse
 */

void put_char(char __c);

/**
 * @brief Put a new line after the cursor
 */

void put_newline();

/**
 * @brief Write a character at a specific position
 *
 * @param[in] __line The line of the character
 * @param[in] __col The column of the character
 * @param[in] __c The character
 */

static inline void write_char(uint32_t __line, uint32_t __col, char __c)
{
    ((char *) ptr_mem(__line, __col))[0] = __c;
}

#endif // CONSOLE_H
