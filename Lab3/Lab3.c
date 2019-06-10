#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include <mc9s12dg256.h>

typedef void (*near tIsrFunc)(void); /* Type of interrupt vector entry */
__interrupt void IRQ_ISR(void); /* Declaration of ISR for IRQ */
const tIsrFunc _vect @0x3E72 = IRQ_ISR; /* 0x3E72: entry for IRQ */
// Let counter be a static variable initialized to 0
static unsigned char counter1 = 0;
static unsigned char counter2 = 0;

__interrupt void IRQ_ISR(void)
{
  unsigned long i;
  //Update the clock tick and its display;
  //Read Port K;
  unsigned char segg[10] = {~0x7E,~0x30,~0x6D,~0x79,~0x33,~0x5B,~0x5F,~0x70,~0x7F,~0x7B};
  //for (i = 0; i < 150000; i++); 
  
  //if (CNT_HLD is 1) return; /* rotate hold */
  if ((PORTK & 0x01)) {
    return;
  }
  //if (CNT_DIR is 1) /* rotate left */
  if ((PORTK & 0x02)) {
    //rotate left -- wrap around if end is reached;
    if (counter1 == 0) PORTA = segg[0];
    else if(counter1 == 1) PORTA = segg[1];
    else if(counter1 == 2) PORTA = segg[2];
    else if(counter1 == 3) PORTA = segg[3];
    else if(counter1 == 4) PORTA = segg[4];
    else if(counter1 == 5) PORTA = segg[5];
    else if(counter1 == 6) PORTA = segg[6];
    else if(counter1 == 7) PORTA = segg[7];
    else if(counter1 == 8) PORTA = segg[8];
    else if(counter1 == 9) PORTA = segg[9];
    counter1++;
    if (counter1 > 9) counter1 = 0;  
  }

  else {
    //rotate right – wrap around if end is reached;
    //Update counter displays;
    if (counter1 == 9) PORTA = segg[9];
    else if(counter2 == 8) PORTA = segg[8];
    else if(counter2 == 7) PORTA = segg[7];
    else if(counter2 == 6) PORTA = segg[6];
    else if(counter2 == 5) PORTA = segg[5];
    else if(counter2 == 4) PORTA = segg[4];
    else if(counter2 == 3) PORTA = segg[3];
    else if(counter2 == 2) PORTA = segg[2];
    else if(counter2 == 1) PORTA = segg[1];
    else if(counter2 == 0) PORTA = segg[0];
    counter1--;
    if (counter1 < 0) counter1 = 10;
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