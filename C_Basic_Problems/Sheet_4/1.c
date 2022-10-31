#include <stdio.h>
int main() {
  int n, i, j, sum;
  printf("enter a num \n");
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    for (j = 1; j < n; j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}
