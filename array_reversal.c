// https://www.hackerrank.com/challenges/reverse-array-c/problem

#include <stdio.h>
#include <stdlib.h>

int main() {
  int num, *arr, i, j, t;
  scanf("%d", &num);
  arr = (int*) malloc(num * sizeof(int));
  for(i = 0; i < num; i++)
    scanf("%d", arr + i);

  i = 0;
  j = num - 1;
  while (i < j) {
    t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
    i++;
    j--;
  }

  for(i = 0; i < num; i++)
    printf("%d ", *(arr + i));

  return 0;
}
