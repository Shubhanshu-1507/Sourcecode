#include <stdio.h>

void arr_input(int arr[], int n) {
    printf("Enter the elements of the array (non-negative integers): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void counting_sort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    int count[max + 1];
    
    // Initialize count array
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Store the count of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Store sorted values into the original array
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    arr_input(arr, n);
    
    printf("Array before sorting: ");
    print_array(arr, n);
    
    counting_sort(arr, n);
    
    printf("Array after sorting: ");
    print_array(arr, n);
    
    return 0;
}
