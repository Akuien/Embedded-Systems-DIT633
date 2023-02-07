// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// Work package 3 
// Exercise 6 
// Submission code: XXXXXX (provided by your TA-s) 

#include <stdio.h>
#include <string.h>

/* 
   Declaring a copystring() custom function 
   that copies contents from first string 'from' to second string 'to' provided as params 
*/
void copystring(char from[], char to[]);

int main(int argc, char const *argv[])
{
    /* Declaring a input char[] where the user's entered input is assigned to.*/
    char input[20];
    /* 
       Asking in the console for the user to input a string of max 20 characters
       This program also supports passing the string input as a .txt file when run like:
       
       -- ./Exerc_2_1 < "path/to/file" --
    */
    printf("\nEnter a string (maximum 20 characters): ");
    scanf("%s", input);
    /* Prints back the received input as confirmation, for cases like eg. when a txt file is
       provided, to see again what was passed in as the input. */
    printf("\nReceived string: -- %s --\n\n", input);

    /* Exits from the program by returning 1, if the string length of the provided input is more than 20 characters. */
    if(strlen(input) > 20) {
        printf(" -- Please input a string under 20 characters. --\n");
        return 1;
    }

    /* String variable that will store the copy of the input through strcpy(), a library function of string.h */
    char copy[20];
    strcpy(/*to*/ copy, /*from*/ input);
    printf("- Input copied to another string via strcpy(): \t\t%s\n", copy);

    /* A second string variable storing another copy of the same input, from a new-made function copystring(from, to) */
    char secondcopy[20];
    /* 
       Copies the contents of one string to another (the parameters were reformatted, to be (from, to) 
       as such an order seems intuitive, analogous to copying from somewhere, to somewhere) 
    */
    copystring(/* from */ input, /* to */ secondcopy);
    printf("- Input copied via copystring() custom method: \t\t%s\n", secondcopy);

    /* End of function */
    return 0;
}

/* The method body of the copystring() function, that copies contents from one string to another */
void copystring(char from[], char to[]) {
    /* Int variable initialised 'i' as 0, used to iterate through the from[] and to[] strings */
    int i = 0; 
    /**
     * Looping through the from[] string, 
     * and assigning characters in the to[] string at index i, characters of from[] at its index i respectively.
    */
    do {
        to[i] = from[i];
        i++; // incrementing i to go through the succeeding indices
    } while(from[i] != '\0'); // '\0' is the ending character that a string var has, and this is used to know when the while loop should end
}