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


#include "process.h"

static process* process_map[process_map_length] = {};

void process_create(
    process* __process,
    int8_t __pid,
    const char* __name,
    void (*__callback)()
)
{
    *__process = (process) { .pid = __pid, .name = __name };

    __process->registers[1] =
        (uintptr_t) &__process->stack[process_stack_length - 1];

    __process->stack[process_stack_length - 1] = (uintptr_t) __callback;
}

const process* process_current()
    { return process_map[0]; }

void process_add_to_map(size_t __index, process* __process)
    { process_map[__index] = __process; }

void process_schedule()
{
    process* tmp = process_map[0];
    process_map[0] = process_map[1];
    process_map[1] = tmp;

    ctx_sw(process_map[1]->registers, process_map[0]->registers);
}
