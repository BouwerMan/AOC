//https://adventofcode.com/2023/day/2
// Part 2
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int maxReds = 12;
int maxGreens = 13;
int maxBlues = 14;

typedef struct {
    int id;
    size_t rounds;
    int red;
    int green;
    int blue;
} game;

int getNum(char *str, int numDigits) {
    int digit, num = 0;
    double pos;
    for (size_t i = 0; i < numDigits; i++) {
        digit = str[i] - '0';
        // printf("digit: %d\n", digit);
        
        pos = pow(10.0, (double)(numDigits - (i + 1)));
        // printf("pos: %f\n", pos);
        num += digit * pos;
    }
    return num;
}

// Gets game id
int getGameID(char *line) {
    char *start;
    char *end;
    int digit, num = 0, numDigits = 0;
    double pos;
    start = strstr(line, "Game");
    end = strchr(line, ':');
    if ((start != NULL) & (end != NULL)) {
        numDigits = end - &start[5];
        // printf("numDigits: %d\n", numDigits);
        char numch[4] = {};
        strncpy(numch, &start[5], numDigits);
        num = getNum(numch, numDigits);
    }    
    return num;
}

// Gets number of rounds
size_t getRounds(char *line) {
    size_t total = 1;
    while (*line) {
        if (*
        line == ';') {total += 1;}
        line++;
    }
    return total;
}

// Gets max number of one color of cubes in a game
int getMaxCubes(char *l, char *color, size_t rounds) {
    char *str;
    char slice[1024] = {0};
    int num, dist, max = 0;
    size_t len;

    // Doing some weird stuff to avoid modifying l
    char tempLine[1024] = {0};
    strcpy(tempLine, l);
    char *line = tempLine;
    
    for (size_t i = 0; i < rounds; i++) {
        // Moves forward round
        if (i > 0) {
            line = strstr(&line[1], "; ");
            if (line == NULL) {return max;}
        }

        str = strstr(line, color);
        if (str == NULL) {return max;}
        dist = str - line;

        strncpy(slice, line, dist);
        slice[strlen(slice + 1)] = '\0';

        char *ptr = strrchr(slice, ' ') + 1;
        if (ptr == NULL) {continue;}
        len = strlen(ptr);
        num = getNum(ptr, (int)len);

        // max()
        if (num > max) {max = num;}

        // Reset slice before next iteration
        memset(slice, 0, 1024);
    }
    return max;
}

int main(void) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    game g;
    game empty;
    char ch;
    int powers, total = 0;

    fp = fopen("./sample.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu:\n", read);
        printf("%s", line);

        printf("\nProcessing:\n");
        g.id = getGameID(line);
        printf("Game ID: %d\n", g.id);
        g.rounds = getRounds(line);
        printf("Number of rounds: %ld\n", g.rounds);
        g.red = getMaxCubes(line, "red", g.rounds);
        printf("Max red cubes found: %d\n", g.red);
        g.green = getMaxCubes(line, "green", g.rounds);
        printf("Max green cubes found: %d\n", g.green);
        g.blue = getMaxCubes(line, "blue", g.rounds);
        printf("Max blue cubes found: %d\n", g.blue);
        printf("\n");

        powers = g.red * g.blue * g.green;
        printf("powers: %d\n", powers);
        total += powers;
        
        g = empty;
    }

    printf("Total: %d\n", total);

    return 0;
}
