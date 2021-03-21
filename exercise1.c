#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

typedef struct coordinate {
    int x;
    int y;
} coordinate;

int distance(coordinate a, coordinate b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main(int argc, char **argv) {
    coordinate a, b;
    if (argc > 1 && !strcmp("test", argv[1])) { // check for verification program: ./EX1 test
        coordinate test1a = {0, 0}, test1b = {0, 0};
        coordinate test2a = {1, 1}, test2b = {5, 10};
        coordinate test3a = {-1, -2}, test3b = {-6, -8};
        coordinate test4a = {3, -4}, test4b = {-7, 13};
        coordinate test5a = {3.5, 5.2}, test5b = {-6.4, 0.578};

        assert(distance(test1a, test1b) == 0);
        assert(distance(test2a, test2b) == 13);
        assert(distance(test3a, test3b) == 11);
        assert(distance(test4a, test4b) == 27);
        assert(distance(test5a, test5b) == 14);
        
        printf("Verification program completed.\n");
        return 0;
    }
    else if (argc < 5) { // If insufficient inputs given in command prompt, prompt user for input
        printf("Please enter x and y of first point, separated by a space: ");
        if (scanf("%d %d", &a.x, &a.y) != 2) {
            fprintf(stderr, "User input is invalid.\n");
            exit(1);
        }
        printf("Please enter x and y of second point, separated by a space: ");
        if (scanf("%d %d", &b.x, &b.y) != 2) {
            fprintf(stderr, "User input is invalid.\n");
            exit(1);
        }
    }
    else { // Otherwise get input from command line: ./EX1 3 5 7 9
        if (!isdigit(argv[1][0]) || !isdigit(argv[2][0]) || !isdigit(argv[3][0]) || !isdigit(argv[4][0])){
            fprintf(stderr, "Command line input is invalid.\n");
            exit(1);
        }
        a.x = atoi(argv[1]);
        a.y = atoi(argv[2]);
        b.x = atoi(argv[3]);
        b.y = atoi(argv[4]);
    }

    printf("Manhattan Distance: %d\n", distance(a, b));

    return 0;
}