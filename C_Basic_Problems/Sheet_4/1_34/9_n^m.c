#include <stdio.h>
int main() {
  int n, m, pow = 1, i = 1;
  printf("enter value of Base (n) amd Power (m)\n");
  scanf("%d%d", &n, &m);
  while (i <= m) {
    pow = pow * n;
    i++;
  }
  printf("\n Base(n)^Power(m)=%d", pow);
  return 0;
}
