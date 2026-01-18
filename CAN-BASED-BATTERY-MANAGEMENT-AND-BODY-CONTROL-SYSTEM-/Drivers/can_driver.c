#include <LPC21xx.H>
#include "types.h"

void can2_init(void){
    PINSEL1 |= 0x00014000; // P0.23 TD2, P0.24 RD2
    VPBDIV = 1; // PCLK = 60MHz

    C2MOD = 0x1; // Reset mode
    AFMR  = 0x2; // Accept all
    C2BTR = 0x001C001D; // 125kbps
    C2MOD = 0x0; // Normal mode
}

void can2_tx(CAN2_MSG m){
    C2TID1  = m.id;
    C2TFI1  = (m.dlc << 16);
    if(m.rtr == 0){
        C2TFI1 &= ~(1<<30); // Data frame
        C2TDA1  = m.byteA;
        C2TDB1  = m.byteB;
    } else {
        C2TFI1 |= (1<<30); // RTR
    }
    C2CMR = (1<<0) | (1<<5);
    while((C2GSR & (1<<3)) == 0);
}

void can2_rx(CAN2_MSG *m){
    while((C2GSR & 0x1) == 0);
    m->id   = C2RID;
    m->dlc  = (C2RFS >> 16) & 0xF;
    m->rtr  = (C2RFS >> 30) & 0x1;
    if(m->rtr == 0){
        m->byteA = C2RDA;
        m->byteB = C2RDB;
    }
    C2CMR = (1<<2);
}
