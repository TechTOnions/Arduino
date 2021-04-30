/*
  Date: 23-01-21
  Code written by: Dharmik
  LED blink code using Watchdog timer interrupt
  Code is non-blocking code and tested on Arduino UNO, Nano, Mega
  Code uses 810 bytes of program memory and Global variables use 10 bytes
  Find more on www.TechTOnions.com
*/

#include <avr/wdt.h>                                          //include avr Watchdog timer liberary
#define LED 13                                                //define LED pin as 13
boolean ledState = false;                                     //determines current state of led

void setup() {
  pinMode(LED, OUTPUT);                                       //Set LED pin as an OUTPUT
  cli();                                                      //Disable all interrupt occurring
  WDTCSR = (1 << WDCE) | (1 << WDE);                          //enable Watchdog interrupt

  /********************************************************************************************/
  //Uncomment any one-time interval as per your requirement

  //WDTCSR = (1 << WDIE);                                     //16ms
  //WDTCSR = (1 << WDIE) | (1 << WDP0);                       //32ms
  //WDTCSR = (1 << WDIE) | (1 << WDP1);                       //64ms
  //WDTCSR = (1 << WDIE) | (1 << WDP1) | (1 << WDP0);         //0.125
  //WDTCSR = (1 << WDIE) | (1 << WDP2);                       //0.25s
  //WDTCSR = (1 << WDIE) | (1 << WDP2) | (1 << WDP0);         //0.5s
  WDTCSR = (1 << WDIE) | (1 << WDP2) | (1 << WDP1);           //1s
  //WDTCSR = (1<<WDIE)| (1<<WDP2) | (1<<WDP1) | (1<<WDP0);    // 2s
  //WDTCSR = (1<<WDIE)| (1<<WDP3);                            //4s
  //WDTCSR = (1 << WDIE) | (1 << WDP3) | (1 << WDP0);         //8s

  /*******************************************************************************************/

  sei();                                                      //Enable interrupts
}

void loop() {
  // put your main code here, to run repeatedly:
}


ISR(WDT_vect) {                                    // Watchdog interrupt vector
  if (ledState)                                    //check if ledstate is true then convert to false
  {
    ledState = false;
  }
  else                                             // if ledstate is false then this make it true
  {
    ledState = true;
  }
  digitalWrite(LED, ledState);                    //Set LED pin state as per ledState          
}
