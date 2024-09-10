#include "screen.h"
#include "cpu.h"

static uint32_t cursor = 0;

void clear_screen()
{
	uint16_t *begin = (uint16_t *) 0xB8000;
	uint16_t *end   = begin + 2000;

	for (; begin != end; ++begin) {
		((uint8_t *) begin)[0] = 0;
	}
}

void set_cursor(uint32_t __line, uint32_t __col)
{
	cursor = __col + __line * 80;

	outb(0x0F, 0x3D4);
	outb((uint8_t) (cursor & 0xFF), 0x3D5);
	outb(0x0E, 0x3D4);
	outb((uint8_t) ((cursor >> 8) & 0xFF), 0x3D5);
}
