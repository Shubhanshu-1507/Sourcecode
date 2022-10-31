#include <stdio.h>
int main() {
  int a, b, operator, answer = 0;
  printf("Enter Two Numbers A and B:\n");
  scanf("%d", &a);
  scanf("%d", &b);

  printf("Choose One Operator :\n1 Addition\n2 Subtraction\n3 Product\n4 "
         "Divide\n");
  scanf("%d", &operator);

  switch (operator) {
  case 1:
    printf("Addition of %d and %d is %d", a, b, a + b);
    break;
  case 2:
    printf("Subtraction of %d and %d is %d", a, b, a - b);
    break;
  case 3:
    printf("Product of %d and %d is %d", a, b, a * b);
    break;
  case 4:
    printf("Division of %d and %d is %d", a, b, a / b);
    break;

  default:
    printf("Invalid Selection of Operator");
    break;
  }
}
