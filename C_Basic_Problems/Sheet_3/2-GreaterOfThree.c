#include <stdio.h>

int main() {
  int a, b, c, answer = 0;
  scanf("%d%d%d", &a, &b, &c);

  answer = (a > b) ? (a > c ? a : c) : (b > c ? b : c);
  printf("%d is Greatest of Three ", answer);
}
