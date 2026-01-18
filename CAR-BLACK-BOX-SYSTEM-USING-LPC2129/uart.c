#include <LPC21xx.h>
#include "uart.h"

void UART_Init(void)
{
    PINSEL0 |= 0x05;
    U0LCR = 0x83;
    U0DLL = 97;
    U0LCR = 0x03;
}

void UART_Tx(char c)
{
    while(!(U0LSR & (1<<5)));
    U0THR = c;
}

void UART_SendLogs(void)
{
    char *log = "Speed,Gear,Time\n";
    while(*log)
        UART_Tx(*log++);
}
