#include <stdio.h>

int main() {
  int a, b;
  scanf("%d", &a);
  scanf("%d", &b);

  if (a > b) {
    printf("%d is greater", a);
  } else if (a < b) {
    printf("%d is greater", b);
  } else {
    printf("%d and %d are Equal", a, b);
  }
}
