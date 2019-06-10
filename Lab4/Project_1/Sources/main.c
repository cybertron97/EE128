#include <hidef.h> /* common defines and macros */
#include <mc9s12dg256.h>
#include <stdio.h>

unsigned int data;
unsigned long i;
unsigned char decimal = ~0x80 ;

void init(){
  DDRA = 0xff;
  DDRB = 0xff;
  PORTA = 0x00;
  PORTB = 0x00;
  EnableInterrupts;
  ATD0CTL2 = 0xc0;
  for (i=0;i<150000;i++);//wait 20us
  ATD0CTL3 = 0x08;
  ATD0CTL4 = 0x60;//for 10-bit
  //ATD0CTL4 = 0xE0; // for 8-bit
}

void main(void) {
  //unsigned char decoder[10] = {0x7E,0x30,0x6D,0x79,0x33,0x5B,0x5F,0x70,0x7F,0x7B };
//  unsigned char decoder[10] = {~0x7E,~0x30,~0x6D,~0x79,~0x33,~0x5B,~0x5F,~0x70,~0x7F,~0x7B };
unsigned char decoder[10] = {~0x3F,~0x06,~0x5B,~0x4F,~0x66,~0x6D,~0x7D,~0x07,~0x7F,~0x6F };
unsigned char decoder2[10] = {~0x3F,~0x06,~0x5B,~0x4F,~0x66,~0x6D,~0x7D,~0x07,~0x7F,~0x6F };

  init();
   while (1) {
    ATD0CTL5 = 0x80;
    while (!(ATD0STAT0 & 0x80));
    data = ATD0DR0;
    data = data*50/1023;//for 10-bit
   //data = data*50/255; // for 8-bit
   // data = 24;
  //  PORTA = ~ 0x80;
   
    PORTA = decoder[data/10];
    PORTA &= 0x7F; //|= ~(0x80);
    PORTB = decoder[data%10];
    // printf("%d", data);
    for(i = 0; i < 300000; i++);
  } 
 
}
