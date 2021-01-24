/*
  Date: 23-01-21
  Code writen by: Dharmik
  LED blink code using a counter 
  Code is non blocking code
  Code uses 810 bytes of program memory and Global variables use 13 bytes
  Find more on www.TechTOnions.com
*/

#define LED 13    // Defining an LED variable as 13 because our LED is connected to pin 13
long counter = 0; // Defining counter variable for counting

void setup() {
  pinMode(LED, OUTPUT); // Set LED pin as OUTPUT
}

void loop() {

  counter++;                 // will increment counter by 1 
  if (counter == 100000)     // Check if conter value reach to 100000
  {
    digitalWrite(LED, HIGH); // turn LED ON by writing HIGH (Sending 5v to pin 13)
  }
  else if (counter == 200000) // Check if conter value reach to 200000
  {
    counter = 0;             // making counter value to 0
    digitalWrite(LED, LOW);  // turn LED OFF by writing LOW (Sending 0v to pin 13)
  }
  //Code is non blocking you can add your loop code after this
}
