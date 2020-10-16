/*
 * Sean Fischer
 * 9/28/19
 *
 * Work out the first ten digits of the sum of the following one-hundred
 * 50-digit numbers.
 *
 * (see resources/p13_input.txt)
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define N_DIGITS 10
#define N_NUMBERS 100
#define LEN_NUMBER 50

char **read_input(const char *file_name, int n_lines, int length) {
    FILE *f = fopen(file_name, "r");

    char **input_buffer = malloc(n_lines * sizeof(char *));
    for (int i = 0; i < n_lines; i++) {
        input_buffer[i] = malloc(length * sizeof(char));
        fgets(input_buffer[i], length + 2, f);
    }
    fclose(f);
    return input_buffer;
}

int main(int argc, char *argv[]) {
    char **input = read_input("problems/resources/p13_input.txt", N_NUMBERS, LEN_NUMBER);
    int **numbers = malloc(N_NUMBERS * sizeof(int *));

    for (int i = 0; i < N_NUMBERS; i++) {
        numbers[i] = malloc(LEN_NUMBER * sizeof(int));
        for (int j = 0; j < LEN_NUMBER; j++) {
            numbers[i][j] = input[i][j] - '0';
        }

        free(input[i]);
    }
    free(input);

    // Conert all numbers to double precision floating point
    double *dbl_numbers = calloc(N_NUMBERS, sizeof(double));
    double sum = 0;
    for (int i = 0; i < N_NUMBERS; i++) {
        for (int j = 0; j < 15; j++) {  // 15 is the max decimal precision
            dbl_numbers[i] = dbl_numbers[i] + numbers[i][j] * pow(10, -1 * j);
        }
        sum += dbl_numbers[i];
    }
    free(dbl_numbers);

    // Convert double to char array to print out onlt first 10
    /*char *output = malloc(10 * sizeof(char));*/

    // Figure out inital magnitude
    int magnitude = 308;  // max exponent of c double
    while (pow(10, magnitude) > sum) {
        magnitude -= 1;
    }

    int tmp;
    for (int i = 0; i < N_DIGITS; i++) {
        tmp = sum / pow(10, magnitude);
        sum -= tmp * pow(10, magnitude);
        magnitude -= 1;
        printf("%d", tmp);
    }
    printf("\n");

    for (int i = 0; i < N_NUMBERS; i++){
        free(numbers[i]);
    }
    free(numbers);

    return 0;
}
