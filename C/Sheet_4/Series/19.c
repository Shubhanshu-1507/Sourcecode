#include <stdio.h>
int main()
{
    int n, x, i, j, k, z, fact;
    double sum = 1.0;
    printf("enter value of x and n\n");
    scanf("%d%d", &x, &n);
    for (i = 1; i <= n; i++)
    {
        z = 1;
        fact = 1;
        for (j = 1; j <= i; j++)
        {
            z = z * x;
        }
        for (k = 1; k <= i; k++)
        {
            fact = fact * k;
        }
        sum = sum + (double)z / fact;
    }
    printf("sum of series upto %d is %lf", n, sum);
    return 0;
}
