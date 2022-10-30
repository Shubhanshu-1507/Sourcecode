#include <stdio.h>

int main() {
  float p, r, t, ans = 0;
  scanf("%f%f%f", &p, &r, &t);
  ans = (p * r * t) / 100;
  printf("%f", ans);
  return 0;
}
