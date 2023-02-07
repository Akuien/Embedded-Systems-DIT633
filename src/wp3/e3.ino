// C++ code
//

const byte row = 4; // define row size of 4
const byte column = 4; // define column size of 4

byte row_pins[row] = {11, 10, 9, 8}; // define pins for rows of keypad
byte column_pins[column] = {7, 6, 5, 4}; // define pins for columns of keypad

char keys[row][column] = { // create a matrix of keypad characters, where rows and columns are size of 4
  {'1', '2', '3', 'A'}, // first row
  {'4', '5', '6', 'B'}, // second row
  {'7','8', '9', 'C'}, // third row
  {'*', '0', '#', 'D'} // fourth row
};


void setup()
{
  Serial.begin(9600); // start the serial
  Serial.println("Keypad program"); // print out this statement in the beginning of the program.
  
  for(int i = 0; i < 4; i++) { // loop 4 times
	pinMode(row_pins[i], OUTPUT); // assign row pins as output pins
    pinMode(column_pins[i], INPUT_PULLUP); // assign column pins as input pullup
  }
}

void loop()
{
  keypad(); // run the keypad function
}

void keypad(){
  
  for(int i = 0; i < 4; i++) { // loop 4 times
    digitalWrite(row_pins[i], LOW); // turn off the circuit for row pins
    for(int j = 0; j < 4; j++) { // loop 4 times on internal loop
      if(digitalRead(column_pins[j]) == LOW) { // if a button has been pressed on a particular position from column pin
        Serial.println(keys[i][j]); // then print out a position of the character from the keypad matrix.
        delay(1000); // delay for one second.
      }
    }
    digitalWrite(row_pins[i], HIGH); // turn on the flow of circuit on row pins
  }

}