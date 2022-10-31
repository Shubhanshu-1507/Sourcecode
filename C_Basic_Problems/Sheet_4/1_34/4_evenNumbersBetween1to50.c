#include <stdio.h>
int main() {
  int i = 1;
  while (i <= 50) {
    if (i % 2 == 0)
      printf("\n%d", i);
    i++;
  }
  return 0;
}