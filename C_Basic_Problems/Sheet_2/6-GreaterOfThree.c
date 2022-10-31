#include <stdio.h>

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);

  if (a >= b && a >= c)
    printf("A = %d is the largest ", a);

  if (b >= a && b >= c)
    printf("B = %d is the largest ", b);

  if (c >= a && c >= b)
    printf("C = %d is the largest", c);
}
