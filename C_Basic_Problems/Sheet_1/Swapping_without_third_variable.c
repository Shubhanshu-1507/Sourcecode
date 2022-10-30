# include <stdio.h>
int main() {
    int a, b;
    printf("Enter the value of a & b: ");
    scanf("%d %d", &a, &b);

    printf("Before the swapping of: a = %d, b = %d\n", a, b);

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("After the swapping of: a = %d, b = %d\n", a, b);

    return 0;
}
