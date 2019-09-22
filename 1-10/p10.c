/*
 * Sean Fischer
 * 9/22/2019
 *
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17
 *
 * Find the sum of all the primes below two million.
 * 2000000
 */

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define TARGET_N 2000000

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
}

long next_prime(long cur_prime) {
  do {
    cur_prime += 2;
    // printf("k updated to %li\n", cur_prime);
  } while (!is_prime(cur_prime));
  return cur_prime;
}

int main(int argc, char *argv[]) {

  long k = 3; // precalculate first 2 primes
  unsigned long long running_sum = 2;

  while (k < TARGET_N) {
    running_sum += k;
    //printf("k updated to %li\n", k);
    k = next_prime(k);
  }

  printf("%llu\n", running_sum);
  return 0;
}