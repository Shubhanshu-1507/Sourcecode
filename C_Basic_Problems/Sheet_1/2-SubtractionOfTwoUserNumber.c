#include <stdio.h>

int main() {
  int a, b;
  printf("Enter A = \n");
  scanf("%d", &a);
  printf("Enter B = \n");
  scanf("%d", &b);

  printf("Difference of %d and %d is %d", a, b, a - b);
  return 0;
}