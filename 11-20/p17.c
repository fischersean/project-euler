/*
 *
 * Sean Fischer
 * 10/4/2019
 *
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five,
 * then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 *
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out
 * in words, how many letters would be used?
 *
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and
 * forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20
 * letters. The use of "and" when writing out numbers is in compliance with
 * British usage.
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// I could define these with their char counts already defined
// but that would be had to keep track of
static const char *mag_lookup[2] = {"hundred\0", "thousand\0"};

static const char *lookup[27] = {
    "one\0",     "two\0",       "three\0",    "four\0",     "five\0",
    "six\0",     "seven\0",     "eight\0",    "nine\0",     "ten\0",
    "eleven\0",  "twelve\0",    "thirteen\0", "fourteen\0", "fifteen\0",
    "sixteen\0", "seventeen\0", "eighteen\0", "nineteen\0", "twenty\0",
    "thirty\0",  "forty\0",     "fifty\0",    "sixty\0",    "seventy\0",
    "eighty\0",  "ninety\0"};

int char_count(char *word) {
  int i = 0;
  while (word[i] != '\0') {

    i++;
  }

  return i;
}

int main(int argc, char *argv[]) {

  // May God forgive me for this horrific routine i've writter
  int count = 0;
  int n;
  int magnitude;
  int base;
  int value;
  // Hundreds and thoudands place
  for (int i = 1; i <= 1000; i++) {
    n = i;
    magnitude = (int)log10(n);
    while (magnitude >= 0) {
      base = (int)pow(10, magnitude);
      value = n / base;
      if (magnitude >= 2) {
        if (value > 0) {
          count += char_count((char *)lookup[value - 1]);
          count += char_count((char *)mag_lookup[magnitude - 2]);
        }
      } else if (n > 0) {
        if (i >= 100) {
          count += 3; // 'and'
        }
        if (n > 19) {
          count += char_count((char *)lookup[n / 10 + 17]);
          n = n - value * base;
          if (n > 0) {
            count += char_count((char *)lookup[n - 1]);
          }
          magnitude = -1;
        } else {
          count += char_count((char *)lookup[n - 1]);
          n = n - value * base;
          magnitude = -1;
        }
      }
      n = n - value * base;
      magnitude = magnitude - 1;
    }
  }
  printf("%d\n", count);

  return 0;
}