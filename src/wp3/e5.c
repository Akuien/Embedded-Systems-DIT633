// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// Work package 3 
// Exercise 5 
// Submission code: 2D8UPPE (provided by your TA-s) 

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Declaring a variable for the pre-processor of the maximum number of integer elements
 * in the array, that are randomly generated between 1 to 99. As a starting default, it 
 * is set to 50 elements.
*/
#define MAX 50

int main(int argc, char const *argv[])
{
    /* Declaring an array of the size of MAX (defined earlier at the start as 50) */
    int arr[MAX];
    /* Random seed, to generate new random numbers every time main() is run. */
    srand(time(0));

    /* For-loop to iterate through indices 0 until, not including MAX, of arr, and at that index, 
       assign a random value between 1 - 99 (achieved by mod 99, +1 for when the remainder might be 0). */
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % 99 + 1;
    }

    /* Information of the array */
    /* ---------- */

    printf("\nThe value of the address of the array (pointer) is: %p\n", arr); // Address of the first element of the arr, expressed as a hexadecimal value.
    printf("First integer in the array is: %d\n", arr[0]);  // Element in arr at index 0
    printf("Last integer in the array is: %d\n", arr[MAX-1]); // Element in arr at index MAX - 1, as it is of size MAX and indices begin from 0
    printf("The size of an integer (number of bytes) is: %d\n", (int) sizeof(int)); // Size of an int is printed to the console, in bytes (should be 4)
    printf("The size of the whole array in bytes is: %d\n\n", (int) sizeof(arr)); // Size of arr in int, expressed in bytes (should be sizeof(int) * MAX)
    
    int *ptr_to_arr; //declaring a pointer variable that will be used to access the array's contents

    puts("Contents of the array: ");
    /**
     * Loops through the array, and makes ptr_to_arr point to each of the elements. 
     * Then, whatever value it is pointing at, it prints the value, and then moves to the next index, and the pointer var points to the succeeding element.
    */
    for (int i = 0; i < MAX; i++) {
        ptr_to_arr = &arr[i]; //sets the pointer var to the address (&) of where the element at i'th index is stored
        printf("%d ", *ptr_to_arr); //prints the raw value at whatever address the ptr_to_arr is at 
    }

    /**
     * Same as the previous for loop, however the value that is pointed at, is multiplied by 2, and printed on the console.
     * For an element in the array X, this will print 2X for all values inside arr.
    */
    puts("\n\nContents of the array (multiplied by two): ");
    for (int i = 0; i < MAX; i++) {
        ptr_to_arr = &arr[i]; //sets the pointer var to the address (&) of where the element at i'th index is stored
        printf("%d ", (*ptr_to_arr * 2)); //prints the value
    }
    printf("\n");

    /* End of function main() */
    return 0;
}