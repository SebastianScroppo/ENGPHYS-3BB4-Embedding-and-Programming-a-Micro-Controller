#include "io430.h"

#pragma vector = PORT1_VECTOR
__interrupt void PORT1_ISR(void)
{
 unsigned long n = 100000;
   P1OUT_bit.P6 = 1;
   P1OUT_bit.P0 = 0;
   while (n--);
   P1OUT_bit.P6 = 0;
 P1IFG_bit.P3 = 0; // clear the interrupt request flag 
}



void Init(void)
{
  // initialize MSP430 hardware
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;

  // set system clock to calibrated values
  DCOCTL  = CALDCO_1MHZ;
  BCSCTL1 = CALBC1_1MHZ;
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
 
}

void main(void)
{ 
  Init();
  Init_UART();
  
  P1DIR=0x41;
  
  P1IE_bit.P3 = 1; // enable interrupts on P1.3 input 
  __enable_interrupt();
  while(1) P1OUT_bit.P0 = 1;


}

