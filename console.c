#include "console.h"

#include "cpu.h"
#include "string.h"

static uint32_t cursor_column = 0;
static uint32_t cursor_line   = 0;

void clear_screen()
{
    uint16_t *begin = first_cell;
    uint16_t *end   = begin + cell_number;

    for (; begin != end; ++begin) {
        ((char *) begin)[0] = 0;
    }
}

void console_putbytes(const char *__str, int __len)
{
    for (; __len != 0; --__len) {
        put_char(*__str);
        ++__str;
    }
}

void put_newline()
{
    if (cursor_line != line_number) {
        ++cursor_line;
    } else {
        scroll();
    }

    cursor_column = 0;

    set_cursor(cursor_line, cursor_column);
}

void put_char(char __c)
{
    switch (__c) {
        case '\b':
            if (cursor_column != 0) {
                --cursor_column;
            }

            break;
        case '\t':
            if (cursor_column >= (column_number / tab_width)) {
                put_newline();
            }

            cursor_column =
                tab_width * ((cursor_column / tab_width) + 1);

            break;
        case '\n':
            put_newline();

            break;
        case '\f':
            clear_screen();

            cursor_column = 0;
            cursor_line   = 0;

            break;
        case '\r':
            cursor_column = 0;

            break;
        default:
            if (cursor_line == line_number) {
                put_newline();
            }

            write_char(cursor_line, cursor_column, __c);
            ++cursor_column;

            break;
    }

    set_cursor(cursor_line, cursor_column);
}

void scroll()
{
    memmove(
        ptr_mem(0, 0),
        ptr_mem(1, 0),
        2 * (line_number - 1) * column_number
    );

    uint16_t *end = ptr_mem(24, 80);

    for (uint16_t *begin = ptr_mem(24, 0); begin != end; ++begin) {
        ((char *) begin)[0] = 0;
    }

    if (cursor_line != 0) {
        --cursor_line;
    }

    set_cursor(cursor_line, cursor_column);
}

void set_cursor(uint32_t __line, uint32_t __col)
{
    cursor_column = __col;
    cursor_line   = __line;

    uint32_t pos = __col + __line * column_number;

    outb(cursor_cmd_low, cursor_cmd_port);
    outb((uint8_t) (pos & 0xFF), cursor_data_port);
    outb(cursor_cmd_high, cursor_cmd_port);
    outb((uint8_t) ((pos >> 8) & 0xFF), cursor_data_port);
}
