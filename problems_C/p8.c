/*
 * Sean Fischer
 * 9/21/2019
 *
 * The four adjacent digits in the 1000-digit number that have the greatest
 * product are 9 × 9 × 8 × 9 = 5832.
 *
 * Find the thirteen adjacent digits in the 1000-digit number that have the
 * greatest product. What is the value of this product?
 *
 * 73167176531330624919225119674426574742355349194934
 * 96983520312774506326239578318016984801869478851843
 * 85861560789112949495459501737958331952853208805511
 * 12540698747158523863050715693290963295227443043557
 * 66896648950445244523161731856403098711121722383113
 * 62229893423380308135336276614282806444486645238749
 * 30358907296290491560440772390713810515859307960866
 * 70172427121883998797908792274921901699720888093776
 * 65727333001053367881220235421809751254540594752243
 * 52584907711670556013604839586446706324415722155397
 * 53697817977846174064955149290862569321978468622482
 * 83972241375657056057490261407972968652414535100474
 * 82166370484403199890008895243450658541227588666881
 * 16427171479924442928230863465674813919123162824586
 * 17866458359124566529476545682848912883142607690042
 * 24219022671055626321111109370544217506941658960408
 * 07198403850962455444362981230987879927244284909188
 * 84580156166097919133875499200524063689912560717606
 * 05886116467109405077541002256983155200055935729725
 * 71636269561882670428252483600823257530420752963450
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define N_LEN 13
#define LEN_STR 1000

long set_product(int *set, int begin, int end) {
  long prod = 1;
  for (int i = begin; i < end; i++) {
    // printf("%d", set[i]);
    prod *= set[i];
  }
  return prod;
}

long max_n_len(int *set, int len, int n) {
  /*
   * Calculate the product of the first n elements where n is the length of our
   * analysis window. int len is the total length of the set
   */

  long running_prod = set_product(set, 0, n);
  long max_prod = running_prod;

  for (int i = n; i < len; i++) {
    running_prod = set_product(set, i, n + i);
    if (running_prod > max_prod) {
      max_prod = running_prod;
    }
  }
  return max_prod;
}

int main(int argc, char *argvp[]) {

  FILE *f = fopen("problems/resources/p8_n.txt", "r");
  char *tmp = malloc(LEN_STR * sizeof(char));
  int *set = malloc(LEN_STR * sizeof(int));

  fscanf(f, "%s", tmp);
  fclose(f);

  // convert set to int
  for (int i = 0; i < LEN_STR; i++) {
    set[i] = tmp[i] - '0';
  }
  free(tmp);

  printf("%li\n", max_n_len(set, LEN_STR, N_LEN));

  return 0;
}
