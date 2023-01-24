// (C) Anton Golubenko, Aditya Khadkikar, Akuen Akoi Deng - Group: 27 
// Work package 0 
// Exercise 2, 3 
// Submission code: TJCPQ9F (provided by your TA-s) 
#include <stdio.h> // the c preprocessor compiles this line and includes the content in the program.
#include <string.h> // adds the string library that would provide functions connected this library like string comparator.

/*
This is the main function of program, where all the code is executed.
It has arguments holders, the first one is the amount of argumennts passed 
and the second one are the arguments themselves.
*/
int main(int argc, char *argv[]) //argc == argument count, argv == argument values
{
    if(argc < 2 || argc > 2) { 
        // if the arguments provided are more than 2 or less than 2 (program file is included),
        //  then the error message is printed.
        printf("Error: wrong number of arguments. Please enter one argument. \nFor clarification, enter './e2-3 -h'."); // the approapriate error message is printed in terminal.
    } else if(strcmp(argv[1], "-h") == 0) {
        // this line compares the argument that is provided to the "-h" value, 
        // if it succeds(comparison == 0), then it would execute the code inside the block.
        printf("To run the code, first compile, then enter ./e2-3 in the terminal, and enter an argument after it, as e.g, './e2-3 Jerry'. \nAfter the argument is passed, it will print a message stating: 'Hello World - I'm <argument>!'. \nIf more than 1, or no arguments are provided after ./e2-3, then it will throw an error. \nE.g './e2-3 Tom Jerry' will not work."); // the line that is printed after successful comparison. 
    } else { 
        printf("Hello World - I'm %s! \n", argv[1]); // exercise 2 part, takes an argument passed to main and prints the message with the specified argument.             
    }
    return 0; // return success.
}