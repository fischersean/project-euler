/*
 *
 * Sean Fischer
 * 10/2/2019
 *
 *  2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *
 * What is the sum of the digits of the number 2^1000?
 */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TARGET_POW 1000

int *multiply(int *a, int b, int a_len) {
  // Thank god for wikipedia
  int *product = malloc((a_len + 1) * sizeof(int));
  memset(product, 0, (a_len + 1) * sizeof(int));
  int carry;
  carry = 0;
  for (int i = 0; i < a_len; i++) {
    product[i] += carry + a[i] * b;
    carry = product[i] / 10;
    product[i] = product[i] % 10;
  }

  if (carry != 0) {
    product[a_len] = carry;
    product[a_len + 1] = 10;
  } else {
    product[a_len] = 10;
  }
  return product;
}

int *calc_2_n(int exponent) {
  // Calculates 2^n. Stores in buffer. Terminated with NULL
  int n_digits = 1;
  int *product = malloc((n_digits + 1) * sizeof(int));

  memset(product, 0, n_digits * sizeof(int));
  product[0] = 1;
  for (int i = 0; i < exponent; i++) {
    product = multiply(product, 2, n_digits);

    // count number of digits
    while (product[n_digits] != 10) {
      n_digits++;
    }
  }
  return product;
}

int main(int argc, char *argv[]) {
  /*
   * Screw it. Lets just calculate 2^1000
   */

  int *result = calc_2_n(TARGET_POW);
  int i = 0;
  long sum = 0;
  while (result[i] != 10) {
    sum += result[i];
    i++;
  }
  printf("sum = %li\n", sum);
  return 0;
}