#include "io430.h"


void main( void )
{
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR = 0xFF; //set up LED Pins as outputs
  P2DIR = 0XFF;
 
  P2SEL = 0;
  P2SEL2 = 0;

  //UNCOMMENT OUT THESE TO MAKE THE LEDS FLASH FASTER
 
  DCOCTL = CALDCO_16MHZ;
  BCSCTL1 = CALBC1_16MHZ;

 
  TA0CTL_bit.TASSEL1 = 1;
  TA0CTL_bit.TASSEL0 = 0;
  TA0CTL_bit.ID1 = 1;
  TA0CTL_bit.ID0 = 1;
  TA0CTL_bit.MC1 = 1;
  TA0CTL_bit.MC0 = 0;
 
  //BCSCTL1 = CALBC1_8MHZ;
  // DCOCTL = CALDCO_8MHZ;
 
  TACCR0 = 0xFFFF;
  while(1)
  {
  while (!TA0CTL_bit.TAIFG);
 
    TA0CTL_bit.TAIFG = 0; // Clear interrupt bit.
    TA0CTL_bit.TACLR = 0; 
 
    P1OUT = 0xFF;
    
    while (!TA0CTL_bit.TAIFG);
    
    TA0CTL_bit.TAIFG = 0; // Clear interrupt bit.
    TA0CTL_bit.TACLR = 0;
    
    P1OUT = 0x00;
 
  }
}
