#include <stdio.h>
int main() {
  int n, i, j, sum;
  printf("enter a num \n");
  scanf("%d", &n);
  for (i = n; i > 0; i--) {
    for (j = 1; j <= i; j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}
