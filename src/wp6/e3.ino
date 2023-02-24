#include <Adafruit_Keypad.h>
#include <Adafruit_Keypad_Ringbuffer.h>

// // (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// // Work package 3 
// // Exercise 3
// // Submission code: 2D8UPPE (provided by your TA-s) 

// // C++ code


#include <stdio.h>
#include <time.h>
#include <Adafruit_NeoPixel.h> // adding a NeoPixel library for the NeoPixel ring
#include <string.h>

#define LED_PIN 3 // set the NeoPixel ring to pin number 8
#define LIGHTS 24 // set the amount of lights in NeoPixel to 12
#define COMBINATIONS 7
#define LENGTH 8

const byte row = 4; // define row size of 4
const byte column = 4; // define column size of 4

int codes[] = {74, 128, 255};
byte row_pins[row] = {11, 10, 9, 8}; // define pins for rows of keypad
byte column_pins[column] = {7, 6, 5, 4}; // define pins for columns of keypad

char keys[row][column] = { // create a matrix of keypad characters, where rows and columns are size of 4
  {'1', '3', '2', 'A'}, // first row
  {'4', '6', '5', 'B'}, // second row
  {'*', '#', '0', 'D'}, // third row
  {'7', '9', '8', 'C'} // fourth row
};

String addresses[COMBINATIONS] = {
  "13654329",
  "A4D21439", 
  "C21A32B9", 
  "98765439", 
  "12345699", 
  "B42A3C39", 
  "DABCACB9"
};

Adafruit_NeoPixel strip(LIGHTS, LED_PIN, NEO_GRB + NEO_KHZ800); // initialize NeoPixel ring as a strip, assign 12 lights to it, pin number 8 and initialize color bytes
Adafruit_Keypad keypad = Adafruit_Keypad(makeKeymap(keys), row_pins, column_pins, row, column);


void setup()
{
  Serial.begin(9600);
  keypad.begin();
  srand(time(0));
  strip.begin(); // start the NeoPixel ring
  strip.show(); // display the colors on the ring
}


void fillColors(int amount) { // funtion that takes in int amount as a parameter, in order to loop until a certain amount
  for(int i = amount; i < 24; i++) { // looping until a certain amount
    strip.setPixelColor(i, 10, codes[rand() % 3], codes[rand() % 3]); // set a turqoise color on every LED light in NeoPixel until a certain reaching the amount specified
    strip.show(); // display the colors
    delay(200);    
  }
  
  for(int i = amount ; i < 24; i++) { // looping backwards in the ring, in order to fill the rest of LEDs
      if (strip.getPixelColor(i) == 0) {
        strip.setPixelColor(i, 10, codes[rand() % 3], codes[rand() % 3]); // set the color of LED to white
        strip.show();
        delay(20);
        strip.clear(); // display the colors
      }
  }
}

String entered = "";

void loop()
{
  keypad.tick();
  if(keypad.available()) {
    keypadEvent e = keypad.read();
    char buffer[8];
    if(!e.bit.EVENT == KEY_JUST_RELEASED) {
        //Serial.print((char)e.bit.KEY);
        if(e.bit.EVENT == KEY_JUST_PRESSED) {
          char input = e.bit.KEY;
          entered += input;
          Serial.print(input);
          if (entered.length() == 8) {
            Serial.println("\nEntered: ");
            Serial.print(entered);
            fillColors(23);
            Serial.println();
            Serial.println();
            int num_correct;
            for (int i=0; i<COMBINATIONS; i++) {              
              if (entered == addresses[i]) {
                for (int j=0; j<entered.length(); j++) {
                  int k=0;
                  while (k < entered.length()) {
                    strip.setPixelColor(k*3, 255, 0, 0);
                    strip.setPixelColor((k*3)+1, 255, 0, 0);
                    strip.show();
                    delay(500);
                    fillColors(((k*3)+1) + 1);
                    k++;
                  }
                }
                num_correct++;
              }
            }
            entered = "";
          }
        }      
    }
  }
}
