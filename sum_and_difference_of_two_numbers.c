// https://www.hackerrank.com/challenges/sum-numbers-c/problem

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int ia, ib;
  float fa, fb;

  scanf("%d %d", &ia, &ib);
  printf("%d %d\n", ia + ib, ia - ib);

  scanf("%f %f", &fa, &fb);
  printf("%.1f %.1f\n", fa + fb, fa - fb);

  return 0;
}
