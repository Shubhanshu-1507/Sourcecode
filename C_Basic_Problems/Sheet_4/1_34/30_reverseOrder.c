#include <stdio.h>
int main() {
  int n, d, rev = 0;
  printf("enter a num \n");
  scanf("%d", &n);
  for (; n != 0; n = n / 10) {
    d = n % 10;
    rev = rev * 10 + d;
  }
  printf("\n%d", rev);
  return 0;
}
