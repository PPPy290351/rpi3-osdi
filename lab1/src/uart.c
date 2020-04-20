#include "gpio.h"
#include "uart.h"

/**
 * Set baud rate and characteristics (115200 8N1) and map to GPIO
 */
void uart_init()
{
    register unsigned int r;

    /* initialize UART */
    *AUX_ENABLES |= 1;      // enable UART1, AUX mini uart
    *AUX_MU_CNTL_REG = 0;   // Disable transmitter and receiver during configuration
    *AUX_MU_IER_REG = 0;    // Disable interrupt because currently you don’t need interrupt
    *AUX_MU_LCR_REG = 3;    // Set the data size to 8 bit
    *AUX_MU_MCR_REG = 0;    // Don’t need auto flow control
    *AUX_MU_BAUD_REG = 270; // Set baud rate to 115200
    *AUX_MU_IIR_REG = 0xc6; // No FIFO
    
    /* map UART1(mini-UART) to GPIO pins */
    r=*GPFSEL1;
    r&=~((7<<12)|(7<<15)); // gpio14, gpio15
    r|=(2<<12)|(2<<15);    // alt5
    *GPFSEL1 = r;
    *GPPUD = 0;            // enable pins 14 and 15
    r=150; while(r--) { asm volatile("nop"); }
    *GPPUDCLK0 = (1<<14)|(1<<15);
    r=150; while(r--) { asm volatile("nop"); }
    *GPPUDCLK0 = 0;        // flush GPIO setup

    // Re-enable transmitter and receiver
    *AUX_MU_CNTL_REG = 3;      // enable Tx, Rx
}

/**
 * Send a character
 */
void uart_send(unsigned int c) {
    /* wait until we can send */
    do{asm volatile("nop");}while(!(*AUX_MU_LSR_REG&0x20)); // if Transmitter is idle 
    /* write the character to the buffer */
    *AUX_MU_IO_REG=c;
}

/**
 * Receive a character
 */
char uart_getc() {
    char r;
    /* wait until something is in the buffer */
    do{asm volatile("nop");}while(!(*AUX_MU_LSR_REG&0x01)); // receive FIFO holds at least 1symbol (Data ready)
    /* read it and return */
    r=(char)(*AUX_MU_IO_REG);
    /* convert carrige return to newline */
    return r=='\r'?'\n':r;
}

/**
 * Display a string
 */
void uart_puts(char *s) {
    while(*s) {
        /* convert newline to carrige return + newline */
        if(*s=='\n')
            uart_send('\r');
        uart_send(*s++);
    }
    // uart_send('\r');
    // uart_send('\n'); // if disabled, need append "\n" self 
}

int uart_readline (int size, char *buf) {
    int cnt;
    for(cnt = 0; cnt < size; ++cnt)
    {
        // getc before send and store to buf
        buf[cnt] = uart_getc();
        uart_send( buf[cnt] );
        if( buf[cnt] == '\n' )
        {
            uart_send( '\r' );
            cnt++;
            break;
        }
    }
    buf[cnt - 1] = 0; // replace '\n'
    return cnt;
}