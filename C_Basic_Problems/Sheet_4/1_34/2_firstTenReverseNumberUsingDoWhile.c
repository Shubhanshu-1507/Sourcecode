#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printNumber(int n) {
    printf("%d\n", n);
}

int main() {
    int n = 10;
    int numbers[n];

    // Initialize the array with numbers from 1 to 10
    for (int i = 0; i < n; i++) {
        numbers[i] = i + 1;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Shuffle the numbers array using Fisher-Yates algorithm
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Swap numbers[i] and numbers[j]
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Print the numbers in reverse order
    printf("Numbers from 10 to 1:\n");
    for (int i = n - 1; i >= 0; i--) {
        printNumber(numbers[i]);
    }

    return 0;
}

