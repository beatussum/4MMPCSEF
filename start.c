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
#include "process.h"
#include "stdbool.h"
#include "stdio.h"

void one()
{
    while (true) {
        printf(
            "[%s] pid = %i\n",
            process_name(process_current()),
            process_pid(process_current())
        );

        process_schedule();
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

        process_schedule();
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

        process_schedule();
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

        process_schedule();
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

        process_schedule();
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

        process_schedule();
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

    clear_screen();
    one();
}
