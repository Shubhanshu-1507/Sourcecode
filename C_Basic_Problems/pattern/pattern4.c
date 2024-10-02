#include <stdio.h>
int main()
{
    int i, j, k, row;
    printf("enter the number of row:\n");
    scanf("%d", &row);
    for (i = 1; i <= row; i++)
    {
        for (k = 1; i < row - i; k++)

        {
            printf(" ");
        }
        for (j = 1; j <= ((2 * i) - 1); i++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}