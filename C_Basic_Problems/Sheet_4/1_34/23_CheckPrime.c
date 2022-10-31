#include <stdio.h>
int main() {
  int n, i, k = 0;
  printf("enter a num \n");
  scanf("%d", &n);
  for (i = 2; i <= n / 2; i++) {

    if (!(n % i)) {
      k = i;
      break;
    }
  }
  if (!k)
    printf("%d is a prime no", n);
  else
    printf("%d is not a prime no", n);
  return 0;
}
