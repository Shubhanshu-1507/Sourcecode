#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printNumber(int n) {
    printf("%d\n", n);
}

int main() {
    int n = 10;
    int numbers[n];


    for (int i = 0; i < n; i++) {
        numbers[i] = i + 1;
    }

    srand(time(NULL));

   
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
   
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    printf("Numbers from 10 to 1:\n");
    for (int i = n - 1; i >= 0; i--) {
        printNumber(numbers[i]);
    }

    return 0;
}

