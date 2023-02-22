// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// Work package 5 
// Exercise 1 
// Submission code: XXXXXX (provided by your TA-s) 

// Tinkercad Project link: 
// https://www.tinkercad.com/things/jMly8t0Wjwk?sharecode=ycNgbeGRXx4Kuxf4jcvB-7pJ05WKa3p1ajn-s9tvywc

/* Setup function for declaring which pins are to be used */
void setup()
{
  /* Arduino board used in this exercise has a set of defined pins 
     that can be used in building a circuit.*/

  /* Pin nr 12 is used for the blinking LED */
  pinMode(12, OUTPUT);
  /* Pin nr 13 is used for the LED that is turned on by the button */
  pinMode(13, OUTPUT);

  /*End of setup function*/
}

/* This function executes lines inside the body in a repeating manner. */
void loop()
{ 
  /* Sets the power ON by default for pin 13, which is kept unchanged in the looping function */
  digitalWrite(13, HIGH);
 
  /* ------------- */
  /* The bottom part represents the periodic blinking of the LED that is on pin 12, where it is turned
     on (HIGH) and off (LOW) every 1 second. */

  /* Sets the power at pin 12 to ON */
  digitalWrite(12, HIGH);
  /* add a delay / wait for 1000 ms (1 second) */
  delay(1000);
  /* Turns the power OFF for pin 12 */
  digitalWrite(12, LOW);
  /* waits again for 1000 ms (1 second) */
  delay(1000); 
  /*End of loop function*/
}
