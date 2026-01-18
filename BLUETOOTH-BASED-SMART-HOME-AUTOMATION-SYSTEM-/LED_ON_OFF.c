#include"Header.h"
#include <LPC21xx.H>

void LED_ON(void)
{
    IOCLR0 = LED;
}				

void LED_OFF(void)
{
   IOSET0 = LED;
}