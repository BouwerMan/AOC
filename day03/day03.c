//https://adventofcode.com/2023/day/3
#define _GNU_SOURCE
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 15
#define FILE_LENGTH 10

char symbols[] = {'*', '=', '-', '$', '@', '%', '#', '+', '/'};

int getNum(char *arr[], int i, int j) {

}

// Checks for adjacent digits
bool check(char *arr[], int i, int j) {
    // int sum = 0;
    // up and down include diagonal
    // bool up = isdigit(arr[i-1][j]) || isdigit(arr[i-1][j-1]) || isdigit(arr[i-1][j+1]);
    // bool down = isdigit(arr[i+1][j]) || isdigit(arr[i+1][j-1]) || isdigit(arr[i+1][j+1]);
    // bool left = isdigit(arr[i+1][j]);
    // bool right = isdigit(arr[i+1][j]);

    // if (!(up || down || left || right)) { return 0; }

    // Iterates over each row
    for (int k = -1; k < 2; k++) {
        // safety check
        if (i == 0 || i == FILE_LENGTH - 1) { continue; }
        // Iterates over each column
        for (int l = -1; l < 2; l++) {
            // safety check again
            if (j == 0 || j == strlen(arr[i])) { continue; }
            bool sym = (arr[i+k][j+l] != '.') && !isdigit(arr[i+k][j+l]);
            if (sym) {
                printf("char: %c\n", arr[i+k][j+l]);
                return sym;
            }
        }
    }
    
    return false;
}

int solve(char *arr[]) {
    int sum = 0;
    for (size_t i = 0; i < FILE_LENGTH; i++) {
        for (size_t j = 0; j < strlen(arr[i]); j++) {
            if (isdigit(arr[i][j])) {
                bool test = check(arr, i, j);
                printf("Test: %d\n", test);
            }
            // bool sym = (arr[i][j] != '.') && !(isdigit(arr[i][j])) && (arr[i][j] != '\n');
            // if (!sym) { continue; }
            // (void)check(arr, i, j);
        }
    }
    
    return sum;
}

int main(void) {
    FILE *fp;
    size_t len = 0;
    ssize_t read;

    char *lines[FILE_LENGTH];
    char *line = malloc(MAX_LINE_LENGTH);


    fp = fopen("./sample.txt", "r");
    if (fp == NULL)
        return EXIT_FAILURE;

    size_t i = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Line: %s", line);
        lines[i] = line;
        line = malloc(MAX_LINE_LENGTH);
        i++;
    }
    printf("Solve: %d\n", solve(lines));

    free(line);
    fclose(fp);
    printf("\n");

    return EXIT_SUCCESS;
}