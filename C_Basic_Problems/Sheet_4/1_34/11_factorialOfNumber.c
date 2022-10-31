#include <stdio.h>
int main() {
  int a, i, fact = 1;
  printf("enter a num\n");
  scanf("%d", &a);
  if (a < 0)
    printf("number should be positive");
  else {
    for (i = 1; i <= a; i++) {
      fact = fact * i;
    }
    printf("factorial of %d is %d", a, fact);
  }
  return 0;
}