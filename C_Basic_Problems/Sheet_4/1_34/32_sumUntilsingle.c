#include <stdio.h>
int main()
{
    int n, d, sum;
    printf("enter a num \n");
    scanf("%d", &n);
    while (n > 9)
    {
        sum = 0;
        for (; n != 0; n = n / 10)
        {
            d = n % 10;
            sum = sum + d;
        }
        printf("\n%d", sum);
        n = sum;
    }
    printf("\nFinal Answer = %d", n);
    return 0;
}
