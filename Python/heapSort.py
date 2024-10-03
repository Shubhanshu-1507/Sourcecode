# Function to heapify a subtree rooted at index i
def heapify(arr, n, i):
    largest = i  # Initialize largest as root
    left = 2 * i + 1  # Left child
    right = 2 * i + 2  # Right child

    # If left child is larger than root
    if left < n and arr[left] > arr[largest]:
        largest = left

    # If right child is larger than largest so far
    if right < n and arr[right] > arr[largest]:
        largest = right

    # If largest is not root
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # Swap

        # Recursively heapify the affected subtree
        heapify(arr, n, largest)

# Main function to perform heap sort
def heap_sort(arr):
    n = len(arr)

    # Build a maxheap (rearrange array)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # One by one extract elements
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # Swap the root with the last element
        heapify(arr, i, 0)  # Heapify the reduced heap

# Utility function to print the array
def print_array(arr):
    for i in arr:
        print(i, end=" ")
    print()

# Main code to test heap sort
if __name__ == "__main__":
    arr = [12, 11, 13, 5, 6, 7]

    print("Original array:")
    print_array(arr)

    heap_sort(arr)

    print("Sorted array:")
    print_array(arr)
