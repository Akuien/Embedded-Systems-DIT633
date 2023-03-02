// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// Work package 6 
// Exercise 3
// Submission code: XXXXXX (provided by your TA-s) 

// C++ code

/* Importing standard C libraries */
#include <stdio.h>
#include <time.h>
#include <string.h>

/* Including libraries for configuring the components Neopixel 24 Ring, and the Keypad by Adafruit */
#include <Adafruit_NeoPixel.h>
#include <Adafruit_Keypad.h>
#include <Adafruit_Keypad_Ringbuffer.h>

#define LED_PIN 3 // set the NeoPixel ring to pin number 8
#define LIGHTS 24 // set the amount of lights in NeoPixel to 12
#define COMBINATIONS 7 // number of combinations that are accepted by the stargate
#define LENGTH 8 // length of one combination (consisting of 8 digits)

const byte row = 4; // define row size of 4
const byte column = 4; // define column size of 4

int codes[] = {74, 128, 255};
byte row_pins[row] = {11, 10, 9, 8}; // define pins for rows of keypad
byte column_pins[column] = {7, 6, 5, 4}; // define pins for columns of keypad

/* Some had to be mapped differently due to constraints in the physical module, but link to the same key as shown in the physical key buttons */
char keys[row][column] = { // create a matrix of keypad characters, where rows and columns are size of 4
  {'1', '3', '2', 'A'}, // first row - on physical board: '1', '2', '3', 'A'
  {'7', '9', '8', 'C'}, // second row - on physical board: '4', '5', '6', 'B'
  {'*', '#', '0', 'D'}, // third row - on physical board: '7', '8', '9', 'C'
  {'4', '6', '5', 'B'} // fourth row - on physical board: '*', '0', '#', 'D'
};

/* Set of accepted addresses that the Stargate  */
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
Adafruit_Keypad keypad = Adafruit_Keypad(makeKeymap(keys), row_pins, column_pins, row, column); // initializing the keypad with the layout described above in keys[][]
/* It also takes in 4 pins each responsible for the rows (11, 10, 9, 8) and the columns (7, 6, 5, 4) */

/* ---------- Setup function -------- */
void setup()
{
  /* Start the serial console */
  Serial.begin(9600);
  keypad.begin(); // Start the keypad
  srand(time(0)); // The seed for the rand() method to generate a random value upon every execution
  strip.begin(); // start the NeoPixel ring
  strip.show(); // display the colors on the ring
}

/* -------- Function for the 'loading animation' shown in the  -------- */
void fillColors(int amount) { // funtion that takes in int amount as a parameter, in order to loop until a certain amount
  for(int i = amount; i < 24; i++) { // looping until a certain amount
    strip.setPixelColor(i, 10, codes[rand() % 3], codes[rand() % 3]); // set a turqoise color on every LED light in NeoPixel until a certain reaching the amount specified
    strip.show(); // display the colors
    delay(40); // added a few small delays to regulate the speed of the loading animation    
  }
  
  for(int i = amount ; i < 24; i++) { // looping backwards in the ring, in order to fill the rest of LEDs
      if (strip.getPixelColor(i) == 0) {
        strip.setPixelColor(i, 10, codes[rand() % 3], codes[rand() % 3]); // set the color of LED to white
        strip.show(); // display the colors
        delay(20);
        strip.clear(); // reset the display again, as a precaution, for the loading animation to repeat some number of times
      }
  }
}

/* storing the entered input by the user via the keypad */
String entered = "";

/* -------- Looping function in Arduino -------- */
void loop()
{
  /* Starting the keypad */
  keypad.tick();
  /* Initialising a counter for going through every digit entered in the combination, for 'locking in' animations one-by-one */
  int k = 0;

  /* Conduct the set of instructions when the keypad is on and available */
  if(keypad.available()) {
    /* Storing a received event (in the form of a key-press) in a keypadEvent variable e */
    keypadEvent e = keypad.read();
    delay(150);
    char buffer[8];
    /* The following nested-ifs were done to simulate the key-pressing behaviour, 
    as it eliminates conflicts of running operations during a key-press, or when running it when a key is not pressed. */
    if(!e.bit.EVENT == KEY_JUST_RELEASED) {
      if(e.bit.EVENT == KEY_JUST_PRESSED) {
        /* After a press event, store in an input variable which key was pressed. */
        char input = e.bit.KEY;
        /* On every pressed key, increment it in the string that stores the user's inputted combination */
        entered += input;
        /* Show on the console so that the user also knows which key was pressed. */
        Serial.print(input);
        /* Run the processing when the length of the entered combination is 8 */
        if (entered.length() == 8) {
          /* Prints on the screen again, the full combination that the user has entered. */
          Serial.println("\nEntered: ");
          Serial.print(entered);
          fillColors(23); // Begin with one loading animation (each of such function calls is a loading animation of one cycle)
          Serial.println();
          Serial.println();
          
          /* A checker for when the right combination is found, that matches among the accepted list of combinations */
          bool found = false;
          
          /* Loop through the combinations to check */
          for (int i=0; i<COMBINATIONS; i++) {              
            /* If the entered matches a combination out of the accepted ones.. */
            if (entered == addresses[i]) {
              /* Show the loading animation for 'locking in' 8 pairs of LEDs around the Neopixel, as the length of the entered value. */
              while (k < entered.length()) {
                strip.setBrightness(10);
                /*
                  Discovered pattern: for every digit in 8 correctly entered ones, it lights up the (index * 3) and ((index * 3)+1)th pixel
                  to show a locking in pattern while having a gap of one LED in between each. The first param in setPixelColor() is the index of
                  the pixel to light, then the following ones are R, G and B code based on the color/hue to be shown. Hence, (255, 0, 0) corresponds to
                  red.

                  Examples: 0th index: lights 0th and 1st pixel, 1st index: lights 3rd and 4th pixel ... until 7th index: lights 21st and 22nd pixel
                */
                strip.setPixelColor(k*3, 255, 0, 0);
                strip.setPixelColor((k*3)+1, 255, 0, 0);
                /* Show the LED strip */
                strip.show();
                /* A delay before the loading animation is executed */
                delay(500);
                /* Loading animation function: to show the dialing */
                fillColors(((k*3)+1) + 1); // starts from the last LOCKED-IN marked LED, to show dialing from that digit onwards ...
                /* Increment k to go to the next digit */
                k++;

                /* Process overall: dialing animation, lock 1 pair of LEDs in Red hue, dialing animation, lock another pair ... until 8 locked pairs shown on the dial */
              }

              /* ---- Success message: upon the series of 'locking' the digits, showing that they are being processed, the combination was correct, 
              so these set each LED pixel to GREEN (RGB(0, 255, 0)) for 2 seconds to show that the entered combination is accepted. ---- */
              for (int i=0; i<=LIGHTS; i++) {
                strip.show();
                strip.setPixelColor(i, strip.Color(0, 200, 0));
              }
              /* Add a pause of 2000 ms (2 sec) */
              delay(2000);
              /* Set found to true */
              found = true;   
            }                
          }
          /* A set of instructions that are run when the combination was not found among the accepted ones; 
              - Only loops 7 times instead (allowed length of combination (8) - 1) to show that it only locks 7 digits, but on the 8th it gives an error light pattern (shown later)
          */
          if (found == false) {
            while (k < entered.length()-1) {
              strip.setBrightness(10);
              /* Same process repeated as the previous, where the combination would be correct. */
              strip.setPixelColor(k*3, 255, 0, 0);
              strip.setPixelColor((k*3)+1, 255, 0, 0);
              strip.show();
              /* Add a delay of around half a second to regulate the loading animation speed */
              delay(500);
              fillColors(((k*3)+1) + 1);
              k++;
            }
            /* Sets all of the LED pixels to RED, showing after 7 digits were locked in, and the "8th failed", and does not match an accepted combination. */
            for (int i=0; i<=LIGHTS; i++) {
              strip.show();
              strip.setPixelColor(i, strip.Color(200, 0, 0));
            }
            delay(2000); 
          }  

          /* Reset the value of entered, to enable another entry to be put in by the user */
          entered = "";
          delay(1000);

          // Clearing the LED pixels to empty, resetting them to initial state, waiting for another entry from the user
          for (int i=0; i<=LIGHTS; i++) {
            strip.show();
            strip.setPixelColor(i, strip.Color(0, 0, 0));
          }       
        }      
      }
    }
  }
}
