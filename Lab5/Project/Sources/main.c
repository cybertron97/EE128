#include <hidef.h> /* common defines and macros */
#include <mc9s12dg256.h>
#include <stdio.h>

unsigned long risingEdge1, risingEdge2, downEdge, period;

void init(){
  DDRA = 0xff;
  DDRB = 0xff;
  PORTA = 0x00;
  PORTB = 0x00;

  DDRT = 0x00;

  TSCR1 = 0x90; /* enable timer counter, enable fast flag clear*/
  TIOS &= ~0x1; /* enable input-capture 0*/
  TSCR2 = 0x03; /* disable TCNT overflow interrupt, set prescaler to 64 */

  EnableInterrupts;
  risingEdge1 = 0;
  risingEdge2 = 0;
  downEdge = 0;
  period = 0;
}

void myDis(unsigned long x){
  unsigned char decoder[10] = {~0x3F,~0x06,~0x5B,~0x4F,~0x66,~0x6D,~0x7D,~0x07,~0x7F,~0x6F };
  if (x >= 100) {
    x = 99;
  }
  PORTA = decoder[x/10];
  PORTB = decoder[x%10];
  return;
}

void main(void) {
  unsigned long i;
  init();// initialize

  while (1) {

    TCTL4 = 0x01; /* capture the rising edge of the PT0 pin */
    TFLG1 = 0x1;
    while (!(TFLG1 & 0x1)); /* wait for the first rising edge */
    risingEdge1 = TC0; /* save the first captured edge and clear C0F flag */

    TCTL4 = 0x02;  //caputre downEdge
    while (!(TFLG1 & 0x1)); /* wait for the second rising edge */
    downEdge = TC0;

    TCTL4 = 0x01;  //caputre risingEdge2
    while (!(TFLG1 & 0x1)); /* wait for the second rising edge */
    risingEdge2 = TC0;

    myDis((downEdge - risingEdge1) * 100 / (risingEdge2 - risingEdge1));
    // myDis((downEdge - risingEdge_pres) * 100 / (765)); //testing
    for(i = 0; i < 1000; i++){
      TC0 = 0;
    }
  }
}