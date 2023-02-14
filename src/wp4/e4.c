// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// Work package 4
// Exercise 4 
// Submission code: XXXXXX (provided by your TA-s) 

#include <stdio.h>
#define MAX 10

// (a)
int search_number(int number, int tab[], int size) 
{
    for (int i = 0; i < size; i++) {
        if (tab[i] == number) {
            return i;
        }
    }
    return -1;
}

// (b)
void sort (int number, int tab[]) 
{
    int temp;
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < (number-1); j++) {
            temp = tab[j];
            if (tab[j+1] < tab[j]) {
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }        
        }
    }
}

int main(int argc, char const *argv[])
{
    int test[] = {1,2,34,5,67,3,23,12,13,10};
    printf("\nInitial Array: \n--------\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", test[i]);
    }
    sort(MAX, test);
    printf("\n\nSorted:");
    printf("\n--------\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", test[i]);
    }
    printf("\n\nSearching for '5' in test[] : index --> %d\n", search_number(5, test, MAX));
    printf("\n");
    return 0;
}