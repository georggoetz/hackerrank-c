#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **s, int i, int j);

/* Knuth, The Art of Computer Programming, ch. 7.2.1.2 Lexicographic Permutation Generation */
int next_permutation(int n, char **s) {
	int j = n - 2;
  // Find j
  while (strcmp(s[j], s[j + 1]) >= 0) {
    if (j == 0) {
      return 0;
    }
    j--;
  }
  // Increase s[j]
  int l = n - 1;
  while (strcmp(s[j], s[l]) >= 0) {
    l--;
  }
  swap(s, j, l);
  // Reverse s[j+1]...s[n]
  int k = j + 1;
  l = n - 1;
  while (k < l) {
    swap(s, k, l);
    k++;
    l--;
  }
  return 1;
}

void swap(char **s, int i, int j) {
  char *t = s[i];
  s[i] = s[j];
  s[j] = t;
}

int main() {
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++) {
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do {
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
