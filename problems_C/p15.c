/*
 * Sean Fischer
 * 9/30/19
 * Starting in the top left corner of a 2×2 grid, and only being able to move to
 * the right and down, there are exactly 6 routes to the bottom right corner.
 *
 * (see problem stmt for figure)
 *
 * How many such routes are there through a 20×20 grid?
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 20

long long binom_coefficient(int n, int k) {
  // n choose k
  long double result = 1;
  for (int i = 1; i <= k; i++) {
    result *= n + 1 - i;
    result /= i;
  }
  return (long long)result;
}

int main(int argc, char *argv[]) {
  /*
   * From the wikipedia page on lattice paths:
   *
   * The number of paths from (0,0) to (n, k) using NE moves is equal to the binomial
   * coefficient (n+k , n)
   *
   */
  // printf("%lli\n", catalan(GRID_SIZE));
  // printf("%lli\n", factorial(n + 1));
  printf("The answer is: %lli\n", binom_coefficient(2 * GRID_SIZE, GRID_SIZE));

  return 0;
}