#include <LPC21xx.h>
#include "adc.h"

void ADC_Init(void)
{
    PINSEL1 |= (1<<24);   // AD0.2
    ADCR = (1<<21) | (4<<8);
}

int ADC_ReadSpeed(void)
{
    ADCR |= (1<<24);
    while(!(ADDR & (1<<31)));
    return (ADDR >> 6) & 0x3FF;
}

int ADC_ReadGear(void)
{
    return (IOPIN0 >> 16) & 0x03;  // switch-based gear
}
