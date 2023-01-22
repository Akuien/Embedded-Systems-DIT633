// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// Work package 1 
// Exercise 1 
// Submission code: XXXXXXX (provided by your TA-s) 
#include <stdio.h> // has functions for standard input and output


int main(void) { // main function that returns an integer and takes in void as an argument

    int num; // declaring an integer "num"

    do { // do whats in this block first before reaching the while condition.
        printf("\nEnter a number: "); // print out this statement first.
        scanf("%d", &num); // take in the number from keyboard and store it in num variable

        switch(num) { // take num variable in the switch
            case 1: // if number value entered equals 1
                printf("You chose number one\n"); // then print out this statement
                break; // break the condition and start the loop again
            case 2: // if number value entered equals 2
                printf("You chose number two\n"); // then print out this statement
                break; // break the condition and start the loop again
            case 3: // if number value entered equals 3
                printf("You chose number three\n"); // then print out this statement
                break; // break the condition and start the loop again
            case 4: // if number value entered equals 4
                printf("You chose number four\n"); // then print out this statement
                break; // break the condition and start the loop again
            case 5: // if number value entered equals 5
                printf("You chose number five\n"); // then print out this statement
                break; // break the condition and start the loop again
            default: // if no case matches the input
                break; // then break the loop
        }
    } while (num <= 5 && num >= 1); // the loop will kee running while the input from keyboard is in 1-5 range

    return 0; // return success
}