#include <stdio.h>

int main() {
  float a, b, average = 0, percentage = 0;
  scanf("%f%f", &a, &b);
  average = a + b / 2;
  percentage = (a / b) * 100;
  printf("Average = %f\n", average);
  printf("Percentage = %f", percentage);
  return 0;
}
