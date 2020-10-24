/*
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n
 * which divide evenly into n). If d(a) = b and d(b) = a, where a ≠ b, then a
 * and b are an amicable pair and each of a and b are called amicable numbers.
 *
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44,
 * 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4,
 * 71 and 142; so d(284) = 220.
 *
 * Evaluate the sum of all the amicable numbers under 10000.
 */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define U_BOUND 10000

int sum_divisors(int n) {
  // +1 is for the 1 divisor of all whole numbers
  int sum = 1;
  for (int i = 2; i < sqrt(n); i++) {
    if (n % i == 0) {
      sum += i;
      sum += n / i;
    }
  }
  return sum;
}

int pair_sum(int a) {
  int asum = sum_divisors(a);
  int bsum = sum_divisors(asum);

  if (a != bsum || asum < a) {
    return 0;
  } else if ((asum + bsum) - a == a) {
    return 0;
  } else {
    return asum + bsum;
  }
}

int main(int argc, char *argv[]) {

  int asum = 0;
  for (int i = 0; i < U_BOUND; i++) {
    asum += pair_sum(i);
  }
  printf("%d\n", asum);
  return 0;
}
