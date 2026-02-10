#include <stdio.h>

// Swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Max-Heapify logic
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Min-Heapify logic
void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Build Max-Heap
void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Build Min-Heap
void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int data[] = {4, 1, 3, 2, 16, 9, 10};
    int n = sizeof(data) / sizeof(data[0]);
    int temp[10];

    printf("Original Array: ");
    printArray(data, n);

    // Build and display Max-Heap
    for(int i=0; i<n; i++) temp[i] = data[i];
    buildMaxHeap(temp, n);
    printf("Max-Heap: ");
    printArray(temp, n);

    // Build and display Min-Heap
    for(int i=0; i<n; i++) temp[i] = data[i];
    buildMinHeap(temp, n);
    printf("Min-Heap: ");
    printArray(temp, n);

    return 0;
}
