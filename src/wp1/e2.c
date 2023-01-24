// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// Work package 1 
// Exercise 2 
// Submission code: XXXXXXX (provided by your TA-s)
#include <stdio.h> // used for standard output and input 
#include <stdlib.h> // used to convert char to number
#include <string.h> // used to call function strlen()
#include <ctype.h> // used to call functions such as islower() and isupper()

int main(int argc, char const *argv[]) // main function, where argc stands for amount of arguments that is entered, and argv[] stands for what arguments are entered.
{
    int i; // is a counter used for the for loop, that loops over characters in inputed word by the user.
    int shiftBy; // is used to contain a number that user enters in argument of main function, and the characters in an inputed string are shfted by this amount of positions. 
    char arr[10]; // used to hold a string that is passed as an input from user.
    int result; // used to hold the sum of ASCII position of index in a word and by how much the character should be shifted. 

    shiftBy = atoi(argv[1]); // the argument that user passes needs to be converted to a number, because by default argv[1] is a char type.


    while (!feof(stdin)) { // while loop is running while feof(stdin) is false. Feof() is a function that looks for end of file indicator. 

        printf("\nEnter a word to encrypt: "); // this sentence prompts the user to enter a word to be encrypted.
        scanf("%s", &arr); // this scanner takes in the word that the user has entered, and stores it in arr variable.

        for (i = 0; i < strlen(arr); i++) { // the for loop loops through the word that was entered by a user, until the last index in the word. 

            result = arr[i] + shiftBy; //the result now holds the ASCII number of character plus how many places it should be shifted by. 

            if(islower(arr[i])){ // checks if the character at which the for loop is currently at is a lower-case letter. 

                if(result > 122) { // if the result number is higher than 122, which is lower-case z in ASCII table
                    result = result - 26; // then subtract 26 from the result, which would mean that the loop stays inside the alphabet of lowercase letters in ASCII table. 

                } // end of if block
            } // end of if block
 
            if(isupper(arr[i])){ // checks if the character at which the for loop is currently at is an upper-case letter.

                if(result > 90) {  // if the result number is higher than 90, which is an upper-case Z in ASCII table
                    result = result - 26; // then subtract 26 from the result, which would mean that the loop stays inside the alphabet of uppercase letters in ASCII table.
                } // end of if block
            } // end of if block

            printf("%c", result); // print every enrypted character in a row. 

        } // end of an if block

    } // end of while loop


    return 0; // return success
}
