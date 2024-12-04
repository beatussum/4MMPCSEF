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


#include "console.h"
#include "cpu.h"
#include "interrupt.h"
#include "process.h"
#include "stdbool.h"
#include "stdio.h"
#include "time.h"

void one()
{
    while (true) {
        printf(
            "[%s] pid = %i\n",
            process_name(process_current()),
            process_pid(process_current())
        );

        sti();
        hlt();
        cli();
    }
}

void two()
{
    while (true) {
        printf(
            "[%s] pid = %i\n",
            process_name(process_current()),
            process_pid(process_current())
        );

        sti();
        hlt();
        cli();
    }
}

void three()
{
    while (true) {
        printf(
            "[%s] pid = %i\n",
            process_name(process_current()),
            process_pid(process_current())
        );

        sti();
        hlt();
        cli();
    }
}

void four()
{
    while (true) {
        printf(
            "[%s] pid = %i\n",
            process_name(process_current()),
            process_pid(process_current())
        );

        sti();
        hlt();
        cli();
    }
}

void five()
{
    while (true) {
        printf(
            "[%s] pid = %i\n",
            process_name(process_current()),
            process_pid(process_current())
        );

        sti();
        hlt();
        cli();
    }
}

void six()
{
    while (true) {
        printf(
            "[%s] pid = %i\n",
            process_name(process_current()),
            process_pid(process_current())
        );

        sti();
        hlt();
        cli();
    }
}

void kernel_start()
{
    process_create("one", &one);
    process_create("two", &two);
    process_create("three", &three);
    process_create("four", &four);
    process_create("five", &five);
    process_create("six", &six);
    process_create("write_run_time", &write_run_time);

    clear_screen();
    set_clock_frequency(50);
    init_isr(32, &update_run_time_isr_wrapper);
    mask_irq(0, false);
    sti();

    one();
}
