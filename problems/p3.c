/*
* Sean Fischer
* 9/17/2019

* The prime factors of 13195 are 5, 7, 13 and 29.
* What is the largest prime factor of the number 600,851,475,143 ?
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TARGET_N 600851475143
#define TRUE 1
#define FALSE 0

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

long gcd(long a, long b) {
  // Euclids gcd formula
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

long rho_g(long x, long long n) { return (x * x + 1) % n; }

long rho_factor(long long n, long x) {
  // https://en.wikipedia.org/wiki/Pollard%27s_rho_algorithm
  long y, d; // Initial values for sequence
  long tmp;
  x = x;
  y = 2;
  d = 1;
  while (d == 1) {
    x = rho_g(x, n);
    y = rho_g(rho_g(y, n), n);
    if (x > y) {
      tmp = x - y;
    } else {
      tmp = y - x;
    }
    d = gcd(tmp, n);
  }

  return d;
}

int main(int argc, char *argv[]) {

  /*
   * Number of tries we will perform to find unique factors
   * This is only necessary because we suspect the target n
   * is made up of MORE than 2 prime factors
   */

  int n_factors = 10000; // Just a guestimate for the max number of factors
  long cur_high_factor = 1;

  long *fact_list = calloc(n_factors, sizeof(long));
  long j = 0; // counting index for unique values
  int fully_factored = FALSE;
  long n = TARGET_N;
  long factor_a;
  long factor_b;
  int a_prime_bool;
  int b_prime_bool;

  /*
   * We are essentially performing a
   * binary tree search with the rho algorithm
   */
  while (!fully_factored) {
    factor_a = rho_factor(n, random());
    factor_b = n / factor_a;

    /*printf("(%li, %li)\n", factor_a, factor_b);*/
    // If both a and b are prime -> fully factored
    a_prime_bool = is_prime(factor_a);
    b_prime_bool = is_prime(factor_b);
    /*printf("%d\n", a_prime_bool);*/
    /*printf("%d\n", b_prime_bool);*/

    if (a_prime_bool && b_prime_bool) {

      fact_list[j] = factor_a;
      j += 1;
      fact_list[j] = factor_b;
      fully_factored = TRUE;

    } else if (a_prime_bool) {

      fact_list[j] = factor_a;
      j++;
      n = n / factor_a;

    } else if (b_prime_bool) {
      fact_list[j] = factor_b;
      j++;
      n = n / factor_b;
    }
  }

  /*
   * Now that we have all the factors, we need to determine
   * which one is the largest. Can probably use the bult-in
   * quick sort to do this but this will work for now.
   */

  for (long i = 0; i <= j; i++) {
    // If prime, compare against current highest
    if (fact_list[i] > cur_high_factor) {
      cur_high_factor = fact_list[i];
    }
  }

  printf("The largest prime factor of %li found was: %li\n", TARGET_N,
         cur_high_factor);

  return 0;
}
