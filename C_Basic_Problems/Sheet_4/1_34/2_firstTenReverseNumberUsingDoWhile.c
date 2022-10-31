#include <stdio.h>

int main() {

  int n = 10;

  printf("Numbers from 1 to 10: \n");

  do {
    printf("%d\n", n);
    n--;
  } while (n >= 1);

  return 0;
}
