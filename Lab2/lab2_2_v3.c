#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include <mc9s12dg256.h>


 unsigned power(unsigned base, unsigned degree) {
  unsigned result =1 ; 
  unsigned term = base;
  while (degree) {
  if (degree & 1)
  result *= term; 
  term *=term;
  degree= degree>>1;
  }
  return result;
  }
  
void main(void) {
  /* put your own code here */
  unsigned long i;
  int base = 2;
  int exp = 8;
  int power1;
  int j;

  unsigned char CNT_DIR;
  unsigned char ROT_DIR;
  
  
 
  
  DDRA = 0xFF;
  PORTA = 0x00;
  DDRB = 0xFF; 
  PORTB = 0x00;
  DDRK = 0x00;
  PORTK = 0xFF;
  
  for (;;) {
    for (i = 0; i < 150000; i++); 

    
    CNT_DIR = PORTK & 0x01;
    ROT_DIR = PORTK & 0x02;
    PORTB=255;
    if (!CNT_DIR)
        PORTA--; 
    if (CNT_DIR) 
        PORTA++;                                                             
   {
     for(j=0; i<=exp; j++)
        power1= power(2,exp); 
        if(j > 8) j = 0;
         PORTB = power1;
         
    }
   
   
    
      //  PORTB = PORTB << 1;
    
  }
  /* please make sure that you never leave main */
}