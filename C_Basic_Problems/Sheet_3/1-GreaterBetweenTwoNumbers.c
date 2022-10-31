#include <stdio.h>

int main() {
  int a, b;
  scanf("%d", &a);
  scanf("%d", &b);

  (a > b) ? printf("A = %d is Greater\n", a) : printf("B = %d is Greater\n", b);
}
