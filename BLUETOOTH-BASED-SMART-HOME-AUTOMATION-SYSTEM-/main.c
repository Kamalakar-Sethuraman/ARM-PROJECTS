#include <LPC21xx.H>

#define  IN1 1<<6
#define  IN2 1<<7
#define LED1 1<<16
#define SW  1<<14

unsigned int flag = 0;

void UART0_CONFIG(void);
void UART0_TX(unsigned char);
void UART0_STRING(char *);
void FAN_ON(void);
void FAN_OFF(void);
unsigned char UART0_RX(void);


void timer0_isr(void) __irq
{
  T0IR = 0X01; // to clear the MR0 interrupt flag
  
  if(((IOPIN0>>SW)&1)==0)
    IOSET0 = LED1;
  else
    IOCLR0 = LED1;
 
VICVectAddr = 0;  // to indicate the end of isr
}

int main()
{
   unsigned char cmd;
   IODIR0 = IN1|IN2;
   IODIR1 = LED1;   // P1.16 as output

   T0MR0 = 7500000-1;  //500ms

   T0MCR = 0X03;   //MR0I & MR0R enabled interrupt action and reset action

   VICIntSelect = 0;   //IRQ
   VICVectCntl0 = (0x20)|4;   //Timer0 interrupt number is 4
   VICVectAddr0 = (unsigned long)timer0_isr;
   VICIntEnable = 1<<4;  //Enbaling the Timter0 interrupt to monitor the flag

   T0TCR = 0x01;  //enable timer

   UART0_CONFIG();
   
   while(1){
   
   cmd = UART0_RX();
   
    if((cmd == 'A')||(cmd == 'a'))
	{ 
	      UART0_STRING("FAN ON\r\n");
		  FAN_ON();
		  //break;
	}
	
	else if((cmd == 'B')||(cmd == 'b'))
	{	  
	      UART0_STRING("FAN OFF\r\n");
		  FAN_OFF();
		  //break;
	}
	
	//else
	//{	
	    //   UART0_STRING("INVALID CHOICE\r\n");
    //}
   }      
}

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

void FAN_ON(void)
{
   IOSET0 = IN1;
   IOCLR0 = IN2;
}				

void FAN_OFF(void)
{
   IOCLR0 = IN1;
   IOCLR0 = IN2;
}

void UART0_STRING(char *s)
{
   while(*s)
   {
      UART0_TX(*s++);
   }
}
