/*
 *
 * Sean Fischer
 * 10/4/2019
 *
 * By starting at the top of the triangle below and moving to adjacent numbers
 * on the row below, the maximum total from top to bottom is 23.
 *
 *  3
 *  7 4
 *  2 4 6
 *  8 5 9 3
 *
 * That is, 3 + 7 + 4 + 9 = 23.
 * Find the maximum total from top to bottom of the triangle below:
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int **read_trianle(const char *file_name, int n_lines) {
    FILE *f = fopen(file_name, "r");

    int line_len;
    int **input_buffer = malloc(n_lines * sizeof(int *));
    for (int i = 0; i < n_lines; i++) {
        line_len = i + 1;
        input_buffer[i] = malloc(line_len * sizeof(int *));
        for (int j = 0; j < line_len; j++) {
            fscanf(f, "%d", &input_buffer[i][j]);
        }
    }

    fclose(f);
    return input_buffer;
}

int max_path(const char *file_name, int n_lines) {
    int **input_buffer = read_trianle(file_name, n_lines);
    int A, a, b, max;

    for (int i = n_lines - 2; i >= 0; i--) {
        for (int j = 0; j < i + 1; j++) {
            A = input_buffer[i][j];
            a = input_buffer[i + 1][j];
            b = input_buffer[i + 1][j + 1];
            input_buffer[i][j] = a + A > b + A ? a + A : b + A;
            /*printf("Collapsing %d, %d, %d -> %d\n", a, b, A,*/
            /*input_buffer[i][j]);*/
        }
    }
    max = input_buffer[0][0];
    free(input_buffer);
    return max;
}

int main(int argc, char *argv[]) {
    int result = max_path("resources/p18_tri.txt", 15);
    printf("%d\n", result);
    return 0;
}
