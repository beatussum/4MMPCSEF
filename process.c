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

process process_map[process_map_length] = {};

process process_create(int8_t __pid, const char* __name, void (*__callback)())
{
    process ret = { .pid = __pid, .name = __name };

    ret.registers[1] = (uintptr_t) &ret.stack[process_stack_length - 1];
    ret.stack[process_stack_length - 1] = (uintptr_t) __callback;

    return ret;
}
