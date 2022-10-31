#include <stdio.h>
int main()
{
    int n, i;
    double sum = 0;
    printf("enter a num\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        sum = sum + (double)i / (i + 1);
    }
    printf("sum of series upto %d is %lf", n, sum);
    return 0;
}
