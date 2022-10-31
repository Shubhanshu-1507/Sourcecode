#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  if ((n % 100) && (n % 4)) {
    printf("%d is not a leap Year", n);
  } else {
    printf("%d is a leap Year", n);
  }
}
