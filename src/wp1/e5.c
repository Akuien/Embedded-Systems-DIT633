// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// Work package 1 
// Exercise 5 
// Submission code: XXXXXXX (provided by your TA-s)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
 
#define MAX 100 // Defines the maximum number of the values in the table 
#define MAXNUMBER 20 // Defines the maximum value of random numbers 
 
 
// ------ Function declarations   ----------  
 
// This function generates a set of random numbers 
// and fills the table *tab with these numbers 
void create_random(int *tab) {
    int i;
    srand(time(0));
    for (i = 0; i < MAX; i++) {
        tab[i] = rand() % MAXNUMBER;
    }
};  

 
// This function takes the *tab of random numbers 
// and creates a table with the frequency counts for these numbers 
void count_frequency(int *tab, int *freq ) {

    int i;
    
    for (i = 0; i < MAX; i++) { 
        freq[tab[i]]++;
        
    }

};     
 
// This function takes the frequency count table 
// and draws a histogram of the values in that frequency table 
void draw_histogram(int *freq) {

    int i, j;
    bool isFrequencyZero;

    for (i = 0; i < MAXNUMBER; i++)
    {
        if (freq[i] == 0)
        {
            continue;
            isFrequencyZero = true;
        }
        else
        {
            isFrequencyZero = false;
        }
        if (i < 10)
        {
            printf("%d    ", i);
        }
        else
        {
            printf("%d   ", i);
        }
        for (j = 0; j < freq[i]; j++)
        {
            if (!isFrequencyZero)
            {
                printf("%c", 'x');
            }
        }

        printf("\n");
    }
};  
 
// ------ Function definitions   ---------- 
 
 
// ------ Main   -------------------------- 
 
// The main entry point for the program 
//  
// If you choose to go for the optional part 
// Please modify it accordingly

int main(int argc, char const *argv[])
{
    int table[MAX], n; 
    int frequency[MAXNUMBER] = {0};

    create_random(table);
    count_frequency(table, frequency);
    draw_histogram(frequency);

    return 0;
}
