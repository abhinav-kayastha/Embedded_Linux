// function.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../inc/function.h"

void generate_random_numbers(int min, int max, int count) {
    int range = max - min + 1;
    int *random_numbers = (int *)malloc(count * sizeof(int));
    if (random_numbers == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        int num;
        bool unique;
        do {
            num = rand() % range + min;
            unique = true;
            for (int j = 0; j < i; j++) {
                if (random_numbers[j] == num) {
                    unique = false;
                    break;
                }
            }
        } while (!unique);
        random_numbers[i] = num;
        printf("%d ", num);
    }
    printf("\n");
    free(random_numbers);
}

bool validate_inputs(int min, int max, int count) {
    if (min > max) {
        printf("Minimum value cannot be greater than maximum value.\n");
        return false;
    }
    if (count > (max - min + 1)) {
        printf("The number of unique values requested exceeds the range of possible unique values.\n");
        return false;
    }
    return true;
}

