#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    unsigned char byte = 0;

    if (argc != 2 || strlen(argv[1]) != 2) {
        printf("Error: Please enter 1 argument only, that is strictly a 2-digit hexadecimal value.\n");
        return 1;
    }

    if ((!((argv[1])[0] >= 48 && (argv[1])[0] <= 57) && !((argv[1])[0] >= 65 && (argv[1])[0] <= 70)) 
    || (!((argv[1])[1] >= 48 && (argv[1])[1] <= 57) && !((argv[1])[1] >= 65 && (argv[1])[1] <= 70))) {
        printf("Error: Not a valid hexadecimal value. Please enter either a digit (0-9) or an UPPERCASE alphabet between A-F.\n");
        return 1;
    } else {
        for (int i=48; i<=57; i++) {
            if (argv[1][0] == i) {
                char i_char = i;
                byte += atoi(&i_char) << 4;
            }
            if (argv[1][1] == i) {
                char i_char = i;
                byte += atoi(&i_char);
            }
        }

        for (int i=65; i<=70; i++) {
            if (argv[1][0] == i) {
                byte += (i-55) << 4;
            }
            if (argv[1][1] == i) {
                byte += (i-55);
            }
        }
    }

    byte < 10 ? printf("0%d\n", byte) : printf("%d\n", byte);
    return 0;
}