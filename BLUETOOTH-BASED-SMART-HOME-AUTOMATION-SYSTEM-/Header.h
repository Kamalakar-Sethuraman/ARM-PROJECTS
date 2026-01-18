#ifndef HEADER_H
#define HEADER_H

#define MAX_LENGTH 100
#define LED 1<<8

void UART0_CONFIG(void);
void UART0_TX(unsigned char);
void UART0_STRING(char *);
void LED_ON(void);
void LED_OFF(void);
void UART0_TX_STRING(unsigned char *);
void UART0_RX_STRING(unsigned char *);

#endif