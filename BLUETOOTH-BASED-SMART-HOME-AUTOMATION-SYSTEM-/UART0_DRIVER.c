#include"Header.h"
#include <LPC21xx.H>

void UART0_CONFIG(void)
{
    PINSEL0 = 0x05; //PO.O as Tx and P0.1 as Rx
	U0LCR = 0x83;   //8N1 frame format and making the DLAB = 1 to access DLL & DLM
	U0DLL = 97;     //97 or 0x61 lower 8 bits
	U0DLM = 0;      //upper 8 bits
    U0LCR = 0x03;   //making DLAB = 0 to access the U0THR & U0RBR
}

void UART0_TX(unsigned char txbyte)
{
   while(((U0LSR>>5)&1)==0);  //WAITING FOR THE U0THR TO GET EMPTY
   U0THR = txbyte;            //once it is empty write the data in U0THR
}

unsigned char UART0_RX(void)
{
   while((U0LSR&0x01)==0);  //aiting for the RBR to get all the data from RSR
   return U0RBR;
}

void UART0_STRING(char *s)
{
   while(*s)
   {
      UART0_TX(*s++);
   }
}

// Function to receive string until Enter key
void UART0_RX_STRING(unsigned char *buffer)
{
    unsigned int i = 0;
    unsigned char rxbyte;
   
    for(i = 0; i < MAX_LENGTH; i++) {
        rxbyte = UART0_RX();
       
        if((rxbyte == '\r')||(rxbyte == '\n')) {
            buffer[i] = '\0'; // Null terminate
            break;
        }
        else {
            buffer[i] = rxbyte; // Store character
        }
    }
   
    // If buffer full, ensure null termination
    if(i == MAX_LENGTH) {
        buffer[MAX_LENGTH - 1] = '\0';
    }

}

// Function to transmit string
void UART0_TX_STRING(unsigned char *buffer)
{
    unsigned int i;
   
    for(i = 0; i < MAX_LENGTH; i++) {
        if(buffer[i] == '\0') {
            break; // Stop at null terminator
        }
        UART0_TX(buffer[i]);
    }
   
    // Add newline after transmission
    UART0_TX('\r');
    UART0_TX('\n');
}