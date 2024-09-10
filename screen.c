#include "screen.h"

void clear_screen()
{
	uint16_t *begin = (uint16_t *) 0xB8000;
	uint16_t *end   = begin + 2000;

	for (; begin != end; ++begin) {
		((uint8_t *) begin)[0] = 0;
	}
}
