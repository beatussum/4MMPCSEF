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


#include "time.h"

#include "console.h"
#include "cpu.h"
#include "debug.h"
#include "interrupt.h"

static time_t run_time = 0;

void set_clock_frequency(uint16_t __frequency)
{
    uint16_t value = clock_quartz_frequency / __frequency;

    outb(clock_cmd_set, clock_cmd_port);
    outb(value & 0xFF, clock_data_port);
    outb((value >> 8) & 0xFF, clock_data_port);
}

void update_run_time_isr()
{
    interrupt_acknowledge();
    run_time += 20;
}

void write_run_time()
{
    write_time(run_time);
}

void write_time(time_t __time)
{
    __time /= 1000;

    time_t hours  = __time / 60 / 60;
    __time       -= hours * 60 * 60;

    time_t minutes  = __time / 60;
    __time         -= minutes * 60;

    char buffer[11];

    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wformat-overflow"

    buffer[10] = '\0';
    sprintf(buffer, "%.4" PRIi32, hours);
    buffer[4] = ':';
    sprintf(buffer + 5, "%.2" PRIi32, minutes);
    buffer[7] = ':';
    sprintf(buffer + 8, "%.2" PRIi32, __time);

    #pragma GCC diagnostic pop

    const char *end = buffer + 11;
    uint32_t col    = column_number - 10;

    for (const char *i = buffer; i != end; ++i) {
        write_char(0, col, *i);
        ++col;
    }
}
