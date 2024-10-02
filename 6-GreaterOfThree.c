#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int largest = a;

    if (b > largest) { largest = b; }
    
    if (c > largest) { largest = c; }

    printf("The largest number is %d\n", largest);
}
