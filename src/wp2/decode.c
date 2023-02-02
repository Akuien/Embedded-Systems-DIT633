#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        printf("Error: Please enter 1 argument only.");
        return 1;
    }

    unsigned char byte = 0;

    switch(argv[1][0]) {
        case 49:
            byte += 1 << 4; 
            break;
        case 50:
            byte += 2 << 4; 
            break;
        case 51:
            byte += 3 << 4; 
            break;
        case 52:
            byte += 4 << 4; 
            break;
        case 53:
            byte += 5 << 4; 
            break;
        case 54:
            byte += 6 << 4;
            break;
        case 55:
            byte += 7 << 4;
            break;
        case 56:
            byte += 8 << 4;
            break;
        case 57:
            byte += 9 << 4;
            break;
        case 65:
            byte += 10 << 4;
            break;
        case 66:
            byte += 11 << 4;
            break;
        case 67:
            byte += 12 << 4;
            break;
        case 68:
            byte += 13 << 4;
            break;
        case 69:
            byte += 14 << 4;
            break;
        case 70:
            byte += 15 << 4;
            break;
        default:
            printf("The entered argument is not a valid hexadecimal.\n");
            return 1;
    }

    switch(argv[1][1]) {
        case 49:
            byte += 1; 
            break;
        case 50:
            byte += 2; 
            break;
        case 51:
            byte += 3; 
            break;
        case 52:
            byte += 4; 
            break;
        case 53:
            byte += 5; 
            break;
        case 54:
            byte += 6;
            break;
        case 55:
            byte += 7;
            break;
        case 56:
            byte += 8;
            break;
        case 57:
            byte += 9;
            break;
        case 65:
            byte += 10;
            break;
        case 66:
            byte += 11;
            break;
        case 67:
            byte += 12;
            break;
        case 68:
            byte += 13;
            break;
        case 69:
            byte += 14;
            break;
        case 70:
            byte += 15;
            break;
        default:
            printf("The entered argument is not a valid hexadecimal.\n");
            return 1;
    }

    printf("%d\n", byte);
    return 0;
}
