#include <stdio.h>
int main()
{
    int n;
    printf("enter a num \n");
    scanf("%d", &n);
    for (; n != 0; n = n / 10)
    {
        printf("\n%d", n % 10);
    }
    return 0;
}
