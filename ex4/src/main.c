// main.c
#include <stdio.h>
#include <stdlib.h>
#include "../inc/function.h"

int main(int argc, char *argv[]) {
    int min, max, count;
    
    if (argc == 4) {
        min = atoi(argv[1]);
        max = atoi(argv[2]);
        count = atoi(argv[3]);
        
        if (!validate_inputs(min, max, count)) {
            return 1;
        }
    } else if (argc == 1) {
        printf("Enter the minimum value: ");
        scanf("%d", &min);
        printf("Enter the maximum value: ");
        scanf("%d", &max);
        printf("Enter the number of unique values to generate: ");
        scanf("%d", &count);
        
        if (!validate_inputs(min, max, count)) {
            return 1;
        }
    } else {
        printf("Usage: %s [min] [max] [count]\n", argv[0]);
        return 1;
    }
    
    generate_random_numbers(min, max, count);
    return 0;
}

