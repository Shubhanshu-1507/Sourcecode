#include <stdio.h>
int main()
{
    int n, d, sum = 0;
    printf("enter a num \n");
    scanf("%d", &n);
    for (; n != 0; n = n / 10)
    {
        d = n % 10;
        sum = sum + d;
    }
    printf("\nsum=%d", sum);
    return 0;
}
