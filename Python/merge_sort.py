def merge_sort(listy):
    if len(listy) <= 1:
        return listy

    left_half = listy[:len(listy) // 2]
    right_half = listy[len(listy) // 2:]

    return merge(merge_sort(left_half), merge_sort(right_half))

def merge(arr1, arr2):
    i = 0
    j = 0
    result = []
    while i < len(arr1) and j < len(arr2):
        if arr1[i] < arr2[j]:
            result.append(arr1[i])
            i += 1
        elif arr2[j] < arr1[i]:
            result.append(arr2[j])
            j += 1
        else:
            result.append(arr1[i])
            result.append(arr2[j])
            i += 1
            j += 1

    result.extend(arr1[i:])  # when one list exhausts before the other
    result.extend(arr2[j:])
    
    return result

def main():
    # Example usage
    listy = eval(input("Enter a list of numbers (e.g., [5, 2, 9, 1]): "))
    sorted_list = merge_sort(listy)
    print("Sorted list:", sorted_list)

if __name__ == "__main__":
    main()