// https://www.hackerrank.com/challenges/bitwise-operators-in-c/problem

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void calculate_the_maximum(int n, int k) {
  int max_and, max_or, max_xor, and, or, xor;
  max_and = max_or = max_xor = 0;
  for (int a = 1; a <= n; a++) {
    for (int b = 1; b <= n; b++) {
      if (a != b) {
        and = a & b;
        if (and > max_and && and < k) {
          max_and = and;
        }
        or = a | b;
        if (or > max_or && or < k) {
          max_or = or;
        }
        xor = a ^ b;
        if (xor > max_xor && xor < k) {
          max_xor = xor;
        }
      }
    }
  }
  printf("%d\n%d\n%d\n", max_and, max_or, max_xor);
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);

    return 0;
}
