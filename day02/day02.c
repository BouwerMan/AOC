//https://adventofcode.com/2023/day/2
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int id;
    int red;
    int green;
    int blue;
} game;

int getGameID(char * line) {
    char *start;
    char *end;
    char digits[4] = {};
    int numDigits = 0;
    int digit;
    start = strstr(line, "Game");
    end = strchr(line, ':');
    if ((start != NULL) & (end != NULL)) {
        numDigits = &end - &start;
        printf("numDigits: %d\n", numDigits);
        char *num = &start;
        printf("num:%s\n", num);

        for (size_t i = 0; i < numDigits; i++) {
            digit = (num[i] - '0');
            printf("%c\n", num[i]);
            printf("digit:%d\n", digit);
        }

        
        //char t = pch[5];
        //printf("char: %c\n", t);
    }    
}

int main(void) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    char ch;
    int left, right;
    int total = 0;

    fp = fopen("./sample.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu:\n", read);
        printf("%s\n", line);
        getGameID(line);
        // for (size_t i = 0; i < read; i++) {
        // }
    }

    return 0;
}
