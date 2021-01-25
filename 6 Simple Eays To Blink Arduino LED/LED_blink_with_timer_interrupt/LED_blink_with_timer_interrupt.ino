/*
  Date: 23-01-21
  Code writen by: Dharmik
  LED blink code using timer interrupt
  Code is non blocking code and tested on Arduino UNO, Nano, Mega
  Code uses 880 bytes of program memory and Global variables use 10 bytes
  Find more on www.TechTOnions.com
*/

#define LED 13
boolean ledState = false;          //determines current state of led

void setup() {
  pinMode(LED, OUTPUT);
  TCCR1A = 0;                      //Reset Timer1 control Registor A

  bitClear(TCCR1B, WGM13);         //Set CTC mode
  bitSet(TCCR1B, WGM12);


  bitSet(TCCR1B, CS12);            //Set prescaler to 1024
  bitClear(TCCR1B, CS11);
  bitSet(TCCR1B, CS10);

  //Reset Timer1
  TCNT1 = 0;

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

  bitSet(TIMSK1, OCIE1A); // Enable Timer1 compare interrupt
  sei();                  // Enable global interrupts
}

void loop() {
  // put your main code here, to run repeatedly:
}

ISR(TIMER1_COMPA_vect)
{
  if (ledState)                // check if ledstate is true then convert to false
  {
    ledState = false;
  }
  else                         // if ledstate is false then this make it true
  {
    ledState = true;
  }
  digitalWrite(LED, ledState); //Set LED pin state as per ledState 
}
