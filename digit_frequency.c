// https://www.hackerrank.com/challenges/frequency-of-digits-1/problem

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
  int *freq = (int *) calloc(10, sizeof(int));
  char num[1000 + 1];
  if (fgets(num, sizeof(num), stdin) != NULL) {
      for (int i = 0; i < strlen(num); i++) {
          if (isdigit(num[i])) {
              freq[num[i] - '0']++;
          }
      }
  }
  for (int i = 0; i < 10; i++) {
      printf("%d ", freq[i]);
  }
  return 0;
}
