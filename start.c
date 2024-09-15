#include "console.h"
#include "cpu.h"

void kernel_start(void)
{
    clear_screen();
    set_cursor(0, 0);
    console_putbytes("iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii", 100);
    scroll();

    // On ne doit jamais sortir de kernel_start
    while (1) {
        hlt(); //< Cette fonction arrete le processeur
    }
}

