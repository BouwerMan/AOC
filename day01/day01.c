//https://adventofcode.com/2023/day/1
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char nums[10][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const int lenNums = 10; //sizeof(nums) / sizeof(nums[0]);

int getDigit(char *line, int i) {
    char * pch;
    
    if (isdigit(line[i])) {
        return line[i] - '0';
    }
    char *subline = line + i;
    printf("substring: %s\n", subline);

    for (size_t j = 0; j < lenNums; j++) {
        printf("Testing: %s\n", nums[j]);
        pch = strstr(subline, nums[j]);
        //printf("strlen of %s: %zu\n", nums[j], strlen(nums[j]));
        //if (pch) {printf("strlen pch: %zu\n", strlen(pch));}


        if (pch) {
            size_t l = strlen(nums[j]);
            char test[6] = {};
            strncpy(test, subline, l);
            test[l + 1] = '\0';
            printf("%d\n", strcmp(test, nums[j]));
            printf("Sizeof %d\n", l);
            printf("test=%s\n", test);
            if (strcmp(test, nums[j]) == 0) {
                printf("test: %s\n", test);
                return j;
            }

            // printf("Found: %s At: %s\n", nums[j], pch);
        }
    }
    return -1;
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
        int d1 = -1, d2 = -1;
        printf("Retrieved line of length %zu:\n", read);
        printf("%s\n", line);
        for (size_t i = 0; i < read; i++) {
            int d = getDigit(line, i);
            // skip invalid
			if (d == -1) { continue; };

			if (d1 == -1) {
				d1 = d;
			} else {
				d2 = d;
			}
            
        }

        if (d2 == -1) { d2 = d1; };
        printf("First: %d, Last: %d\n", d1, d2);


        total += d1*10 + d2;
        printf("Running total: %d\n", total);
        // for (int i = 0; i < read; i++) {
        //     ch = line[i];
        //     if (ch >= 48 && ch <=57) {
        //        left = ch - '0';
        //        break;
        //     }
        //     test[i] = ch;
        //     s = sizeof(test) / sizeof(test[0]);
        // }
        // for (int i = read; i >= 0; i--) {
        //     ch = line[i];
        //     if (ch >= 48 && ch <=57) {
        //        right = ch - '0';
        //        break;
        //     }
        // }
        // printf("Left: %d, Right: %d\n", left, right);
        // total += (left * 10) + right;
        // printf("%d\n", total);
    }

    fclose(fp);
    if (line)
        free(line);

    printf("\nTotal: %d\n", total);
    exit(EXIT_SUCCESS);
}
