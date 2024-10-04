class MaxHeap:
    def __init__(self):
        """Initializes an empty heap."""
        self.heap = []

    def _left_child(self, index):
        """Returns the index of the left child."""
        return 2 * index + 1

    def _right_child(self, index):
        """Returns the index of the right child."""
        return 2 * index + 2

    def _parent(self, index):
        """Returns the index of the parent."""
        return (index - 1) // 2

    def _swap(self, index1, index2):
        """Swaps elements at two indices."""
        self.heap[index1], self.heap[index2] = self.heap[index2], self.heap[index1]

    def remove(self):
        """Removes and returns the maximum value (root)."""
        if len(self.heap) == 0:
            return None
        if len(self.heap) == 1:
            return self.heap.pop()

        max_value = self.heap[0]
        self.heap[0] = self.heap.pop()
        self._sink_down(0)
        return max_value

    def _sink_down(self, index):
        """Restores heap property by sinking down an element."""
        max_index = index
        while True:
            left_index = self._left_child(index)
            right_index = self._right_child(index)

            if left_index < len(self.heap) and self.heap[left_index] > self.heap[max_index]:
                max_index = left_index
            if right_index < len(self.heap) and self.heap[right_index] > self.heap[max_index]:
                max_index = right_index

            if max_index != index:
                self._swap(index, max_index)
                index = max_index
            else:
                break

    def heapify(self, my_list):
        """Converts a list into a max-heap."""
        self.heap = my_list
        for i in range(len(self.heap) // 2 - 1, -1, -1):
            self._sink_down(i)
        return self.heap

    def heap_sort(self, my_list):
        """Sorts a list using heap sort."""
        self.heapify(my_list)
        sorted_list = []
        while len(self.heap) > 0:
            sorted_list.append(self.remove())
        return sorted_list[::-1]


def main():
    """Demonstrates the MaxHeap class functionality using heapify."""
    # Input a list using eval
    numbers = eval(input("Enter a list of numbers (e.g., [3, 9, 5]): "))
    
    heap = MaxHeap()
    print(f"Original list: {numbers}")

    # Heapifying the input list
    heap.heapify(numbers)
    print(f"Heap after heapify: {heap.heap}")

    # Sorting the list using heap sort
    sorted_list = heap.heap_sort(numbers.copy())
    print(f"Sorted list using heap sort: {sorted_list}")


if __name__ == "__main__":
    main()
