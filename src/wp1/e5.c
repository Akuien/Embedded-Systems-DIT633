// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// Work package 1 
// Exercise 5 
// Submission code: VV96BO8 (provided by your TA-s)

#include <stdio.h> // has functions for standard input and output.
#include <stdlib.h> // used for implementing random number generator.
#include <time.h> // used for generating random numbers on each compilation of the program.
#include <stdbool.h> // used for implementing the boolean variable. 
 
#define MAX 100 // Defines the maximum number of the values in the table 
#define MAXNUMBER 20 // Defines the maximum value of random numbers 
 
 
// ------ Function declarations   ----------  
 
// This function generates a set of random numbers 
// and fills the table *tab with these numbers 
void create_random(int *tab) { // the function takes tab array as an argument.
    int i; // declaring a variable "i", which is the counter for the for loop below.
    srand(time(0)); // generator of random numbers.
    for (i = 0; i < MAX; i++) { // the for loop loops with numbers 0 through 100.
        tab[i] = rand() % MAXNUMBER; // for every index until 100, the rand() function generates a random number that can be 20 as a max value. 
    } // end for loop.
};  // end function

 
// This function takes the *tab of random numbers 
// and creates a table with the frequency counts for these numbers 
void count_frequency(int *tab, int *freq ) { // the function takes a tab array of type int, and a frequency array of type int. 

    int i; // the declaration of counter variable. 
    
    for (i = 0; i < MAX; i++) {  // the for loop loops until it reaches a 100
        freq[tab[i]]++; // this counts all the duplicate indecies and adds that count to the frequency array.
        
    } // end of for loop.

}; // end of function. 
 
// This function takes the frequency count table 
// and draws a histogram of the values in that frequency table 
void draw_histogram(int *freq) { // the function takes frequency array as an argument. 

    int i, j; // the counters i and j are declared, i for the outer loop 
    bool isFrequencyZero; // the bool variable takes true or false, if it is true, then it indicates that it found a unique number in frequency array.

    for (i = 0; i < MAXNUMBER; i++) // the for loop loops until it reaches 20 index numbers.
    {
        // ----------------------------------------------------------------------------------------------------------------------

        if (freq[i] == 0) // if if current position of a number in freq[] array is zero, then that would mean that the number is not duplicated.
        {
            continue; // then skip over that index and dont print it.
            isFrequencyZero = true; // frequency is then 0. 
        }
        else
        {
            isFrequencyZero = false; // if the number is duplicated then isFrequencyZero set to false.
        }

        // ----------------------------------------------------------------------------------------------------------------------

        if (i < 10) // if the numbers printed on the left column of the histogram are less than 10.
        {
            printf("%d    ", i); // then print a bigger space between numbers and x's. This is due to the fact that numbers under 10 have one digits, therefore require more space.
        }
        else
        {
            printf("%d   ", i); // if the numbers are more than 9, then add a lesser space. 
        }

        // -----------------------------------------------------------------------------------------------------------------------

        for (j = 0; j < freq[i]; j++) // the inner loop that loops through the frequeny numbers at each index of the freq[] array. 
        {
            if (!isFrequencyZero) // if there is frequency greater than 0.
            {
                printf("%c", 'x'); // then print out x's.
            }
        }

        printf("\n"); // the divider between the columns of numbers and x's.
    }
};  
 
// ------ Function definitions   ---------- 
 
 
// ------ Main   -------------------------- 
 
// The main entry point for the program 
//  
// If you choose to go for the optional part 
// Please modify it accordingly

int main(void) // the main function takes void as an argument.
{
    int table[MAX]; // the table array with the size of max 100 positions is declared.
    int frequency[MAXNUMBER] = {0}; // the frequency array with the size of max 20 positions is declared and initialized with a 0.

    create_random(table); // the function takes the table variable as an argument, and calculates and adds random numbers to that array.
    count_frequency(table, frequency); // the function takes table and frequency array, and adds the frequency count to frequency array for each table value.
    draw_histogram(frequency); // the function draws the histogram with indecies on the left side and frequency x's on the right column. 

    return 0; // return succesffuly. 
}
