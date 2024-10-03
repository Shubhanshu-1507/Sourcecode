#include <stdio.h>
int main()
{
    int n, i, k, j, sum;
    printf("enter a num \n");
    scanf("%d", &n);
    for (i = n; i > 0; i--)
    {
        for (j = i; j < n; j++)
        {
            printf(" ");
        }
        for (k = 1; k <= i; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
