#include  <msp430x14x.h>
void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  P2DIR |= 0x04;                            // P1.0 output
  P4DIR |= 0x01;
  TACTL = TASSEL_1 + MC_2 + TAIE;           // ACLK, contmode, interrupt

  _BIS_SR(LPM3_bits + GIE);                 // Enter LPM3 w/ interrupt
}


#pragma vector=TIMERA1_VECTOR
__interrupt void Timer_A(void)
{
   switch( TAIV )
   {
     case  2:  break;                        
     case  4:  break;                        
     case 10:  
               P2OUT ^= 0x04;                
               P4OUT ^= 0x01;  
               break;
  }
}
