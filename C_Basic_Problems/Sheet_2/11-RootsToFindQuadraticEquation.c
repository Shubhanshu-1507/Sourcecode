#include <math.h>
#include <stdio.h>

int main() {
  float a, b, c;
  float discriminant = 0, realPart = 0, imagPart = 0, root1 = 0, root2 = 0;
  printf(" Enter A, B, C as Ax^2 + Bx + C = 0:\n");
  scanf("%f%f%f", &a, &b, &c);
  discriminant = (b * b - 4 * a * c);

  if (discriminant > 0) {
    root1 = (-b + sqrt(discriminant)) / (2 * a);
    root2 = (-b - sqrt(discriminant)) / (2 * a);
    printf("root1 = %f and root2 = %f", root1, root2);
  }

  else if (discriminant == 0) {
    root1 = root2 = -b / (2 * a);
    printf("root1 = root2 = %f\n", root1);
  }

  else {
    realPart = -b / (2 * a);
    imagPart = sqrt(-discriminant) / (2 * a);
    printf("root1 = %f+%fi and root2 = %f-%fi\n", realPart, imagPart, realPart,
           imagPart);
  }
}
