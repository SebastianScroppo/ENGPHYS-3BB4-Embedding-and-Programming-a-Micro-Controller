#include "io430.h" 
void main( void )
{
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR = 0xFF; //set up P1 as output
  P2DIR = 0x00; //set up P2 input
  
  

  while(1)
  {
  if(P2IN_bit.P0 == 1) P1OUT++;
  if(P2IN_bit.P0 == 0) P1OUT--;
 
  }
 
  }

