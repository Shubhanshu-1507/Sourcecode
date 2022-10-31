#include <stdio.h>
int main()
{
    int n, i, j, k, c = 0;
    printf("enter a num \n");
    scanf("%d", &n);
    for (i = 2; i <= n; i++)
    {
        k = 0;
        for (j = 2; j <= i / 2; j++)
        {
            if (!(i % j))
            {
                k = 1;
                break;
            }
        }
        if (!k)
        {
            printf("\n%d is a prime no", i);
            c++;
        }
    }
    printf("\nNo of prime nums upto %d are %d", n, c);
    return 0;
}
