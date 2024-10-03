#include <stdio.h>

void arr_input(int arr[], int n) {
    printf("Enter the elements of the sorted array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

int binary_search(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;  // To avoid overflow

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    arr_input(arr, n);
    
    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);
    
    int index = binary_search(arr, n, key);
    
    if (index != -1) {
        printf("Element found at index: %d\n", index);
    } else {
        printf("Element not found\n");
    }
    
    return 0;
}
