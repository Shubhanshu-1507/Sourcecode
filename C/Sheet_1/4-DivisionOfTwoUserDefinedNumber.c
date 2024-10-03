#include <stdio.h>

int main()
{
    float a, b;
    printf("Enter A = \n");
    scanf("%f", &a);
    printf("Enter B = \n");
    scanf("%f", &b);

    printf("Division of %f and %f is %.2f", a, b, a / b);
    return 0;
}
