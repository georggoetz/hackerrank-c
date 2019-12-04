#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LEN 255

int main() {
  char c;
  char s[MAX_LEN + 1];

  scanf("%c", &c);
  printf("%c\n", c);

  scanf("%s", s);
  printf("%s\n", s);

  scanf("\n");
  scanf("%255[^\n]%*c", s);
  printf("%s\n", s);

  return 0;
}
