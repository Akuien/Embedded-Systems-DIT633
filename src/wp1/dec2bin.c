#include<stdio.h>    
#include<stdlib.h>  
#include <string.h>

#include <sys/types.h>
#include <unistd.h>


/*
Step 1: Divide the number by 2 through % (modulus operator) and store the remainder in array
Step 2: Divide the number by 2 through / (division operator)
Step 3: Repeat the step 2 until number is greater than 0
*/
// Convert decimal to binary number


//Main function which takes in an argument
//argc == argument count
//argv == argument value
int main(int argc, char *argv[]) 
{
    //we check if the provided number in the argument is less than zero to avoid negative values
    //if the value provided is less than 0, then we send an error message
    if(atoi(argv[1]) < 0) { 

        printf("Error: Please provide a positive integer/digits"); 

    //we check if the user has enter argument -h seeking help
    //we use strcmp to compare if the argument value is exactly equal to -h so that we can provide the user with the help instructions on how to use the program
    } else if(strcmp(argv[1], "-h") == 0) {
        // this line compares the argument that is provided to the "-h" value, 
        // if it succeds(comparison == 0), then it would execute the code inside the block.

        // we print the instructions for the user to see, what to do
        printf("To run the code, first compile...");

    } else { 
        // if non of the above condition are encountered, we therefore do the conversion

            //we declare a new integer array to store the binary digits during the division process
            int i, new_binary_array[8];

            //converting the string representation of the argument to a long integer so that we can use it during the division
            char* end;
            long provided_number = strtol(argv[1], &end, 10);

           //long int n = (long)(int)argv[1];
           // clear the console
            //system ("cls");  
 
            /*
            //in the below for-loop we:
            Divide the provided_number by 2 through % (modulus operator) and store the remainder in array
            Divide the number by 2 through / (division operator)
            Repeat the step 2 until number is less than 0
            */
            for(i=0 ;provided_number>0 ; i++)    {    
                new_binary_array[i] = provided_number % 2;    
                provided_number  = provided_number/2;    
            } 

/*             int array_len = sizeof(new_binary_array)/sizeof(new_binary_array[0]);

            for(i=0; i< array_len; i++ ) {
                if(array_len < 8) {
                
                }
            } */

            //here we iterate through the new binary number in reverse order 00110000===00001100
            printf("\nBinary of Given Number is=");    
            for(i = i-1; i >= 0; i--)    {    
                printf("%d",new_binary_array[i]);


/*                 //int len = (new_binary_array[1]);
                int len = atoi(new_binary_array[1]);
                

                if (len > 8) {
                    int fd[2];

                    if(pipe(fd) == -1) {
                        printf("An error occurred with opening the pipe\n");
                        return 1;
                    }

                    int id = fork();
                    if(id == 0) {
                        close(fd[0]);
                        int x = new_binary_array[1];
                        write(fd[1], &x, sizeof(int));
                        close(fd[1]);
                    }
                }  */  
            } 
                     
    }
    return 0; // return success.
}