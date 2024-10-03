#include <stdio.h>
int main()
{
    int n, m, a = 1, x, y, hcf;
    printf("enter 2 num \n");
    scanf("%d%d", &x, &y);
    if (x > 0)
    {
        n = x;
        m = y;
    }
    else
    {
        n = y;
        m = x;
    }
    while (a != 0)
    {
        a = n % m;
        n = m;
        m = a;
    }
    hcf = n;

    printf("\nHCF=%d", hcf);
    return 0;
}
