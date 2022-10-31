#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    (n&1)?printf("%d is odd",n) :printf("%d is Even",n); 
}
