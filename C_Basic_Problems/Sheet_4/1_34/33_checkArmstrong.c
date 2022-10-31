#include <stdio.h>
int main()
{
    int n, x, d, m, z, j, sum = 0, l = 0;
    printf("enter a num \n");
    scanf("%d", &n);
    m = n;
    x = n;
    while (m > 0)
    {
        m = m / 10;
        l++;
    }
    printf("lenght is %d", l);
    for (; n != 0; n = n / 10)
    {
        d = n % 10;
        z = 1;
        for (j = 1; j <= l; j++)
        {
            z = z * d;
        }
        sum = sum + z;
    }
    printf("\n sum=%d", sum);
    if (x == sum)
        printf("\n%d is an armstrong no", x);
    else
        printf("\n%d is not an armstrong no", x);
    return 0;
}
