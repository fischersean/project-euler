/*
 * Sean Fischer
 * 9/23/2019
 *
 * In the 20×20 grid below, four numbers along a diagonal line have been marked
 * in red.
 *
 * (grid not shown here)
 *
 * The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
 *
 * What is the greagrid product of four adjacent numbers in the same direction
 * (up, down, left, right, or diagonally) in the 20×20 grid?
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 20
#define SEARCH_LEN 4

int **read_int_grid(int width, int height, const char *file_name) {

  FILE *f = fopen(file_name, "r");

  int **input_buffer = malloc(height * sizeof(int *));

  for (int i = 0; i < height; i++) {
    input_buffer[i] = malloc(width * sizeof(int));
    for (int j = 0; j < width; j++) {
      fscanf(f, "%d", &input_buffer[i][j]);
    }
  }
  fclose(f);

  return input_buffer;
}

long diagonal_prod(int **grid, int x, int y, int len, int grid_edge) {
  long max_prod = 1;
  long running_prod = 1;

  // down and right
  if (x + len <= grid_edge && y + len <= grid_edge) {
    for (int i = 0; i < len; i++) {
      running_prod *= grid[x + i][y + i];
    }
  }
  max_prod = running_prod > max_prod ? running_prod : max_prod;
  running_prod = 1;
  // down and left
  if (x + len <= grid_edge && y - len >= 0) {
    for (int i = 0; i < len; i++) {
      running_prod *= grid[x + i][y - i];
    }
  }
  max_prod = running_prod > max_prod ? running_prod : max_prod;
  running_prod = 1;

  return max_prod;
}

long vertical_prod(int **grid, int x, int y, int len) {
  long running_prod = 1;

  for (int i = 0; i < len; i++) {
    running_prod *= grid[x + i][y];
  }

  return running_prod;
}

long horizontal_prod(int **grid, int x, int y, int len) {
  long running_prod = 1;

  for (int i = 0; i < len; i++) {
    running_prod *= grid[x][y + i];
  }

  return running_prod;
}

int main(int argc, char *argv[]) {

  int **grid = read_int_grid(20, 20, "resources/p11_grid.txt");

  long max_prod = 1;
  long vert_prod;
  long hori_prod;
  long diag_prod;

  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      if (i <= GRID_SIZE - SEARCH_LEN && j <= GRID_SIZE - SEARCH_LEN) {
        diag_prod = diagonal_prod(grid, i, j, SEARCH_LEN, GRID_SIZE);
      } else {
        diag_prod = 1;
      }
      if (i <= GRID_SIZE - SEARCH_LEN) {
        vert_prod = vertical_prod(grid, i, j, SEARCH_LEN);
      } else {
        vert_prod = 1;
      }
      if (j <= GRID_SIZE - SEARCH_LEN) {
        hori_prod = horizontal_prod(grid, i, j, SEARCH_LEN);
      } else {
        hori_prod = 1;
      }

      max_prod = vert_prod > max_prod ? vert_prod : max_prod;
      max_prod = hori_prod > max_prod ? hori_prod : max_prod;
      max_prod = diag_prod > max_prod ? diag_prod : max_prod;
    }
  }

  printf("MAX = %li\n", max_prod);
  free(grid);
  return 0;
}