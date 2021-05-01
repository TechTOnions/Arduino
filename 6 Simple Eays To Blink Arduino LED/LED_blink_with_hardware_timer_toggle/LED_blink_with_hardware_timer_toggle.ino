/*
  Date: 23-01-21
  Code written by: Dharmik
  LED blink code using hardware timer interrupt
  This method only work for Digital pin 9
  Code is non blocking code and tested on Arduino UNO, Nano
  Code uses 634 bytes of program memory and Global variables use 9 bytes
  Find more on www.TechTOnions.com
*/

#define LED 9
void setup() {
  pinMode(LED, OUTPUT);

  TCCR1A = 0;               //Reset Timer1 control Registor A

  bitClear(TCCR1B, WGM13);  //Set CTC mode
  bitSet(TCCR1B, WGM12);

  bitSet(TCCR1B, CS12);    //Set prescaler to 1024
  bitClear(TCCR1B, CS11);
  bitSet(TCCR1B, CS10);

  //set compare value
  //max value  (16bit Timer) = 65535
  /*******************************************
    To calculate compare value

    OCR1A = (time(s) * clock Freq.)/prescaler
    OCR1A = (1*16*10^6)/1024
  ********************************************/
  //OCR1A = 3906;     //for 0.25sec
  //OCR1A = 7812;    //for 0.5sec
  OCR1A = 15625;   //for 1sec
  //OCR1A = 31250;   //for 2sec

  //  OCR1A= 62500;
  bitSet(TCCR1A, COM1A0); // Toggle pin OC1A (9)
}

void loop()
{

}
