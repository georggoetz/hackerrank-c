#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char nums[10][6] = {
  "zero",
  "one",
  "two",
  "three",
  "four",
  "five",
  "six",
  "seven",
  "eight",
  "nine"
};

int main() {
  int a, b;
  scanf("%d\n%d", &a, &b);

  for (int i = a; i <= b; i++) {
    if (i < 10) {
      printf("%s\n", nums[i]);
    } else {
      printf("%s\n", i % 2 == 0 ? "even" : "odd");
    }
  }

  return 0;
}
