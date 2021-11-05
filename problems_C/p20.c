/*
 * n! means n × (n − 1) × ... × 3 × 2 × 1
 *
 * For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
 * and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0
 * = 27.
 *
 * Find the sum of the digits in the number 100!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TARGET_N 100

int *multiply(int *a, int *b, int a_len, int b_len) {
    // Multiplies a and b. terminates with 10
    // Expects to have both numbers in reversed
    int prod_len = a_len + b_len + 1;  // +1 becuase we need the term char
    int *product = malloc(prod_len * sizeof(int));
    memset(product, 0, prod_len * sizeof(int));
    int carry;
    for (int i = 0; i < b_len; i++) {
        /*printf("%d", b[i]);*/
        carry = 0;
        for (int j = 0; j < a_len; j++) {
            product[j + i] += carry + a[j] * b[i];
            carry = product[i + j] / 10;
            product[i + j] = product[i + j] % 10;
        }
        product[i + a_len] = carry;
    }
    product[prod_len + 1] = 10;
    return product;
}

int *factorial(int n) {
    int n_digits = 1;
    int *product = malloc((n_digits + 1) * sizeof(int));
    // we can assume that it will never be longer than 3 digits
    int *b = malloc(3 * sizeof(int));
    int b_len;
    int tmp;

    memset(product, 0, n_digits * sizeof(int));
    product[0] = 1;
    for (int i = 1; i <= n; i++) {
        tmp = i;
        b_len = 1;
        while (tmp > 9) {
            tmp = tmp / 10;
            b_len++;
        }

        tmp = i;
        for (int j = b_len - 1; j >= 0; j--) {
            b[j] = tmp % 10;
            tmp = (tmp - b[j]) / 10;
        }
        // Need to reverse the array for it to work with multiply()
        for (int j = 0; j < b_len / 2; j++) {
            tmp = b[b_len - j - 1];
            b[b_len - j - 1] = b[j];
            b[j] = tmp;
        }
        product = multiply(product, b, n_digits, b_len);
        n_digits = 0;
        while (product[n_digits] != 10) {
            n_digits++;
        }
    }
    free(b);
    return product;
}

int main(int argc, char *argv[]) {
    int *result = factorial(TARGET_N);
    int i = 0;
    long sum = 0;
    while (result[i] != 10) {
        sum += result[i];
        i++;
    }
    printf("sum = %li\n", sum);
    free(result);

    return 0;
}
