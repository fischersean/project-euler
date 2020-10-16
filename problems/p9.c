/*
 * Sean Fischer
 * 9/21/2019
 *
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for
 * which,
 * a^2 + b^2 = c^2
 *
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TARGET_SUM 1000

int is_perfect_sq(int n) {
  // Find floating point value of
  // square root of x.
  long double sr = sqrt(n);

  // If square root is an integer
  return ((sr - floor(sr)) == 0);
}

int main(int argc, char *argv[]) {
  // Use euclids formula for generating triples
  /*
   * After doing some algebra, I found that all i need to do is solve the
   * following equation, given m, n, and k with the following conditions:
   *
   * m^2 + m * n = 500 / k
   * 1) m > n
   * 2) m, n are not BOTH odd
   * 3) m, n are co-prime
   *
   * -> implicitly, we also know that k%500 = 0
   *
   * Actually, scratch that. I'm doin the simple method
   */
  int a, b, c;
  // int n, m, k;
  // n = 1;
  // m = 2;
  int tmp;
  int increment = 1;
  int solution_found;

  for (int i = 1; i < 1000; i++) {
    for (int j = i + 1; j < 1000; j++) {
      // printf("i = %d, j = %d\n", i, j);
      tmp = pow(i, 2) + pow(j, 2);
      if (is_perfect_sq(tmp)) {
        c = sqrt(tmp);
        if (i + j + c == 1000) {
          a = i;
          b = j;
          goto exit_loc; // this feels so dirty
        }
      }
    }
  }
  return 1;

exit_loc:
  // printf("m = %d, n = %d, k = %d\n", m, n, k);
  printf("a = %d, b = %d, c = %d\n", a, b, c);
  printf("a x b x c = %d\n", a * b * c);
  return 0;
}