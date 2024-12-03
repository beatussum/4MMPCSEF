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


#ifndef PROCESS_H
#define PROCESS_H

#include "inttypes.h"

enum {
    process_map_length = 2 ///< The length of the process map
};

enum {
    process_register_number = 5,  ///< The number of registers to store
    process_stack_length    = 512 ///< The stack length to store
};

/**
 * @brief The state of a process
 */

typedef enum {
    process_state_electable, ///< The process can be elected
    process_state_elected    ///< The process is elected
} process_state;

/**
 * @brief A process
 */

typedef struct {
    int8_t        pid;   ///< The PID of the process
    const char*   name;  ///< The name of the process
    process_state state; ///< The state of the process

    /**
     * @brief The registers to store
     */

    uintptr_t registers[process_register_number];

    uintptr_t stack[process_stack_length]; ///< The stack to store
} process;

/**
 * @brief The constructor of \ref process
 *
 * @param[in] __pid The PID of the \ref process
 * @param[in] __name The name of the \ref process
 * @param[in] __callback The callback to use
 *
 * @return A constructed \ref process
 */

process process_create(int8_t __pid, const char* __name, void (*__callback)());

/**
 * @brief Switches from an old context to a new one
 *
 * @param[out] __old The old context
 * @param[in] __new The new context
 */

void ctx_sw(uintptr_t* __old, uintptr_t* __new);

extern process process_map[process_map_length]; ///< The process map

#endif // PROCESS_H
