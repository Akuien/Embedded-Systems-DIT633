
#include <stdio.h> 
#include<stdlib.h>  
#include <string.h>

//convert binary to hexadecimal number



// main function that takes in an argument
int main(int argc, char *argv[]) 
{
    // 
    if(atoi(argv[1]) < 0) { 
        printf("Error: The value provided is invalid.\n"); 
        return 2;
    } else if(strcmp(argv[1], "-h") == 0) {
        // this line compares the argument that is provided to the "-h" value, 
        // if it succeds(comparison == 0), then it would execute the code inside the block.
        printf("To run the code, first compile using \n\n gcc bin2hec.c -o bin2hec\n\nand run using \n\n ./bin2hec <binary number to convert to hexad.>\n\n Make sure to use a valid binary number as an argument. This can also be run in conjunction with executable \"./dec2bin\". This is done with running that file (with a decimal arg), and then appending it with a '| xargs' (pipeline), and then calling \"./bin2hec\" without any arguments. Like this -- \n\n ./dec2bin 255 | xargs ./bin2hec    // this will return FF\n\nThis will pass the output from the first executable directly as an argument to the next executable, and conduct dec-hex conversions in one go.\n");
    
    } else { 
        for (int i=0; i<strlen(argv[1]); i++) {
            if ((argv[1][i] - '0') > 1) {
                printf("There was an error.\n");
                return 2;
            }
            /*detectzero = strspn(argv[1], "0");
            detectone = strspn(argv[1], "1");
            if (detectone == 0 || detectzero == 0) {
                printf("There was an error.\n");
            } else {
                printf("%c", (argv[1])[i]);
            }*/

            /*if (atoi(&(argv[1])[i]) > 1) {
                printf("There was an error.\n");
            }*/
        }

        long int hexadecimalval[2] = {0};
        long int i = 1, remainder;

        //Take a binary number as input and store it in the variable binary_number.
        //converting the string representation of the argument to a long integer so that we can assign it to binary_number variable
        char* end;
        long binary_number = strtol(argv[1], &end, 10);

        //While the value of the binary_number is not equal to 0(zero)
        while (binary_number != 0)
        {
            //Obtain the remainder and quotient of the binary_number by dividing it by 10.
            remainder = binary_number % 10;

            //Multiply the obtained remainder with variable i and increment the variable hexadecimalval with this value.
            hexadecimalval[1] = hexadecimalval[1] + remainder*i;
            //Increment the variable i by 2 and override the variable binaryval with the quotient obtained.
            i = i * 2;
            /*
             Repeat the steps 2-4 until the variable binaryval becomes zero.
             Print the variable hexadecimalval as output
            */
            binary_number = binary_number / 10;
        }
        if (hexadecimalval[1] < 17) {
            for (int i=0; i<=1; i++) {
                printf("%lX", hexadecimalval[i]);
            }
        } else {
            printf("%lX", hexadecimalval[1]);
        }
        printf("\n");
    }
    return 0; // return success.
}
