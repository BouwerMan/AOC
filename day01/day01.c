//https://adventofcode.com/2023/day/1
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char nums[4][6] = {"zero", "one", "two", "three"};
const int lenNums = sizeof(nums) / sizeof(nums[0]);

int getDigit(char *line, int i) {
    char * pch;
    
    if (isdigit(line[i])) {
        return line[i] - '0';
    }
    char *subline = line + i;
    printf("substring: %s\n", subline);
    for (size_t j = 0; j < lenNums; j++) {
        pch = strstr(subline, nums[j]);
        //printf("strlen of %s: %zu\n", nums[j], strlen(nums[j]));
        //if (pch) {printf("strlen pch: %zu\n", strlen(pch));}


        if (pch) {
            char test[6];
            size_t l = strlen(nums[j]);
            strncpy(test, subline, l);
            // test[l + 1] = '\0';
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
    int total, ele = 0;

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
        printf("First: %d, Last: %d\n", d1, d2);
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