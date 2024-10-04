#include <stdio.h>
int main()
{
    int n, m, d, rev = 0;
    printf("enter a num \n");
    scanf("%d", &n);
    m = n;
    for (; n != 0; n = n / 10)
    {
        d = n % 10;
        rev = rev * 10 + d;
    }
    if (rev == m)

        printf("\n%d is a palindrome no", m);
    else
        printf("\n%d is not a palindrome no", m);
    return 0;
}
