/*
 * Sean Fischer
 * 9/28/19
 *
 * The following iterative sequence is defined for the set of positive integers:
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following
 * sequence:
 *
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1)
 * contains 10 terms. Although it has not been proved yet (Collatz Problem), it
 * is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000000
// We use a larger hashzie because if it faster to iterate over an array
// than it is to step through an unordered linked list.
#define HASHSIZE 10001

/*
 * Riped the hash table implementation from The C Programming Language
 * (thank you D-Rich and B-Kerg)
 */
struct nlist {
  long key;
  long value;
  struct nlist *next;
};

static struct nlist *hashtab[HASHSIZE];

/* hash:  form hash value for string s */
unsigned int hash(long key) {
  // Simply take modulo of key to determine hash
  return key % HASHSIZE;
}

struct nlist *lookup(long key) {
  for (struct nlist *np = hashtab[hash(key)]; np != NULL; np = np->next) {
    if (np->key == key) {
      return np;
    }
  }
  return NULL; // Not found
}

void insert(long key, long value) {
  unsigned int hash_val = hash(key);
  struct nlist *np = hashtab[hash_val];
  // Inserts key value pair into hastable.
  // Does not check if key, value pair is alread present!
  if (np == NULL) {
    np = (struct nlist *)malloc(sizeof(*np));
    np->key = key;
    np->value = value;
    np->next = NULL;
    hashtab[hash_val] = np;
  } else {
    struct nlist *tmp = np;
    hashtab[hash_val] = (struct nlist *)malloc(sizeof(*np));
    hashtab[hash_val]->key = key;
    hashtab[hash_val]->value = value;
    hashtab[hash_val]->next = tmp;
  }
}

long collatz_length(long n, long cur_length) {
  // For checking + reference purposes only
  if (n == 1) {
    return cur_length + 1;
  }
  if (n % 2 == 0) {
    // printf("Incrementing Even\n");
    return collatz_length(n / 2, cur_length + 1);
  } else {
    // printf("Incrementing Odd\n");
    return collatz_length(3 * n + 1, cur_length + 1);
  }
}

int main(int argc, char *argv[]) {
  // Use a lookup table to reduce the number of iterations
  long max_len = 0;
  long max_i;
  long max_n_lookup = 0;
  long n;
  long p;
  struct nlist *lt;
  /* Turns out, it is faster to start at 0
   * This is likely because the lookup table is more
   * useful whe it has these lower key values populated
   */
  for (long i = 1; i < MAX_N; i++) {
    n = i;
    p = 1;
    // USED_SHORTCUT = 0;
    while (n > 1) {
      if (n <= max_n_lookup) {
        lt = lookup(n);
        if (lt != NULL) {
          p += lt->value - 1;
          break;
        }
      }
      if (n % 2 == 0) {
        n = n / 2;
        p += 1;
      } else {
        n = (3 * n + 1) / 2;
        p += 2;
      }
    }
    insert(i, p);
    if (i > max_n_lookup) {
      max_n_lookup = i;
    }
    if (p > max_len) {
      max_len = p;
      max_i = i;
    }

    if (i % 100000 == 0) {
      printf("i = %liK, max=%li\n", i / 1000, max_len);
    }
  }
  printf("MAX = collatz(%li) =  %li\n", max_i, max_len);
  return 0;
}