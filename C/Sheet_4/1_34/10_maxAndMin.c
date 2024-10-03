#include <stdio.h>
int main()
{
    int a, i, max, min;
    printf("enter 10 numbers: \n");
    scanf("%d", &a);
    max = a;
    min = a;
    for (i = 2; i <= 10; i++)
    {
        scanf("%d", &a);
        if (a > max)
        {
            max = a;
        }
        else if (a < min)
        {
            min = a;
        }
    }
    printf("Maximum=%d and Minimum=%d", max, min);
    return 0;
}
