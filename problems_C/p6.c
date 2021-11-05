/*
 * Sean Fischer
 * 9/20/2019
 * The sum of the squares of the first ten natural numbers is,
 * 1^2 + 2^2 + ... + 10^2 = 385
 *
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)^2 = 55^2 = 3025
 *
 * Hence the difference between the sum of the squares of the first ten natural
 * numbers and the square of the sum is 3025 − 385
 *
 * Find the difference between the sum of the squares of the first one hundred
 * natural numbers and the square of the sum.
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

long sum_set(long *set, int len) {
  long runing_sum = 0;
  for (int i = 0; i < len; i++) {
    runing_sum += set[i];
  }
  return runing_sum;
}

long brute_force(int n) {
  // set a is all natural numbers < max
  long *set_a = malloc(n * sizeof(long));
  // set a is the square all natural numbers < max
  long *set_b = malloc(n * sizeof(long));
  long nat_n_squared;

  // populate each set
  for (int i = 0; i < n; i++) {
    set_a[i] = i + 1;
    set_b[i] = pow(i + 1, 2);
  }
  long sum_a = pow(sum_set(set_a, n), 2);
  long sum_b = sum_set(set_b, n);

  return sum_a - sum_b;
}

long optimized_method(int n) {
  // Ripped directly from the problem writeup
  long sum = n * (n + 1) / 2;
  long sum_sq = (2 * n + 1) * (n + 1) * n / 6;
  return pow(sum, 2) - sum_sq;
}

int main(int argc, char *argv[]) {

  printf("Brute Force: %li\n", brute_force(MAX_N));
  printf("Clever Optimized: %li\n", optimized_method(MAX_N));

  return 0;
}