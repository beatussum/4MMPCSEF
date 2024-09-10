#ifndef SCREEN_H
#define SCREEN_H

#include "inttypes.h"

static uint16_t *const first_cell = (uint16_t *) 0xB8000;

static inline uint16_t *ptr_mem(uint32_t __line, uint32_t __col)
{
	return first_cell + __line * 80 + __col;
}

static inline void write_char(uint32_t __line, uint32_t __col, char __c)
{
	((uint8_t *) ptr_mem(__line, __col))[0] = __c;
}

void clear_screen();
void set_cursor(uint32_t __line, uint32_t __col);
void parse_char(char __c);
void scroll();

#endif // SCREEN_H
