#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include <mc9s12dg256.h>

typedef void (*near tIsrFunc)(void); /* Type of interrupt vector entry */
__interrupt void IRQ_ISR(void); /* Declaration of ISR for IRQ */
const tIsrFunc _vect @0x3E72 = IRQ_ISR; /* 0x3E72: entry for IRQ */
// Let counter be a static variable initialized to 0
static unsigned char counter1 = 1;
static unsigned char counter2 = 0;

__interrupt void IRQ_ISR(void)
{
  //Update the clock tick and its display;
  //Read Port K;
  unsigned char segg[10] = {~0x3F,~0x06,~0x5B,~0x4F,~0x66,~0x6D,~0x7D,~0x07,~0x7F,~0x6F};
  
  //if (CNT_HLD is 1) return; /* rotate hold */
  if (PORTK & 0x01) return;
  //if (CNT_DIR is 1) /* rotate left */
  if (PORTK & 0x02) {
  PORTA = PORTA | (~0x01);
    //rotate left -- wrap around if end is reached; 
    if (counter1 > 10) {
      //counter2++;
      counter1 = 1; 
      
      if (counter2 > 10) counter2 = 1;
      if (counter2 == 1) PORTB = segg[0];
      else if(counter2 == 2) PORTB = segg[1];
      else if(counter2 == 3) PORTB = segg[2];
      else if(counter2 == 4) PORTB = segg[3];
      else if(counter2 == 5) PORTB = segg[4];
      else if(counter2 == 6) PORTB = segg[5];
      else if(counter2 == 7) PORTB = segg[6];
      else if(counter2 == 8) PORTB = segg[7];
      else if(counter2 == 9) PORTB = segg[8];
      else if(counter2 == 10) PORTB = segg[9]; 
      counter2++;
    } 
    if (counter1 == 1) PORTA = segg[0];
    else if(counter1 == 2) PORTA = segg[1];
    else if(counter1 == 3) PORTA = segg[2];
    else if(counter1 == 4) PORTA = segg[3];
    else if(counter1 == 5) PORTA = segg[4];
    else if(counter1 == 6) PORTA = segg[5];
    else if(counter1 == 7) PORTA = segg[6];
    else if(counter1 == 8) PORTA = segg[7];
    else if(counter1 == 9) PORTA = segg[8];
    else if(counter1 == 10) {
      PORTA = segg[9];
    }
    counter1++;
    
  } else if (!(PORTK & 0x02)) {
    PORTA = PORTA | (~0x01);
    //rotate right ?wrap around if end is reached;
    //Update counter displays; 
     if (counter1 < 1) {
      counter1 = 10;
      counter2--;
      if (counter2 < 1) counter2 = 10;
     if (counter2 == 10) PORTB = segg[9];
      else if(counter2 == 9) PORTB = segg[8];
     else if(counter2 == 8) PORTB = segg[7];
     else if(counter2 == 7) PORTB = segg[6];
     else if(counter2 == 6) PORTB = segg[5];
     else if(counter2 == 5) PORTB = segg[4];
     else if(counter2 == 4) PORTB = segg[3];
     else if(counter2 == 3) PORTB = segg[2];
     else if(counter2 == 2) PORTB = segg[1];
     else if(counter2 == 1) PORTB = segg[0];
    }
    if (counter1 == 10) PORTA = segg[9];
    else if(counter1 == 9) PORTA = segg[8];
    else if(counter1 == 8) PORTA = segg[7];
    else if(counter1 == 7) PORTA = segg[6];
    else if(counter1 == 6) PORTA = segg[5];
    else if(counter1 == 5) PORTA = segg[4];
    else if(counter1 == 4) PORTA = segg[3];
    else if(counter1 == 3) PORTA = segg[2];
    else if(counter1 == 2) PORTA = segg[1];
    else if(counter1 == 1) PORTA = segg[0];
    counter1--;
  
  }
}

void main(void) {
  // config PORTA and PORTB for output
  DDRA = 0xFF;
  PORTA = 0x00;
  DDRB = 0xFF;
  PORTB = 0x00;
  // config PORTK for input
  DDRK = 0x00;
  PORTK = 0x03;
  // Enable IRQ interrupts;
  PORTE = 0x2; /* IRQ PIN PE1 PULL HIGH */
  INTCR = 0xC0; /* IRQ to be falling edge triggered */
  
  /* and enable IRQ Interrupt */
  EnableInterrupts;
  for (;;){}  
}