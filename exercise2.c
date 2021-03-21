#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void algorithm(int input, char *output) {
    if (input % 3 == 0 && input % 5 == 0) {
        sprintf(output, "MustangBronco");
    }
    else if (input % 3 == 0) {
        sprintf(output, "Mustang");
    }
    else if (input % 5 == 0) {
        sprintf(output, "Bronco");
    }
    else {
        sprintf(output, "%d", input);
    }
}

int main(int argc, char **argv) {
    int input;
    if (argc < 2) { // If input is not given in command line, prompt user for input
        printf("Please enter integer: ");
        if (!scanf("%d", &input)) {
            fprintf(stderr, "User input is invalid.\n");
            exit(1);
        }
    }
    else {  // Otherwise get input from command line: ./EX2 3 or ./EX2 test
        if (!strcmp("test", argv[1])) { // automated testing program
            char test1[14];
            char test2[14];
            char test3[14];
            char test4[14];
            char test5[14];
            char test6[14];

            algorithm(333, test1);
            algorithm(-55, test2);
            algorithm(30, test3);
            algorithm(-45, test4);
            algorithm(0, test5);
            algorithm(7, test6);
            
            assert(!strcmp(test1, "Mustang"));
            assert(!strcmp(test2, "Bronco"));
            assert(!strcmp(test3, "MustangBronco"));
            assert(!strcmp(test4, "MustangBronco"));
            assert(!strcmp(test5, "MustangBronco"));
            assert(!strcmp(test6, "7"));
            
            printf("Verification program completed.\n");
            return 0;
        }
        
        if (!isdigit(argv[1][0])){
            fprintf(stderr, "Command line input is invalid.\n");
            exit(1);
        }
        input = atoi(argv[1]);
    }
    char output[14];

    algorithm(input, output);

    printf("%s\n", output);
    
    return 0; 
}