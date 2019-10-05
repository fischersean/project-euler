/*
 * Sean Fischer
 * 9/21/2019
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
 * that the 6th prime is 13.
 *
 * What is the 10 001st prime number?
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_N 10001

int is_prime(long n) {
  // https://en.wikipedia.org/wiki/Primality_test#Pseudocode

  if (n <= 3) {
    return n > 1;
  } else if (n % 2 == 0 || n % 3 == 0) {
    return FALSE;
  }

  long i = 5;

  while (i * i <= n) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return FALSE;
    }
    i = i + 6;
  }

  return TRUE;

  return 0;
}

void first_n_primes(long *set, int n) {
  long k = 1;
  int i = 2;
  long tmp;
  set[0] = 2;
  set[1] = 3;
  while (i < n) {
    tmp = 6 * k;
    if (is_prime(tmp - 1)) {
      set[i] = tmp - 1;
      i++;
    }
    if (is_prime(tmp + 1)) {
      set[i] = tmp + 1;
      i++;
    }
    k++;
  }
}

int main(int argc, char *argv[]) {

  long *set = malloc(MAX_N * sizeof(long));

  first_n_primes(set, MAX_N);
  printf("%li\n", set[MAX_N - 1]);

  return 0;
}