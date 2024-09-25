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


#ifndef INTTYPES_H
#define INTTYPES_H

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;
typedef signed long long int64_t;
typedef unsigned long long uint64_t;

typedef int intptr_t;
typedef unsigned int uintptr_t;

#define PRIu8 "uhh"
#define PRIu16 "uh"
#define PRIu32 "u"
#define PRIu64 "ull"

#define PRId8 "dhh"
#define PRId16 "dh"
#define PRId32 "d"
#define PRId64 "dll"

#define PRIi8 "ihh"
#define PRIi16 "ih"
#define PRIi32 "i"
#define PRIi64 "ill"

#define PRIx8 "xhh"
#define PRIx16 "xh"
#define PRIx32 "x"
#define PRIx64 "xll"

#endif

