#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *bin2str(char *binStr) {
        int len;
        int i = 0; // input cursor
        int j = 0; // binary cursor used to allow spaces in the input
        static char str[256]; // keep it simple and limit the length

        len = strlen(binStr); // avoid recounting every time

        if (len > 256 * 8 - 1) { // impose the limit
                fprintf(stderr, "Error!  Input string too long\n");
                exit(2);
        }

        for (i = 0; i < len; i ++) {
                switch(binStr[i]) {
                        case ' ':
                                continue;
                                break;

                        case '0':
                        case '1':
                                break;  // valid :)

                        default:
                                fprintf(stderr, "Encountered an invalid binary number ('%c') at offset %d!\nAborting\n", binStr[i], i);
                                exit(3);
                }


                if (j % 8 == 0) {
                        str[j / 8] = 0; // initialize char
                }

                if (binStr[i] == '1') {
                        str[j / 8] |= 1 << (7 - (j % 8));
                }

                j ++;
        }

        str[i / 8] = '\0'; // null terminate string

        return str;
}


int main(int argc, char *argv[]) {
        if (argc != 2) {
                fprintf(stderr, "Usage:\t%s binary string\n", argv[0]);
                exit(1);
        }

        printf("Conversion output: \n%s\n", bin2str(argv[1]));

        return 0;
}
