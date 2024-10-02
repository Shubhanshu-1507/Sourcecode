#include <stdio.h>
int main()
{
    int i, j, row;
    printf("enter the no of row:\n");
    scanf("%d", &row);
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("*");
        }

        printf("\n");
    }
    for (i = 1; i <= row; i++)
    {
        for (j = i; j <= row; j++)
        {
            printf("*");
        }

        printf("\n");
    }
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("*");
        }

        printf("\n");
    }
    /*  #include<stdio.h>
  int main()
  {
      int i,j,row;
      printf("enter the no of row:\n");
      scanf("%d",&row);*/
    for (i = 1; i <= row; i++)
    {
        for (j = i; j <= row; j++)
        {
            printf("*");
        }

        printf("\n");
    }
    return 0;
}