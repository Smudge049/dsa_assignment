# Documentation for Program 8: Sorting Algorithms Comparison

## (a) Data Structure Definition
The program uses a **Dynamic Array** (`int* arr`) to store the $N$ randomly generated integers. It also uses a structure `SortStats` to globally track the number of comparisons and swaps performed during the sorting process.

## (b) Functions Implemented
- `generateRandom(int arr[], int n)`: Populates the array with $N$ integers in the range [1, 1000] using `rand()`.
- `bubbleSort(int arr[], int n)`: Iteratively swaps adjacent elements if they are in the wrong order.
- `selectionSort(int arr[], int n)`: Repeatedly finds the minimum element and places it at the beginning.
- `insertionSort(int arr[], int n)`: Builds the sorted array one element at a time by shifting larger elements.
- `mergeSort(int arr[], int l, int r)`: A divide-and-conquer algorithm that recursively splits and merges sorted sub-arrays.
- `stats.comparisons` and `stats.swaps`: Tracking variables inside each sort function.

## (c) main() Method Organization
The `main()` function:
1. Inputs $N$ from the user and allocates memory.
2. Generates and displays the random numbers.
3. Prompts the user to select one of the four sorting algorithms.
4. Resets stats, executes the chosen algorithm, and displays the sorted array.
5. Prints the final count of comparisons and swaps.

## (d) Sample Output
```
Enter the number of integers to generate: 10

Generated Numbers (Before Sorting):
423 12 856 2 101 45 990 12 55 300 

Choose a Sorting Algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter choice (1-4): 1

Numbers (After Sorting):
2 12 12 45 55 101 300 423 856 990 

--- Performance Statistics ---
Comparisons: 45
Swaps/Movements: 23
```
