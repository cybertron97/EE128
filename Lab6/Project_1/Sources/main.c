#include <hidef.h> /* common defines and macros */
#include <mc9s12dg256.h>
#include <stdio.h>

#define DELAY_TIME_FAST 3000
#define DELAY_TIME_SLOW 6000
unsigned long i;

void init(){
  DDRA = 0xff;
  PORTA = 0x30;
  DDRB = 0x00;
  PORTB = 0xff;
}

void Delay(unsigned long Speed){
  for(i = 0; i < Speed ;i++);
  return;
}

void main(void) {
  unsigned char FR1;
  unsigned char FR2;
  unsigned long Speed;
  init();
  while (1) {
    //FR1 = PORTB & 0x01;
    Speed = 3000;
    
      //PORTA = 0x35;
   
     {
      PORTA = 0x36;
      Delay(Speed);
      PORTA = 0x35;
      Delay(Speed);
      PORTA = 0x39;
      Delay(Speed);
      PORTA = 0x3A;
      Delay(Speed);
      //FR2 = FR1;
      //FR1 = PORTB & 0x01;
    }//
  }
}