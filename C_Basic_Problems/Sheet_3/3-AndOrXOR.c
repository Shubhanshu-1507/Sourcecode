#include <stdio.h>

int main() {
  int a, b, answer_AND, answer_OR, answer_XOR;
  scanf("%d", &a);
  scanf("%d", &b);

  answer_AND = a & b; // AND
  answer_OR = a | b;  // OR
  answer_XOR = a ^ b; // XOR

  printf("AND of %d and %d = %d\n", a, b, answer_AND);
  printf("OR of %d and %d = %d\n", a, b, answer_OR);
  printf("XOR of %d and %d = %d\n", a, b, answer_XOR);
}
