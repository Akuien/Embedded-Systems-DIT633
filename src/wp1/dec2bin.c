#include<stdio.h>    
#include<stdlib.h>  
#include <string.h>

#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>

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

        printf("Error: Please provide a positive integer/digits\n"); 
        return 2;
    //we check if the user has enter argument -h seeking help
    //we use strcmp to compare if the argument value is exactly equal to -h so that we can provide the user with the help instructions on how to use the program
    } else if(strcmp(argv[1], "-h") == 0) {
        // this line compares the argument that is provided to the "-h" value, 
        // if it succeds(comparison == 0), then it would execute the code inside the block.

        // we print the instructions for the user to see, what to do
        printf("To run the code, first compile the code using gcc dec2bin.c -o dec2bin, \nand then run it using \n\n./dec2bin <desired decimal to convert to binary> \n\nPlease enter a valid decimal number as an argument.\n");

    } else { 
        // if non of the above condition are encountered, we therefore do the conversion 
        //during the case when conversion cannot be done, '2' is returned by main() and the process is aborted. This is important to be checked at the start.
        for (int i=0; i<strlen(argv[1]); i++) {
            if (isdigit(argv[1][i]) == 0) {
                printf("Please enter a \"number\".\n");
                return 2;
            }
        }

            //we declare a new integer array to store the binary digits during the division process
            int i;
            int new_binary_array[16] = {0};

            //converting the string representation of the argument to a long integer so that we can use it during the division
            char* end;
            long provided_number = strtol(argv[1], &end, 10);
 
            /*
                //in the below for-loop we:
                Divide the provided_number by 2 through % (modulus operator) and store the remainder in array
                Divide the number by 2 through / (division operator)
                Repeat the step 2 until number is less than 0
            */
            
            int temp = provided_number;

            for (i = 0; temp > 0; i++)    {    
                new_binary_array[i] = temp % 2;    
                temp = temp/2;    
            } 

            //here we iterate through the new binary number in reverse order 00110000===00001100
            if (provided_number >= 256) { //if the provided number is more than 255 (11111111), then print as a 16-bit binary                 
                for(i = 15; i >= 0; i--)    {    
                    printf("%d", new_binary_array[i]); //so print all 16 indexes (15, 14, 13 ... 0, as the binary number is reversed)

                /*          
                int len = (new_binary_array[1]);
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
                }  
                */  
                } 
            } else {       //if the provided number can be 8-bit equivalent in binary, or less than 256 (00000000 - 11111111)
                for(i = 7; i >= 0; i--) {     //prints only 8 indexes out of the total (7, 6, 5 ... 0)
                    printf("%d", new_binary_array[i]); 
                }
            }
            printf("\n");
            return 0; // return success.
    }
}
