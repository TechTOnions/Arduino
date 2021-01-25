/*
  Date: 23-01-21
  Code writen by: Dharmik
  LED blink code using millis
  Code is non blocking code
  Code uses 866 bytes of program memory and Global variables use 14 bytes
  Find more on www.TechTOnions.com
*/

#define LED 13                  // Defining an LED variable as 13 because our LED is connected to pin 13
unsigned long previousMillis;   // variable for comparing millis counter
boolean ledState = false;       // will determine current led state

void setup() {
  pinMode(LED, OUTPUT);         // Set LED pin as OUTPUT
}

void loop() {
  if (millis() - previousMillis >= 1000)  // check that 1000ms is pass
  {
    if (ledState == false) {              // check the leddState and toggle it. 
      ledState = true;
    }
    else {
      ledState = false;
    }
    digitalWrite(LED, ledState);          // Set LED state to ledState 
    previousMillis = millis();            // set previousMillis to current millis
  }
}
