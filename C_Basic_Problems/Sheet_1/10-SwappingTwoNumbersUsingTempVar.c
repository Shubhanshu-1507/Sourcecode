#include <stdio.h>

int main()
{
    int a, b, temp;
    scanf("%d%d",&a,&b);
    temp = a;
    a = b;
    b = temp;
    printf("A= %d and B = %d\n",a,b);
}
