# Documentation for Program 6: Build Min and Max Heap

## (a) Data Structure Definition
The program uses a **Binary Heap** stored in a contiguous **Array**.
- A Max-Heap ensures that the parent node is always greater than or equal to its children.
- A Min-Heap ensures that the parent node is always less than or equal to its children.
- Roots are at index 0. For any index `i`, left child is at `2i + 1` and right child is at `2i + 2`.

## (b) Functions Implemented
- `maxHeapify(int arr[], int n, int i)`: Sifts down the element at index `i` to its correct position to maintain the Max-Heap property.
- `minHeapify(int arr[], int n, int i)`: Sifts down the element at index `i` to maintain the Min-Heap property.
- `buildMaxHeap(int arr[], int n)`: Calls `maxHeapify` starting from the last non-leaf node up to the root.
- `buildMinHeap(int arr[], int n)`: Calls `minHeapify` in a similar bottom-up manner to construct a Min-Heap.

## (c) main() Method Organization
The `main()` function:
1. Initializes an unsorted array: `{4, 1, 3, 2, 16, 9, 10}`.
2. Creates a copy of the array for building the Max-Heap and prints the result.
3. Creates another copy for building the Min-Heap and prints the result.

## (d) Sample Output
```
Original Array: 4 1 3 2 16 9 10 
Max-Heap: 16 4 10 2 1 9 3 
Min-Heap: 1 2 3 4 16 9 10 
```
