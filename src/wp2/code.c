// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// Work package 2 
// Exercise 1 
// Submission code: 6PQVO9T (provided by your TA-s) 

/* Importing standard libraries for printing, processing arguments & int conversions */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Main function */
int main(int argc, char const *argv[])
{
    /* Declaring an unsigned char of size 8 bits (1 byte) named "byte", and initialising it to 0 */
    unsigned char byte = 0;

    /* First check: if the provided arguments excl. executable call is greater/less than 5,
       corresponding to each of the variables. */
    if (argc != 6) {
        printf("Error: Wrong number of arguments. Please enter 5 arguments.\n");
        /* Error, and exit from the system with returning 1 */
        return 1;
    }

    /* ATTR. 1 - engine_on (1 bit) */

    /* Checking whether the length of the argument is of 1 character, and with that true, matching that character to the ASCII codes of either 0 or 1 */
    if ((strlen(argv[1]) > 1) || ((argv[1])[0] != 48 && (argv[1])[0] != 49)) {
        printf("Invalid first input. Please enter either 0 or 1.\n");
        /* Error, and exit from the system */
        return 1;
    } else { /* That the argument is only one character, and is either 0 or 1 */
        /* Adding to the value of the byte, then moving the bit positions to the left by 7 places, to its designated position in the byte */
        byte += atoi(argv[1]);
        byte <<= 7;
    }

    /* ATTR. 2 - gear_pos (3 bits) */

    /* Checking whether the length of the argument is of 1 character, and with that true, matching that character to the ASCII codes of either 0, 1, 2, 3 or 4 */
    if ((strlen(argv[2]) > 1) || ((argv[2])[0] != 48 /* 0 */ && (argv[2])[0] != 49 /* 1 */ && (argv[2])[0] != 50 /* 2 */ && (argv[2])[0] != 51 /* 3 */ && (argv[2])[0] != 52) /* 4 */) {
        printf("Invalid second input. Please enter between 0-4.\n");
        /* Exits program as an error. */
        return 1;
    } else { /* That the argument is between 0-4 */
        /* 
        Increment the byte value by the integer value (atoi) of the argument transitioned by 4 places. 
        For example, if the passed argument is 3 (00000"011"), it will move that to the left by 4 places (-> 0"011"0000).
        This also has 1 vacant position to its left to accomodate for another 1, for when the passed argument might be 4 (-> 0"100"0000).
        */
        byte += atoi(argv[2]) << 4;
    }

    /* ATTR. 3 - key_pos (2 bits) */

    /* Checking whether the length is 1 character, and comparing to ASCII codes of 0, 1 or 2 */
    if ((strlen(argv[3]) > 1) || ((argv[3])[0] != 48 /* 0 */ && (argv[3])[0] != 49 /* 1 */ && (argv[3])[0] != 50) /* 2 */) {
        printf("Invalid third input. Please enter between 0-2.\n");
        /* Exits program as an error. */
        return 1;
    } else { /* If argument is correctly provided, and is between 0-2 */
        /* 
        Same process as in the previous if-block. 
        Here the argument's binary value is transitioned to the left by 2, as the upcoming attributes will only use 1 bit each. 
        */
        byte += atoi(argv[3]) << 2;
    }

    /* ATTR. 4 - brake1 (1 bit) */

    /* Checking whether the length is 1 character, and comparing ASCII codes of 0, 1 */
    if ((strlen(argv[4]) > 1) || ((argv[4])[0] != 48 && (argv[4])[0] != 49)) {
        printf("Invalid fourth input. Please enter between 0-1.\n");
        /* Exits program as an error. */
        return 1;
    } else { /* If argument is correctly provided, and passes through the checks defined above */
        /* Binary value received from the argument is transitioned 1 to the left, for keeping the last bit for the final attribute "brake2". Then, that resultant value is incremented to "byte". */
        byte += atoi(argv[4]) << 1;
    }

    /* ATTR. 5 - brake2 (1 bit) */

    /* Checking whether the length is 1 character, and comparing ASCII codes of 0, 1 */
    if ((strlen(argv[5]) > 1) || ((argv[5])[0] != 48 && (argv[5])[0] != 49)) {
        /* Exits program due to an error for not matching the requirements. */
        printf("Invalid fifth input. Please enter between 0-1.\n");
        return 1;
    } else {
        /* The final bit can just be incremented to "byte" (2^0th place), with the passed checks that the number provided in the argument is always either a 0 or 1. */
        byte += atoi(argv[5]);
        /* Ways of representation of the byte value after receiving all 5 arguments. */
        /* Here the %X identifier is used to display the hexadecimal equivalent, with letters in uppercase. */
        if (byte > 15) { // if the value of byte is greater than 15 (F), show normally as a two-digit hexadecimal representing the 1st 4, and the last 4 bits respectively.
            printf("0x%X\n", byte);
        } else { // if the value of the byte is under 15 (F), format as "0F" by appending a "0" in the print statement.
            printf("0x0%X\n", byte);
        }
    }

    /* Conclude the program */
    return 0;
}