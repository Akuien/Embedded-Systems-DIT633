// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// Work package 4
// Exercise 3
// Submission code: AW1Y2XM (provided by your TA-s) 
#include <Adafruit_NeoPixel.h> // adding a NeoPixel library for the NeoPixel ring
#define LED_PIN 8 // set the NeoPixel ring to pin number 8
#define LED_PIN_RED 7 // set the red LED bulb to pin number 7
#define BUZZER_PIN 6 // set the Piezo speaker to pin number 6
#define LIGHTS 12 // set the amount of lights in NeoPixel to 12
#define TEMP_PIN A1 // set the temperature pin to A1

Adafruit_NeoPixel strip(LIGHTS, LED_PIN, NEO_GRB + NEO_KHZ800); // initialize NeoPixel ring as a strip, assign 12 lights to it, pin number 8 and initialize color bytes

void setup()
{
  strip.begin(); // start the NeoPixel ring
  strip.show(); // display the colors on the ring
}

void fillColors(int amount) { // funtion that takes in int amount as a parameter, in order to loop until a certain amount

  for(int i = 0; i < amount; i++) { // looping until a certain amount
      strip.setPixelColor(i, 64, 156, 255); // set a turqoise color on every LED light in NeoPixel until a certain reaching the amount specified
      strip.show(); // display the colors
    }
  
   for(int i = 12; i >= amount; i--) { // looping backwards in the ring, in order to fill the rest of LEDs
      strip.setPixelColor(i, 0, 0, 0); // set the color of LED to white
      strip.show(); // display the colors
    }

}

void loop()
{
  int temp = ((analogRead(TEMP_PIN)* 5.0 / 1023.0)-0.5)*100; // converting the recieved data from analog temperature sensor to a number
 
  
  if(temp < 0) { // if temperature is negative 
  
    fillColors(1); // fill the colors on NeoPixel up to one LED
  } else if(temp >= 0 && temp < 10) { // if temperature is higher than or equal to 0 and less than 10
    
    fillColors(3); // fill in 3 LED's
  } else if(temp >= 10 && temp < 20) { // if temperature os equal to or higher than 10 and lower than 20
      
    fillColors(6); // fill in 6 LED's
  } else if(temp >= 20 && temp < 30) { // if temperature is equal to or higher than 20 and is lower than 30
     
    fillColors(9); // fill in 9 LED's
    
  } else if(temp >= 30) { // if temperature is equal to or higher than 30
  
    fillColors(12); // fill in all LED's 
    digitalWrite(LED_PIN_RED, HIGH); // light up the red bulb 
    tone(BUZZER_PIN, 50); // make a sound at 50 Khz
  }

  digitalWrite(LED_PIN_RED, LOW); // bulb stays turned off otherwise
  delay(50); // delay for 0.05 seconds
  noTone(BUZZER_PIN); // make no sound from the speaker
}