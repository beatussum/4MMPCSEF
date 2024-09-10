#ifndef SCREEN_H
#define SCREEN_H

#include "inttypes.h"

static uint16_t *const first_cell = (uint16_t *) 0xB8000;

static inline uint16_t *ptr_mem(uint32_t __line, uint32_t __col)
{
	return first_cell + __line * 80 + __col;
}

#endif // SCREEN_H
