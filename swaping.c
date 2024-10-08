//swaping without tempVar 
#include <stdio.h>

int main() {
    int a = 5, b = 10;
    a = a ^ b;  
    b = a ^ b; 
    a = a ^ b;  

    printf("a: %d\n", a);  // Output: a: 10
    printf("b: %d\n", b);  // Output: b: 5

    return 0;
}
