#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void update(int *pa,int *pb) {
  int a = *pa, b = *pb;
  *pa = a + b;
  *pb = abs(a - b);
}

int main() {
  int a, b;
  int *pa = &a, *pb = &b;

  scanf("%d %d", &a, &b);
  update(pa, pb);
  printf("%d\n%d", a, b);

  return 0;
}
