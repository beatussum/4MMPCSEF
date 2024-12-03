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
#include "stdio.h"

void idle()
{
    printf("[idle] I am trying to hand over to proc1...\n");
    ctx_sw(process_map[0].registers, process_map[1].registers);
}

void proc_one()
{
    printf("[proc1] idle left me in charge.\n");
    printf("[proc1] I am halting the system.\n");
    hlt();
}

void kernel_start(void)
{
    process_map[0] = (process) { .pid = 1, .name = "idle()" };

    process_map[0].registers[1] =
        (uintptr_t) &process_map[0].stack[process_stack_length - 1];

    process_map[0].stack[process_stack_length - 1] = (uintptr_t) &idle;

    process_map[1] = (process) { .pid = 2, .name = "proc_one()" };

    process_map[1].registers[1] =
        (uintptr_t) &process_map[1].stack[process_stack_length - 1];

    process_map[1].stack[process_stack_length - 1] = (uintptr_t) &proc_one;

    clear_screen();
    idle();
}
