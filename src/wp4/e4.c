// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// Work package 4
// Exercise 4 
// Submission code: XXXXXX (provided by your TA-s) 

#include <stdio.h>
/* A pre-defined MAX variable that is the length of the array */
#define MAX 10

// Task (a)
/** The method searches for a number that is passed in, in an array tab[] of size 'size'.*/
int search_number(int number, int tab[], int size) 
{
    for (int i = 0; i < size; i++) {
        /* Looping through the contents of the array parameter, and if the value at some position i equals 
           the number to be searched for, the function returns the index where it is first occurring. */
        if (tab[i] == number) {
            return i;
        }
    }
    /* If after going through the array, if 'number' was not present at any index, 
       then the function finishes by returning -1. */
    return -1;
}

// Task (b)
/* This methods sorts a provided array in ascending order using bubble sort. The parameters were number (presumably the size of the array passed in),
   as well as the array that is to be sorted. */
void sort (int number, int tab[]) 
{
    int temp; //a temporary variable that is part of the swapping operation, when the first value is greater than the second in a "bubble"
    /* Number of iterations that the array is traversed */
    for (int i = 0; i < number; i++) {
        /* Number of movements in one iteration, reading an element at index j and its next succeeding to compare. */
        for (int j = 0; j < (number-1); j++) {
            temp = tab[j]; //sets the temp value to the left-hand side value
            /* If the right-hand side value is less, then it should be swapped with the left-hand side value, which is done here to sort in ascending order. */
            if (tab[j+1] < tab[j]) {
                tab[j] = tab[j+1];
                /* Set the new right-hand side index's value to the temp variable's stored value, which used to be the left number's value in the comparison. */
                tab[j+1] = temp;
            }        
        }
    }
}

/* Main function of the array, that is to test the sorting+searching algorithms on a dummy array of 10 values. */
int main(int argc, char const *argv[])
{
    int test[MAX] = {1,2,34,5,67,3,23,12,13,10};

    /* Prints the initial array, which is unsorted. */
    printf("\nInitial Array: \n--------\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", test[i]);
    }

    /* A call to sort the array, and next, prints the same array, but sorted using bubble sort. */
    sort(MAX, test);
    printf("\n\nSorted:");
    printf("\n--------\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", test[i]);
    }

    /* Second test: a call to the function for searching for a desired number in the sorted array. 
    A dummy value passed here is 5, that is searched for. */
    printf("\n\nSearching for '5' in test[] : index --> %d\n", search_number(5, test, MAX));
    printf("\n");

    /* Finish the main() by returning 0 */
    return 0;
}