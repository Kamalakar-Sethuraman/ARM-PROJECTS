#include <LPC21xx.H>
#include "types.h"
#include "can_ids.h"
#include "../Drivers/can_driver.c"
#include "../Drivers/delay.c"

int main(){
    CAN2_MSG m1, m2;
    can2_init();

    m1.id = CAN_ID_BMS_HIGH_TEMP;
    m1.rtr = 0;
    m1.dlc = 4;
    m1.byteA = 0xDDCCBBAA;
    m1.byteB = 0;

    m2.id = CAN_ID_BMS_NORMAL_TEMP;
    m2.rtr = 0;
    m2.dlc = 4;
    m2.byteA = 0xDDCCBBAA;
    m2.byteB = 0;

    while(1){
        // simulate temperature threshold, replace with ADC reading
        int temp = 32; // Example
        if(temp > 30){
            can2_tx(m1);
        } else {
            can2_tx(m2);
        }
        delay_ms(1000);
    }
}
