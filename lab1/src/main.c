#include "time.h"
#include "io.h"
#include "gpio.h"
#include "uart.h"
#include "state.h"

#define CMDSIZE 10

void helper()
{
    uart_puts("---------------------------\n");
    uart_puts( "|> help - show command list\n" );
    uart_puts( "|> hello - print \"hello world\"\n" );
    uart_puts( "|> timestamp - print time \n" );
    uart_puts( "|> reboot - reboot system\n" );
    uart_puts("---------------------------\n");
}
void banner()
{
    uart_puts("#     # ###### #      #       ####     #  #  #  ####  #####  #      #####  \n");
    uart_puts("#     # #      #      #      #    #    #  #  # #    # #    # #      #    # \n");
    uart_puts("####### #####  #      #      #    #    #  #  # #    # #    # #      #    # \n");
    uart_puts("#     # #      #      #      #    #    #  #  # #    # #####  #      #    # \n");
    uart_puts("#     # #      #      #      #    #    #  #  # #    # #   #  #      #    # \n");
    uart_puts("#     # ###### ###### ######  ####      ## ##   ####  #    # ###### #####  \n\n\n");
}

void main()
{
    // set up serial console
    uart_init();
    // Hello World when startup
    banner();
    // Initialization
    char buf[CMDSIZE];

    while(1) {
        uart_puts( "pppy@osdi:# " );
        uart_readline( CMDSIZE, buf );

        if( !strcmp( "help", buf ) )
        {
            helper();
        }else if( !strcmp( "hello", buf ) ){
            uart_puts( "Hello World\n" );
        }else if( !strcmp( "timestamp", buf ) ){
            timestamp();
        }else if( !strcmp( "reboot", buf ) ){
            reset();
        }
        //else if( !strcmp( "reboot", buf ) )
        else{
            uart_puts( buf );
            uart_puts( ": command not found\n" );
        }
    }
}