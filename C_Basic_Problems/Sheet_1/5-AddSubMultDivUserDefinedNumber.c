#include <stdio.h>

int main()
{
    float a, b;
    printf("Enter A = \n");
    scanf("%f", &a);
    printf("Enter B = \n");
    scanf("%f", &b);

    // Integer  Values
    printf("EXECUTION in INTEGER\n\n");

    printf("Addition of %d and %d is %d\n", a, b, a + b);
    printf("Subtraction of %d and %d is %d\n", a, b, a - b);
    printf("Product of %d and %d is %d\n", a, b, a * b);
    printf("Division of %d and %d is %d\n\n", a, b, a / b);

    // float Values

    printf("EXECUTION in FLOAT\n\n");

    printf("Addition of %f and %f is %.2f\n", a, b, a + b);
    printf("Subtraction of %f and %f is %.2f\n", a, b, a - b);
    printf("Product of %f and %f is %.2f\n", a, b, a * b);
    printf("Division of %f and %f is %.2f\n", a, b, a / b);

    return 0;
}
