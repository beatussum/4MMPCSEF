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
#include "debug.h"

void write_time(time_t __time)
{
    __time /= 1000;

    time_t hours  = __time / 60 / 60;
    __time       -= hours * 60 * 60;

    time_t minutes  = __time / 60;
    __time         -= minutes * 60;

    set_cursor(0, 0);
    printf("%*" PRIi32 ".4d:%.2d:%.2d", column_number, hours, minutes, __time);
}
