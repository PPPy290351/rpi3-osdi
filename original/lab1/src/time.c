#include "io.h"
#include "uart.h"
#define dps 100000000

void timestamp() {

    register unsigned long time_FRQ;
    register unsigned long time_PCT;

    // get the current counter frequency
    asm volatile ("mrs %0, cntfrq_el0" : "=r"(time_FRQ));
    // read the current counter
    asm volatile ("mrs %0, cntpct_el0" : "=r"(time_PCT));

    unsigned long long count = (unsigned long long)time_PCT, 
                        freq = (unsigned long long)time_FRQ,
                        intp = count / freq,
                        frap = count * dps / freq % dps;

    uart_puts("[");
    uart_puts(itoa((int)intp, 10));
    uart_puts(".");
    uart_puts(itoa((int)frap, 10));
    uart_puts("]\n");
    
}