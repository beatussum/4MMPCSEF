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
#include "tinyalloc.h"

/*********/
/* TYPES */
/*********/

typedef struct process_node {
    process* value;
    struct process_node* next;
} process_node;

typedef struct {
    process_node* head;
    process_node* tail;
} process_list;

/********************/
/* GLOBAL VARIABLES */
/********************/

static process_list process_process_list = { .head = NULL, .tail = NULL };
static size_t process_first_free = 1;

/************/
/* CHECKERS */
/************/

static inline bool process_list_is_empty(const process_list* __list)
    { return __list->head == NULL; }

/*************/
/* MODIFIERS */
/*************/

static void process_list_push_back(process_list* __list, process* __process)
{
    process_node* node = malloc(sizeof(process_node));
    *node = (process_node) { .next = NULL, .value = __process };

    if (process_list_is_empty(__list)) {
        __list->head = node;
        __list->tail = node;
    } else {
        __list->tail->next = node;
        __list->tail = node;
    }
}

static process* process_list_pop(process_list* __list)
{
    __list->tail->next = __list->head;
    __list->head = __list->head->next;

    __list->tail->next->next = NULL;
    __list->tail = __list->tail->next;

    return __list->tail->value;
}

/****************/
/* CONSTRUCTORS */
/****************/

int8_t process_create(const char* __name, void (*__callback)())
{
    process* ret = malloc(sizeof(process));

    if (ret != NULL) {
        process_list_push_back(&process_process_list, ret);

        *ret = (process) { .pid = process_first_free, .name = __name };
        ret->registers[1] = (uintptr_t) &ret->stack[process_stack_length - 1];
        ret->stack[process_stack_length - 1] = (uintptr_t) __callback;

        return process_first_free++;
    } else {
        return -1;
    }
}

/******************************/
/* GLOBAL GETTERS AND SETTERS */
/******************************/

process* process_current()
    { return process_process_list.head->value; }

/***********/
/* ACTIONS */
/***********/

void process_schedule()
{
    process *old = process_list_pop(&process_process_list);
    process *new = process_current();

    ctx_sw(old->registers, new->registers);
}
