#include "uart.h"

void uart_init(){
    writeRegister(UART_INTEN, 0x0);//disable interrupts
    writeRegister(UART_BAUD, 0x0);//set baud rate
    writeRegister(UART_FLAG, 0x0);//clear flags

    printf("UART initialized\n");
}

void uart_send(char *data){
    while(*data){
        writeRegister(UART_DATA, *data);
        data++;
    }
}

char uart_recv(){
    return readRegister(UART_DATA);
}



