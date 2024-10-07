def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quicksort(arr, low, high):
    while low < high:
        pi = partition(arr, low, high)
        if pi - low < high - pi:
            quicksort(arr, low, pi - 1)
            low = pi + 1
        else:
            quicksort(arr, pi + 1, high)
            high = pi - 1

if __name__ == "__main__":
    user_input = input("Enter numbers separated by spaces: ")
    arr = list(map(int, user_input.split()))
    
    quicksort(arr, 0, len(arr) - 1)
    
    print("Sorted array:", arr)
