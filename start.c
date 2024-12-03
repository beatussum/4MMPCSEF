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

void idle()
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

void proc_one()
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

void kernel_start(void)
{
    process idle_process, proc_one_process;

    process_create(&idle_process, 1, "idle", &idle);
    process_create(&proc_one_process, 2, "proc_one", &proc_one);

    process_add_to_map(0, &idle_process);
    process_add_to_map(1, &proc_one_process);

    clear_screen();
    idle();
}
