// C++ code
// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// Work package 4
// Exercise 2 
// Submission code: AW1Y2XM (provided by your TA-s) 

//include the servo(motor) library
#include <Servo.h>


int MIN_DEGREE = 0;    // Defines the lowest degree for the Servo Motor
int MAX_DEGREE = 180; // Defines the largest degree for the Servo Motor

  
int DEGREE_TIME_MAPPING = 3; // Defines the amount of increment to map degrees to time


Servo seconds_servo; // Declare the servo motor
int current_degrees_rotated = 0; // Initialize the degrees of the motor to 0
int current_seconds = 0;     // Initialize the time passed to 0



void setup()
{
    //Set the timer to timer0
  	//set the CTC mode
    TCCR0A = (1<< WGM01);
  	
  	//value for ORC0A for microseconds
    OCR0A = 0xF9;
  
    // set the interrupt request
    TIMSK0 |= (1<<OCIE0A);
    sei(); // enable interrupt
  
  
    TCCR0B |= (1<<CS01); //Set the prescale
    TCCR0B |= (1<<CS00);
    
  
    seconds_servo.attach(10, MIN_DEGREE, MAX_DEGREE); // Set the motor to pin 12, while setting the min and max degrees to 0 to 180 respectively.
    seconds_servo.write(0); //set the motor to 0(zero)
    Serial.begin(9600); // Begin serial communication via port 9600
}

//Move the motor
void rotate_servo(){
  	 // Increment the rotation degrees and modulou it so if current_degrees is > 180, it is set to 0.
    //Incremenet UPPER_DEGREE (180) by 1 so when mDegrees is 180 it does not get set to 0.
    current_degrees_rotated = (current_degrees_rotated + DEGREE_TIME_MAPPING) % (MAX_DEGREE + 1);
    seconds_servo.write(current_degrees_rotated); 
    }

// The interrupt service routine (ISR) that is a set of commands run when the program is interrupted.
ISR(TIMER0_COMPA_vect)
{                          
    current_seconds++;    // Increment the time
  if (current_seconds > 59000) // check if time is larger than 60 seconds
        current_seconds = 0; 
  if (current_seconds % 1000 == 0){
    Serial.println(current_seconds/1000); // divide the current_seconds with a 1000 to print in seconds instead of microseconds
    rotate_servo(); //Rotate the motor after each second
  }
  
}


void loop()
{

}