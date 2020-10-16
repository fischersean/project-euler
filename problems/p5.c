/*
 * Sean Fischer
 * 9/20/19
 * 2520 is the smallest number that can be divided by each of
 * the numbers from 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly
 * divisible by all of the numbers from 1 to 20?
 *
 * This question is essentially asking to find the least
 * common multiple of {1, 2, 3,..., 20}
 */

// https://en.wikipedia.org/wiki/Least_common_multiple#Using_the_greatest_common_divisor

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define TARGET_N 20

int gcd(int a, int b) {
  // Euclids gcd formula
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

unsigned long lcm(unsigned long a, unsigned long b) {
  return a * b / gcd(a, b);
}

unsigned long lcm_set(int *set, int n) {
  /*
   * Returns the least common multiple of a generic
   * set of positive integers. Assumes the set is
   * ordered/sorted
   */

  // a * b / gcd(a, b)
  unsigned long a = set[n];
  unsigned long b;
  if (n == 1) {
    b = set[n - 1];
    printf("%lu, %lu\n", a, b);
  } else {
    b = lcm_set(set, n - 1);
    printf("%lu, %lu\n", a, b);
  }
  return lcm(a, b);
}

int main(int argc, char *argv[]) {

  int *set = malloc(20 * sizeof(int));
  unsigned k = 0;
  // Build out set
  for (int i = 0; i < TARGET_N; i++) {
    set[i] = i + 1;
  }

  printf("%lu\n", lcm_set(set, TARGET_N - 1));
  return 0;
}