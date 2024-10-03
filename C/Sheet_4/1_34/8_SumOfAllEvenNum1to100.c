#include <stdio.h>
int main()
{
    int i = 1, sum = 0;

    while (i <= 100)
    {
        if (i % 2 == 0)
        {
            sum = sum + i;
        }
        i++;
    }
    printf("Sum = %d", sum);
    return 0;
}
