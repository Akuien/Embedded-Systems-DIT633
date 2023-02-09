// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// Work package 3 
// Exercise 4 
// Submission code: 2D8UPPE (provided by your TA-s) 

#include <Keypad.h> // adding the Keypad value in order to perform keypad functions

// C++ code

const byte row = 4; // define row size of 4
const byte column = 4; // define column size of 4

byte row_pins[row] = {11, 10, 9, 8}; // define pins for rows of keypad
byte column_pins[column] = {7, 6, 5, 4}; // define pins for columns of keypad

char keys[row][column] = { // create a matrix of keypad characters, where rows and columns are size of 4
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7','8', '9', 'C'}, 
  {'*', '0', '#', 'D'}
};

Keypad keypad = Keypad(makeKeymap(keys), row_pins, column_pins, row, column); // create an instance of a keypad library, map the keys out of the keys matrix, set row pins and column pins, and set size of columns and rows to 4 each.

void setup()
{
  Serial.begin(9600); // start the serial
  Serial.println("Keypad program"); // print out this statement in the beginning of the program.
  
}

void loop()
{
  char key_value = keypad.getKey(); // store the value of an input from the keypad in a char value of key_value

  if(key_value) { // if a key has been pressed
    Serial.println(key_value); // print out the key that was pressed
  } 
}






