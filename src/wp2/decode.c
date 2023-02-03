// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// Work package 2 
// Exercise 4 
// Submission code: 6PQVO9T (provided by your TA-s) 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Main function that is executed */
int main(int argc, char const *argv[])
{
    /* Initialise & Declare an unsigned char (1 byte - 8 bits) */
    unsigned char byte = 0;

    /* If the count of arguments provided after the executable call is 
    greater than / less than 1 (total count is not equal to 2) */
    if (argc != 2) {
        printf("Error: Please enter 1 argument.\n");
        /* Exit the program */
        return 1;
    }

    /* A method to check that the length of the passed argument is two, part of the 
    checking process of verifying if it is a valid 8 bits hexadecimal */
    if (strlen(argv[1]) != 2) {
        printf("Error: Please enter a 2-digit hexadecimal value.\n");
        /* Exit the program */
        return 1;
    }

    /* An elaborate nested if-conditions, split into 2 lines for clarity. The first line looks at the first character of the argument string, and checks whether it matches with the ASCII codes of 0-9 and A-F.*/
    /* The second line looks at the 2nd character of the passed in hexadecimal, and checks along the same constraints. */
    
    /* If either the first char is not between 0-9 and A-F, or the second char is not between 0-9 and A-F, throw an error. */
    if ((!((argv[1])[0] >= 48 && (argv[1])[0] <= 57) && !((argv[1])[0] >= 65 && (argv[1])[0] <= 70)) 
    || (!((argv[1])[1] >= 48 && (argv[1])[1] <= 57) && !((argv[1])[1] >= 65 && (argv[1])[1] <= 70))) {
        printf("Error: Not a valid hexadecimal value. Please enter either a digit (0-9) or an UPPERCASE alphabet between A-F.\n");
        /* Exit the program */
        return 1;
    } else { /* If both characters are either 0-9 or A-F */
        
        /* Handling for when the characters are digits, and incrementing to the unsigned char according to their location in the byte */
        for (int i=48; i<=57; i++) {
            /* Loops through 48-57 (ASCII codes for '0'-'9'), and checks the first character */
            if (argv[1][0] == i) {
                char i_char = i;
                /* If the char matches whatever ASCII code it is at (eg. 50), it is parsed as a char in the above line. Then, in the bottom
                line, that equivalent character is converted to an integer (atoi) to extract its value in int from a char. */
                byte += atoi(&i_char) << 4;
                /* The value is moved 4 places in the byte, as the first char of the hexadecimal represents the left 4 bits. */
            }
            /* Loops through 48-57 (ASCII codes for '0'-'9'), and checks the second character */
            if (argv[1][1] == i) {
                char i_char = i;
                /* Same done here, the value of the char based on its ASCII code is got as int. Then, that is incremented to the byte, and no
                shifting as it represents the right-hand-side 4 bits, hence they can just be incremented directly. */
                byte += atoi(&i_char);
            }
        }

        /* Handling for when the characters are letters, and incrementing to the unsigned char according to their location in the byte */
        for (int i=65; i<=70; i++) {
            /* Loops through 65-70 (ASCII codes for 'A'-'F'), and checks the first character */
            /*
             * 65 ('A') -> 10 (Decimal)
             * 66 ('B') -> 11 (Decimal)
             * 67 ('C') -> 12 (Decimal)
             * ... 70 ('F') -> 15 (Decimal)
             * 
             * Pattern: value_to_incr = ascii_code - 55 
            */
            if (argv[1][0] == i) {
                /* The value to increment, directly achieved as int based on the above pattern, is incremented to the left-hand-side 4 bits of the byte. (Hence moved 4 places left <<) */
                byte += (i-55) << 4;
            }
            /* Loops through 65-70 (ASCII codes for 'A'-'F'), and checks the second character */
            if (argv[1][1] == i) {
                /* The value to increment, directly achieved as int, without shifting as it corresponds to the right-hand-side 4 bits of the byte.*/
                byte += (i-55);
            }
        }
    }

    /* Some testing done here below to test the & logic, 
    to retrieve the right elements of the byte based on their location (working out) */
    
        //   0000 1101
        // & 0000 0111
        // -----------
        //        0111

        /*
             0011 1110
           & 0000 0001
           -----------
             0000 0011
        */

    /* Representation of the information in the byte to the states of the different attributes */
    printf("Name\t\tValue\n");
    printf("-----------------------------\n");
    /* Each of the attributes received, and the indexes retreived from the byte, 
    by moving the byte by certain places and using logical & based on the places in the byte it takes, to get the bits that correspond. */
    
    /* engine_on: 1st bit,  hence just to retreive that bit, the byte structure is moved 7 places. 
    0XXX XXXX -> XXXX XXX1 (X are simply placeholders) */
    printf("engine_on\t%d\n", (byte >> 7));

    /* gear_pos: 2nd, 3rd and 4th bit. To get the bytes in between, the structure is moved 4 places, and & operation is done with the 4th bit from the right to exclude that bit in the achieved value. */
        /* X000 XXXX >> 4 = 0000 X000 
                          & 0000 0111 (7) -> 0000 0000 
    X is removed as regardless of X's value, X & 0 === 0 */
    printf("gear_pos\t%d\n", (byte >> 4) & 7);

    /* key_pos: 5th and 6th bit. */    
    /* Eg. if value was 10 (2) */
        /* XXXX 10XX >> 2 = 00XX XX10 
                          & 0000 0011 (3) -> 0000 0010
    Any values before 11 are removed as X & 0 === 0 */
    printf("key_pos\t\t%d\n", (byte >> 2) & 3);

    /* brake1: 7th bit. */
    /* Eg. if value was 0 (0) */
        /* XXXX XX0X >> 1 =   0XXX XXX0 
                            & 0000 0001 (1) -> 0000 0000
    Any values before 0 are removed as X (regardless of 0 or 1) & 0 === 0 */
    printf("brake1\t\t%d\n", (byte >> 1) & 1);

    /* brake2: 8th bit. */
    /* Eg. if value was 1 (1) */
        /* XXXX XXX1 >> 1 =   0XXX XXX1 
                            & 0000 0001 (1) -> 0000 0001
    Any values before 0 are removed here also, as X (regardless of 0 or 1) & 0 === 0 */
    printf("brake2\t\t%d\n", (byte) & 1);

    /* Close the program by returning 0 */
    return 0;
}