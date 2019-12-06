// https://www.hackerrank.com/challenges/printing-pattern-2/problem

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
  int n;
  scanf("%d", &n);
  int dim = 1 + 2*(n-1);
  int row_count, col_count;
  for (int row = 0; row < dim; row++) {
    row_count = row > dim/2 ? dim - row - 1 : row;
    col_count = 0;
    for (int col = 0; col < dim; col++) {
      if (col >= dim - row_count) {
        col_count--;
      }
      printf("%d ", n-col_count);
      if (col < row_count) {
        col_count++;
      }
    }
    printf("\n");
  }
  return 0;
}
