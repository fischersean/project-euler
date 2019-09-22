/*
 * Sean Fischer
 * 9/17/2019
 *
 * If we list all the natural numbers below 10 that are multiples of 3 or 5,
 * we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include <stdio.h>

#define UPPER_THRESH 1000

int main(int argc, char *argv[]) {

  // This is the simple approach
  unsigned int running_sum = 0;

  // We can start at three to save some time
  for (int i = 3; i < UPPER_THRESH; i++) {
    if (i % 3 == 0) {
      running_sum += i;
    } else if (i % 5 == 0) {
      running_sum += i;
    }
  }
  printf("%d\n", running_sum);
  return 0;
}