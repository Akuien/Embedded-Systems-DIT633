// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// Work package 4
// Exercise 1 
// Submission code: AW1Y2XM (provided by your TA-s) 
// C++ code

/*Setting the pin for measuring the temperature to be 2 amongst the analog pins of Arduino.*/
int tempPin = 2;

/*Setup function: Here the interrupts are also defined, that the Arduino passively checks at a freq of 1 second (1Hz).*/
void setup()
{
  	/* Clear any side-running interrupts before running this section. */
  	cli();
  	/* Setting the IO status of the pins 7, 6, 5, 4, and 3 */
	DDRD = B11111000;
  	/* Setting them as LOW (0) at the start */
  	PORTD = B00000000;
    /* Start the serial console */
  	Serial.begin(9600);
  
  	/* Initialising the registers and counter values to 0 in Arduino. */
    TCCR1A = 0;      
    TCCR1B = 0;
    TCNT1  = 0;      
  	/* Constant that was derived from the clock speed of Arduino (16 000 000) divided by 
       the prescaler level (1024) - 1 */
  	OCR1A = 15624;
  
  	/* Setting the compare registers for incrementing at the desired frequency of once a second (1Hz) */
    TCCR1B |= (1 << WGM12);
    TCCR1B |= (1 << CS12) | (1 << CS10);
    TIMSK1 |= (1 << OCIE1A);
  
  	/* Re-enable the program to allow rest of the interrupts */
   	sei();
}

void loop() {}

/* The interrupt service routine (ISR) that is a set of commands run when the program is interrupted every second. */
ISR(TIMER1_COMPA_vect) 
{
  	/* Clear interrupts */
  	cli();
  
  	/* 
       Conversion of the recorded logs by the Temperature Sensor module in Arduino.
       At the tempPin, it reads the analog signal and converts it to temperature in degrees Celsius. 
    */
	int temp = ((analogRead(tempPin)* 5.0 / 1023.0)-0.5)*100; 
    Serial.print(temp);
    Serial.println();
  
  	/* An if-block setting the right amount of LEDs based on increasing temperature. The binary values that are based on the layout of
       the digital pins are set to 1 (HIGH), in an increasing manner. */
  	if (temp <= 10) {
  		PORTD = B10000000;
      	/* Setting the 7th pin on, and rest off */
    } else if ((temp > 0) && (temp <= 30)) {
    	PORTD = B11000000;
      	/* Setting the 7th and 6th pin on */
    } else if ((temp > 30) && (temp <= 60)) {
    	PORTD = B11100000;
        /* Setting 7th, 6th and 5th pin on */
    } else if ((temp > 60) && (temp <= 90)) {
    	PORTD = B11110000;
        /* Setting pins 7, 6, 5, and 4 on */
    } else {
    	PORTD = B11111000;
      	/* Setting all pins (7-3) on, assuming that the temperature is not less than 0, and greater than all of the previous temperature upper bounds (90 DEGREES)*/
    }
  
  	/* After completing the ISR, allow for other interrupts and continue the normal process. */
	sei();
}