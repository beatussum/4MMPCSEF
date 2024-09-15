#ifndef SCREEN_H
#define SCREEN_H

#include "inttypes.h"
#include "stddef.h"

static const uint16_t cursor_cmd_port  = 0x3D4; ///< The cursor command port
static const uint16_t cursor_data_port = 0x3D5; ///< The cursor data port

/**
 * @brief Set the low byte of the cursor position
 */

static const uint8_t cursor_cmd_low  = 0x0F;

/**
 * @brief Set the high byte of the cursor position
 */

static const uint8_t cursor_cmd_high = 0x0E;

/**
 * @brief A pointer to the first cell
 */

static uint16_t *const first_cell = (uint16_t *) 0xB8000;

static const uint32_t tab_width = 8; ///< The length of a tabulation character

static const uint32_t column_number = 80; ///< The number of columns
static const uint32_t line_number   = 25; ///< The number of lines

/**
 * @brief The number of cells
 */

static const uint32_t cell_number = column_number * line_number;

/**
 * @brief Clear the screen
 */

void clear_screen();

/**
 * @brief Put bytes after the cursor
 *
 * @param[in] __str The string to print
 * @param[in] __len The length (without the null character) of the string
 */

void console_putbytes(const char *__str, size_t __len);

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

#endif // SCREEN_H
