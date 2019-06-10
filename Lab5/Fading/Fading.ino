/*
  Fading

  This example shows how to fade an LED using the analogWrite() function.

  The circuit:
  - LED attached from digital pin 9 to ground.

  created 1 Nov 2008
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fading
*/

//// LED connected to digital pin 9
//int ledPin = 3;  
//void setup() {
//  // nothing happens in setup
//  TCCR2B = (TCCR2B & 0xF8) | 0x05;
//}
//
//void loop() {
//  analogWrite(ledPin, 123);
////  analogWrite(ledPin, 127.5);
////  analogWrite(ledPin, 252.45);
//delay(100000);
//}

//// LED connected to digital pin 9
//int ledPin = 3;  
//void setup() {
//  // nothing happens in setup
//  //TCCR2B = (TCCR2B & 0xF8) | 0x05;
//}
//
//void loop() {
//  analogWrite(ledPin, 200);
////  analogWrite(ledPin, 127.5);
////  analogWrite(ledPin, 252.45);
//}

// LED connected to digital pin 9
int ledPin = 3;  
void setup() {
  // nothing happens in setup
  TCCR2B = (TCCR2B & 0xF8) | 0x05;
}

void loop() {
  analogWrite(ledPin, 385);
//  analogWrite(ledPin, 127.5);
//  analogWrite(ledPin, 252.45);
}
