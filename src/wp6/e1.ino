// // (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// // Work package 6 
// // Exercise 1
// // Submission code: E9K8FPL (provided by your TA-s) 

// // C++ code

//Defining the pins
#define ENCODER_A 2
#define ENCODER_B 3
#define POWER_1 5
#define POWER_2 6

int ENC_A_OUTPUT; // a-encoder signal
int ENC_B_OUTPUT; // b-encoder signal

int position_counter = 0; // pistion counter in ticks
float degree = 0; // current degree on the dc motor
int degtarget = 0; // the desired degree entered by the user
int e = 0; //error
int kp = 15; // Proportional constant for controller (tuning parameter)
int u_out = 0; // output of the controller
int speed = 0;

void setup()
{  
  Serial.begin(9600);
  pinMode(ENCODER_A, INPUT_PULLUP);
  pinMode(ENCODER_B, INPUT_PULLUP);
  pinMode(POWER_1, OUTPUT);
  pinMode(POWER_2, OUTPUT);
  
  /* 
  ATTACH INTERRUPT HERE. 
  */
  attachInterrupt(digitalPinToInterrupt(ENCODER_A), ISR_encoder, RISING);

 
  // Start the motor, just a tiny little bit because otherwise TinkerCad dies....
  analogWrite(POWER_2, 10);
  delay(200);
  analogWrite(POWER_1, 10);
}

void loop()
{
  /* Setting speed -------- E1.1 -------- */

  manage_counter(); //at start of execution, make sure everything is reset in the motor
  
  Serial.print("\n");
  Serial.print("\nDegrees: ");
  
  //Check if the dc motor made a full rotation
  //degrees within 360 degrees instead of 400, 420 degrees etc
  if (degree > 359) {
    //If the rotation was a full one, we subtarct 360 from the current degrees to get
    degree = degree - 360;
  }
  //print current position in degrees
  Serial.print(degree);
  Serial.print("\n");
  delay(200);// Get input 
  
  /* -------- E1.3 -------- */
  //update the target degree by adding the current degree on the rotor withb the new
  //desired position
  degtarget = getInput()+ degree;
  
  // Calculate initial error
  e = degtarget - degree;
    
  // Loop until error is zero
  while(e){
    
    // Map current position into degrees
    degree = map(position_counter,0,2300,0,360);
       
  	// Get necessary speed signal
  	speed = getAction(e);
    
  	// Send speed signal to motor
    // Rotating clockwise
    if(speed >= 0){
    	if (speed < 100) // motor does not react with too low inputs
      	speed = 100;
      analogWrite(POWER_2, 0);
      analogWrite(POWER_1, speed);
  	}
  
    // Rotating counter-clockwise
  	else{
    	if (-speed < 100) // motor does not react with too low inputs
      	speed = -100; 
      	analogWrite(POWER_1, 0);
      	analogWrite(POWER_2, -speed); 
    }
	
    // Calculate new error
  	e = degtarget - degree;
  }// when e==0, it means that the degtarget has been reached hence the motor should stop
  if (e == 0) {
    //stop the motor from continously rotating
  	analogWrite(POWER_1, 10);
    delay(200);
    analogWrite(POWER_2, 10);	
  }
}


int getAction(int error){
  /* 
  Calculate u_out as function of the error and the kp (tuning parameter). 
  */
  u_out = kp*e;
  
  if (u_out > 254){ //u_out cannot be more than 255...
  	return 255;
  }
  else if (u_out < -254){ //...or less than -254
    return -255;
  }  
  else
     return u_out;
}


void manage_counter() {
  //check if the counter has reached its max
  if(position_counter < -2299 || position_counter > 2299){
    //if max is reached, reset position counter
    position_counter = 0;
  }
}

//converting the counts in tick to degrees
void count_degrees(){
  //calculated value of 1 degree for conversion purposes
  int oneDegree = 2299/359;
  
  //convert our current counter to degrees
  degree = position_counter / oneDegree;
  
  //if degrees goes to max, reset degrees back to 0, as it has completed a full cycle.
  if(degree > 359 || degree < -359) {
    degree = 0;
  }
  //getting the absolute value of degrees when it may be < 0
  if(degree < 0) {
   	degree = -degree;
  }   
}

/* A method that handles the task of receiving input from the user, and storing it as an int. */
int getInput(){  
  int ready = 0;
  char buf[3];
  int input = -1;
  
  /* PROMPT */
  Serial.print("Please enter the desired position: \n");
  
  /* Takes the string input from the Serial console of tinkercad */
  while(!ready){
    ready = Serial.readBytes(buf,3);
    /* Converts string to int for getting what position to move the motor to. */
    input = atoi(&buf[0]);
  }
  
  return input;
} 

/*
void setMovement(int speed) {
  if(speed > 0){
    analogWrite(POWER_1, speed);
  } else if(speed < 0) {
    analogWrite(POWER_2, -speed);
  }
} */

//TO DO 3
void ISR_encoder(){
  /*
  READ THE ENCODER SIGNAL HERE.
  Read the encoder signals and increase or decrease pos accordingly.
  */
  ENC_A_OUTPUT = digitalRead(ENCODER_A);
  ENC_B_OUTPUT = digitalRead(ENCODER_B);

  // if signal at encoder a is on increase the position counter
  if(ENC_A_OUTPUT > ENC_B_OUTPUT) {
    position_counter++;
  } else {
    //if signal at encoder b is on, decrease the position counter
    position_counter--;
  }
}