#include <LPC21xx.H>
#include "types.h"
#include "can_ids.h"
#include "../Drivers/can_driver.c"
#include "../Drivers/uart_driver.c"
#include "../Drivers/delay.c"

#define RIGHT_LED (1<<8)
#define LEFT_LED  (1<<9)
#define WIPER1   (1<<6)
#define WIPER2   (1<<7)

void Fan_Right_on(void){ IOSET0 = WIPER1; IOCLR0 = WIPER2; }
void Fan_Left_on(void){ IOSET0 = WIPER2; IOCLR0 = WIPER1; }
void Fan_off(void){ IOCLR0 = WIPER1; IOCLR0 = WIPER2; }

int main(){
    IODIR0 |= (RIGHT_LED | LEFT_LED | WIPER1 | WIPER2);
    IOSET0 = (RIGHT_LED | LEFT_LED);

    can2_init();
    uart0_init(115200);
    uart0_tx_string("BCM RX Ready\r\n");

    CAN2_MSG msg;
    unsigned int i;
    while(1){
        can2_rx(&msg);
        if(msg.id == CAN_ID_BCM_RIGHT){
            uart0_tx_string("Right Indicator ON\r\n");
            for(i=0;i<10;i++){ IOCLR0=RIGHT_LED; delay_ms(50); IOSET0=RIGHT_LED; }
        }
        else if(msg.id == CAN_ID_BCM_LEFT){
            uart0_tx_string("Left Indicator ON\r\n");
            for(i=0;i<10;i++){ IOCLR0=LEFT_LED; delay_ms(50); IOSET0=LEFT_LED; }
        }
        else if(msg.id == CAN_ID_BCM_WIPER){
            uart0_tx_string("Wiper ON\r\n");
            Fan_Left_on(); delay_ms(500); Fan_off(); delay_ms(100);
            Fan_Right_on(); delay_ms(500); Fan_off();
        }
    }
}
