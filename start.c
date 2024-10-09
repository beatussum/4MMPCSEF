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
#include "interrupt.h"
#include "stdio.h"
#include "time.h"

void idle()
{
    printf("[idle] I am trying to hand over to proc1...\n");
}

void proc_one()
{
    printf("[proc1] idle left me in charge.\n");
    printf("[proc1] I am halting the system.\n");
    hlt();
}

void kernel_start(void)
{
    clear_screen();
    set_clock_frequency(50);
    init_isr(32, &update_run_time_isr_wrapper);
    mask_irq(0, false);
    sti();

    while (true) {
        write_run_time();
    }
}
