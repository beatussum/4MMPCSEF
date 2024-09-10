#ifndef SCREEN_H
#define SCREEN_H

#include "inttypes.h"
#include "stddef.h"

static const uint16_t cursor_cmd_port  = 0x3D4;
static const uint16_t cursor_data_port = 0x3D5;

static const uint8_t cursor_cmd_low  = 0x0F;
static const uint8_t cursor_cmd_high = 0x0E;

static uint16_t *const first_cell = (uint16_t *) 0xB8000;

static const uint32_t tab_width = 8;

static const uint32_t column_number = 80;
static const uint32_t line_number   = 25;

static const uint32_t cell_number = column_number * line_number;

static inline uint16_t *ptr_mem(uint32_t __line, uint32_t __col)
{
	return first_cell + __line * column_number + __col;
}

static inline void write_char(uint32_t __line, uint32_t __col, char __c)
{
	((char *) ptr_mem(__line, __col))[0] = __c;
}

void clear_screen();
void set_cursor(uint32_t __line, uint32_t __col);
void put_newline();
void parse_char(char __c);
void scroll();
void console_putbytes(const char *__str, size_t __len);

#endif // SCREEN_H
