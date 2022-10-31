#include <stdio.h>
int main()
{
    int n, x, i, j, z;
    double sum = 1.0;
    printf("enter value of x and n\n");
    scanf("%d%d", &x, &n);
    for (i = 1; i <= n; i++)
    {
        z = 1;
        for (j = 1; j <= i; j++)
        {
            z = z * x;
        }
        if (i % 2 == 0)
            sum = sum + z;
        else
            sum = sum - z;
    }
    printf("sum of series upto %d is %lf", n, sum);
    return 0;
}
