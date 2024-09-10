#include "screen.h"
#include "cpu.h"

#include <string.h>

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

void parse_char(char __c)
{
	uint32_t col  = cursor % 80;
	uint32_t line = cursor / 80;

	switch (__c) {
		case '\b':
			if (col != 0) {
				--col;
			}

			break;
		case '\t':
			if (col > 79) {
				parse_char('\n');
			}

			col = 8 * ((col / 8) + 1);

			break;
		case '\n':
			if (line != 25) {
				++line;
			} else {
				scroll();
			}

			col = 0;

			break;
		case '\f':
			clear_screen();

			col = 0;
			line = 0;

			break;
		case '\r':
			col = 0;

			break;
		default:
			if (col == 25) {
				parse_char('\n');
			}

			write_char(line, col, __c);
			++col;

			break;
	}

	set_cursor(line, col);
}

void scroll()
{
	uint32_t col  = cursor % 80;
	uint32_t line = cursor / 80;

	memmove(ptr_mem(0, 0), ptr_mem(1, 0), 3840);
	memset(ptr_mem(25, 0), 0, 1600);

	if (line != 0) {
		--line;
	}

	set_cursor(col, line);
}
