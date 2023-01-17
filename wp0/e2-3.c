// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// Work package 0 
// Exercise 1 
// Submission code: XXXXXX (provided by your TA-s) 
#include <stdio.h> // the c preprocessor compiles this line and includes the content in the program.
#include <string.h> // adds the string library that would provide functions connected this library like string comparator.


int main(int argc, char *argv[]) // this is the main function of program, where all the code is executed. it has arguments holders, the first one is the amount of argumennts passed and the second one are the arguments themselves.
{
    if(argc < 2 || argc > 2) { // if the arguments provided are more than 2 or less than 2 (program file is included), then the error message is printed.
        printf("Error: wrong number of arguments. Please enter one argument"); // the approapriate error message is printed in terminal.
    } else {
        if(strcmp(argv[1], "-h") == 0) { // this line compares the argument that is provided to the "-h" value, if it succeds(comparison == 0), then it would execute the code inside the block.
            printf("To run the code, enter ./main in the terminal, and enter an argument after it"); // the line that is printed after successful comparison. 
        } else {
            printf("Hello World - I'm %s! \n", argv[1]); // exercise 2 part, takes an argument passed to main and prints the message with the specified argument.
        }
    }
    
    return 0; // return success.
}