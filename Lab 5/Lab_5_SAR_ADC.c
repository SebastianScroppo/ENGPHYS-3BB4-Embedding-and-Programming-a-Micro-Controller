#include "io430.h" 

void Delay(long n) 

{ 

  while (n--); 

} 
void main( void )
{
  
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR = 0xFF; //set up P1 as output
  P2DIR = 0x00; //set up P2 input
  
 
  P1OUT=128;

  while(1)
  {
    int half=64;
  for(int num = 7; num>=1; num--)
  {
    if(P2IN_bit.P0 == 1) 
  {
    P1OUT = P1OUT+half;
  }
    else P1OUT=P1OUT-half;
    half=half/2;
  }
  Delay(100);
      P1OUT=128;
  }
  
}
