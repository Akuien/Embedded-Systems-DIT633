// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27
// Work package 5
// Exercise 3
// Submission code: MB58AHJ (provided by your TA-s)
// C++ code

//The DHT library by Adafruit was used to gather temperature readings captured by the DHT22 sensor.
#include <DHT.h>
#include <Adafruit_Sensor.h>

//Making an instance of the DHT class that takes the readings at pin 2
DHT dht = DHT(2, DHT22);

//Definition of the LED colors that a digital pin represents on the Arduino board
#define BLUE 7
#define GREEN 6
#define RED 5

/*Setting the pin for measuring the light sensor to be at A0 on the Arduino board.*/
const int lightPin = A0;
/* Defining a periodicity interval that is the delay between which the light + temp sensor reads (here set as 1 second (1000 ms)) */
int interval = 1000;

/* The setup function for the Arduino board */
void setup() {
  Serial.begin(9600);
  /* Starting the dht, to begin logging */
  dht.begin();
  /* Setting digital pins 7, 6 and 5 as OUTPUT, corresponding to the LEDs */
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}

/* The looping function of the Arduino board */
void loop() {
  /* Storing the logs of the light sensor based on luminosity that is recepted */
  int lightReading = analogRead(lightPin);
  /* A map() function in Arduino that converts value from the darkest luminosity reading (11) 
  on light sensor, to the brightest recorded rating (820) to a percentage equivalent (0 - 100%) */
  lightReading = map(lightReading, 11, 820, 0, 100);

  /* Prints the light reading for checking visually on the Serial Console */
  Serial.print("Light sensor: ");
  Serial.print(lightReading);
  Serial.println();
  Serial.println();
  
  /* A DHT library method to read the temperature detected on the DHT22 sensor, 
  stored in an int variable*/
  int tempReading = dht.readTemperature();
  /* Prints it out on the console also, to view */
  Serial.print("Temperature: ");
  Serial.print(tempReading);
  Serial.println();

  /* Logic handling based on deviation in temperature and light readings */
  /* GREEN LED is lit when the light is at 0%, and temperature is less than -12 degrees C */
  /* BLUE LED only lights up when the temperature is lower than the accepted normal zone, 
  and RED LED lights up when the temperature is higher than what is the accepted zone */
  if (lightReading == 0) {
    if (tempReading < -12) {
      digitalWrite(GREEN, HIGH);
      digitalWrite(RED, LOW);
    } else {
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);
    }
  }

  /* GREEN LED is lit when the light is between 1 - 20%, and temperature is between -12 - 0 degrees C */
  /* BLUE LED only lights up when the temperature is lower than the accepted normal zone, 
  and RED LED lights up when the temperature is higher than what is the accepted zone */
  if (lightReading > 0 && lightReading <= 20) {
    if (tempReading < -12) {
      digitalWrite(BLUE, HIGH);
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, LOW);
    } else if (tempReading > 0) {
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);
      digitalWrite(BLUE, LOW);
    } else {
      digitalWrite(GREEN, HIGH);
      digitalWrite(RED, LOW);
      digitalWrite(BLUE, LOW);
    }
  }
 
  /* GREEN LED is lit when the light is between 21 - 60%, and temperature is between 0 - 20 degrees C */
  /* BLUE LED only lights up when the temperature is lower than the accepted normal zone, 
  and RED LED lights up when the temperature is higher than what is the accepted zone */
  if (lightReading > 20 && lightReading <= 60) {
    if (tempReading < 0) {
      digitalWrite(BLUE, HIGH);
      digitalWrite(GREEN, LOW);
      digitalWrite(RED, LOW);
    } else if (tempReading > 20) {
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);
      digitalWrite(BLUE, LOW);
    } else {
      digitalWrite(GREEN, HIGH);
      digitalWrite(RED, LOW);
      digitalWrite(BLUE, LOW);
    }
  }

  /* GREEN LED is lit when the light is between 61 - 100%, and temperature is greater than 20 deg. C */
  /* BLUE LED only lights up when the temperature is lower than the accepted normal zone, 
  and RED LED lights up when the temperature is higher than what is the accepted zone */
  if (lightReading > 60 && lightReading <= 100) {
    if (tempReading < 21) {
      digitalWrite(BLUE, HIGH);
      digitalWrite(GREEN, LOW);
      digitalWrite(RED, LOW);
    } else {
      digitalWrite(GREEN, HIGH);
      digitalWrite(BLUE, LOW);
      digitalWrite(RED, LOW);
    }
  }

  //Add a small delay for how frequently the program measures the temp + light intensity values (defined earlier as 1000ms)
  delay(interval);
}
