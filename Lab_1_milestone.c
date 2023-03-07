#include "io430.h"

#define ON 1
#define OFF 0

#define RED_LED P1OUT_bit.P6
#define GREEN_LED P1OUT_bit.P0
#define BUTTON P1IN_bit.P3
int main( void )
{
  P1DIR = BIT0 + BIT6; //set up LED Pins as outputs

  WDTCTL = WDTPW + WDTHOLD;

  while (1) //loop
  {
    if (!BUTTON)
    { 
      RED_LED = ON;
      GREEN_LED = OFF;
    }
    else
    {
      RED_LED = OFF;
      GREEN_LED = ON;
    }

  }
}
