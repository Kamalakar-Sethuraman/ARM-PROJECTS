#include <LPC21xx.H>
#include "types.h"
#include "can_ids.h"
#include "../Drivers/can_driver.c"
#include "../Drivers/delay.c"

#define SW1 (1<<14)
#define SW2 (1<<15)
#define SW3 (1<<16)

int main(){
    CAN2_MSG left, right, wiper;
    can2_init();

    left.id  = CAN_ID_BCM_LEFT;
    left.rtr = 0; left.dlc = 4; left.byteA = 0xDDCCBBAA;

    right.id = CAN_ID_BCM_RIGHT;
    right.rtr = 0; right.dlc = 4; right.byteA = 0xDDCCBBAA;

    wiper.id = CAN_ID_BCM_WIPER;
    wiper.rtr = 0; wiper.dlc = 4; wiper.byteA = 0xDDCCBBAA;

    while(1){
        if((IOPIN0 & SW1) == 0){ can2_tx(left); delay_ms(200); }
        if((IOPIN0 & SW2) == 0){ can2_tx(right); delay_ms(200); }
        if((IOPIN0 & SW3) == 0){ can2_tx(wiper); delay_ms(200); }
        delay_ms(100);
    }
}
