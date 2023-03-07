#include "io430.h" 

void Init(void) 

{ 

  // initialize MSP430 hardware 

  // Stop watchdog timer to prevent time out reset 

  WDTCTL = WDTPW + WDTHOLD; 

 

  // set system clock to calibrated values 

  DCOCTL  = CALDCO_1MHZ; 

  BCSCTL1 = CALBC1_1MHZ; 

} 

 

void Delay(long n) 

{ 

  while (n--); 

} 

 

void Init_UART(void) 

{ 

  // initialize the USCI 

  // RXD is on P1.1 

  // TXD is on P1.2 

  // configure P1.2 and P1.2 for secondary peripheral function 

  P1SEL_bit.P1  = 1; 

  P1SEL2_bit.P1 = 1; 

  P1SEL_bit.P2  = 1; 

  P1SEL2_bit.P2 = 1; 

 

  // divide by  104 for 9600b with  1MHz clock 

  // divide by 1667 for 9600b with 16MHz clock 

  UCA0BR1 = 0; 

  UCA0BR0 = 104; 

 

  // select UART clock source 

  UCA0CTL1_bit.UCSSEL1 = 1; 

  UCA0CTL1_bit.UCSSEL0 = 0; 

   

  // release UART RESET 

  UCA0CTL1_bit.UCSWRST = 0; 

  // UCA0CTL1 = 0X80; Shorter version of above commands 

  

} 

 

void putc(unsigned char c) 
{ 

  while (!IFG2_bit.UCA0TXIFG); 

  UCA0TXBUF = c; 

} 
unsigned char getc(void)
{
 while (!IFG2_bit.UCA0RXIFG);
 return (UCA0RXBUF);
}
 
// function to output a text message via putc( ) function
void puts(char *s)
{
while (*s) putc(*s++);
}

void main(void) 
{  

 Init(); 
 Init_UART(); 
 while(1)
 {
   char a = getc();
   if(a == 'a')
   {
     char string[] = "Hello World";
     puts(string);
   }
   if(a == 'b')
   {
     char string[] = "I love ENGPHYS 3BB4";
     puts(string);
   }
   
 } 

} 
