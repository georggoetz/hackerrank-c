// https://www.hackerrank.com/challenges/sorting-array-of-strings/problem

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quicksort(char **a, int p, int r, int (*cmpf)(const char *a, const char *b));
int partition(char **a, int p, int q, int (*cmpf)(const char *a, const char *b));
void swap(char **a, int i, int j);
int num_distinct_chars(const char *s);

int lexicographic_sort(const char* a, const char* b) {
  return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
  return strcmp(b, a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
  int diff = num_distinct_chars(a) - num_distinct_chars(b);
  return (diff == 0) ? lexicographic_sort(a, b) : diff;
}

int num_distinct_chars(const char *s) {
  char freq[26] = {0};
  int sum = 0;
  for (int i = 0; i < strlen(s); i++) {
    freq[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (freq[i] > 0) {
      sum++;
    }
  }
  return sum;
}

int sort_by_length(const char* a, const char* b) {
  int diff = strlen(a) - strlen(b);
  return (diff == 0) ? lexicographic_sort(a, b) : diff;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
  quicksort(arr, 0, len - 1, cmp_func);
}

/* Cormen et al., Introduction to Algorithms, ch. 7 */
void quicksort(char **a, int p, int r, int (*cmpf)(const char *a, const char *b)) {
  if (p < r) {
    int q = partition(a, p, r, cmpf);
    quicksort(a, p, q - 1, cmpf);
    quicksort(a, q + 1, r, cmpf);
  }
}

int partition(char **a, int p, int r, int (*cmpf)(const char *a, const char *b)) {
  char *pivot = a[r];
  int i = p - 1;
  for (int j = p; j <= r - 1; j++) {
    if (cmpf(a[j], pivot) <= 0) {
      i = i + 1;
      swap(a, i, j);
    }
  }
  swap(a, i + 1, r);
  return i + 1;
}

void swap(char **a, int i, int j) {
  char *t = a[i];
  a[i] = a[j];
  a[j] = t;
}

int main() {
  int n;
  scanf("%d", &n);

  char **arr = (char**)malloc(n * sizeof(char*));

  for(int i = 0; i < n; i++){
    *(arr + i) = malloc(1024 * sizeof(char));
    scanf("%s", *(arr + i));
    *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
  }

  string_sort(arr, n, lexicographic_sort);
  for(int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");

  string_sort(arr, n, lexicographic_sort_reverse);
  for(int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");

  string_sort(arr, n, sort_by_length);
  for(int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");

  string_sort(arr, n, sort_by_number_of_distinct_characters);
  for(int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");
}
