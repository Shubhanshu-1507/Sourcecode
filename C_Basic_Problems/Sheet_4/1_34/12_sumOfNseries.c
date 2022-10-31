#include <stdio.h>
int main()
{
    int n, i, sum = 0;
    printf("enter a num: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        sum = sum + i;
    }
    printf("sum of series upto %d is %d", n, sum);
    return 0;
}
