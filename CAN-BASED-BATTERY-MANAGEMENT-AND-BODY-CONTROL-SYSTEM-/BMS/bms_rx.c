#include <LPC21xx.H>
#include "types.h"
#include "can_ids.h"
#include "../Drivers/can_driver.c"
#include "../Drivers/uart_driver.c"

#define FAN1 (1<<6)
#define FAN2 (1<<7)

void Fan_on(void){ IOSET0 = FAN2; IOCLR0 = FAN1; }
void Fan_off(void){ IOCLR0 = FAN1; IOCLR0 = FAN2; }

int main(){
    IODIR0 |= (FAN1 | FAN2);
    can2_init();
    uart0_init(115200);
    uart0_tx_string("BMS RX Ready\r\n");

    CAN2_MSG msg;
    while(1){
        can2_rx(&msg);
        if(msg.id == CAN_ID_BMS_HIGH_TEMP){
            uart0_tx_string("High Temperature!\r\n");
            Fan_on();
        } else if(msg.id == CAN_ID_BMS_NORMAL_TEMP){
            uart0_tx_string("Normal Temperature\r\n");
            Fan_off();
        }
    }
}
