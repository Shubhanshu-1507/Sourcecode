#include <stdio.h>
int main() {
  int n, i, a = 0, b = 1, c = 0;
  printf("enter a num \n");
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    printf(" \%d", c);
    a = b;
    b = c;
    c = a + b;
  }
  return 0;
}
