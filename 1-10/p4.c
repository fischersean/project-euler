/*
 * Sean Fischer
 * 9/19/2019
 *
 * A palindromic number reads the same both ways.
 * The largest palindrome made from the product of two 2-digit numbers is 9009 =
 * 91 × 99. Find the largest palindrome made from the product of two 3-digit
 * numbers.
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

int n_digits(int n) {
  // Count digits in base 10
  int k = 1;
  while (n >= 10) {
    n = n / 10;
    k++;
  }
  return k;
}

int is_palindrome(int n) {
  // Turn n into a string
  int digit_len = n_digits(n);
  int *n_split = malloc(digit_len * sizeof(char));
  int tmp;
  int base_place;
  /*
   * This for loop has the effect of reversing the number
   * but since we care about palindromes, the reversal doesnt matter
   */
  for (int i = digit_len - 1; i >= 0; i--) {
    base_place = pow(10, i);
    tmp = n / base_place;
    n = n - tmp * base_place;
    n_split[i] = tmp;
  }

  // Check to make sure array is a palindrome
  for (int i = 0; i < digit_len; i++) {
    if (n_split[i] != n_split[digit_len - 1 - i]) {
      // printf("(%d != %d)\n", n_split[i], n_split[digit_len - 1 - i]);
      return FALSE;
    }
  }
  return TRUE;
}

int main(int argc, char *argv[]) {
  /*
   * Try the simplest approach first
   */
  int max = 999;
  int largest_pal = 1;
  int tmp;
  for (int i = max; i >= 100; i--) {
    for (int j = max; j >= 100; j--) {
      tmp = i * j;
      if (is_palindrome(tmp) && tmp > largest_pal) {
        largest_pal = tmp;
      }
    }
  }

  printf("The largest palindrome of 2 three digit numbers is: %d\n",
         largest_pal);

  return 0;
}