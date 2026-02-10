#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to track performance statistics
typedef struct {
    long long comparisons;
    long long swaps;
} SortStats;

SortStats stats = {0, 0};

// Utility to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    stats.swaps++;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            stats.comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            stats.comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&arr[i], &arr[min_idx]);
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            stats.comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                stats.swaps++; // Treating shift as part of "swap/movement"
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

// Merge helper for Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        stats.comparisons++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        stats.swaps++; // Count as movement
    }

    while (i < n1) {
        arr[k++] = L[i++];
        stats.swaps++;
    }
    while (j < n2) {
        arr[k++] = R[j++];
        stats.swaps++;
    }

    free(L);
    free(R);
}

// Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void generateRandom(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 1000) + 1;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, choice;
    srand(time(NULL));

    printf("Enter the number of integers to generate: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    generateRandom(arr, n);

    printf("\nGenerated Numbers (Before Sorting):\n");
    printArray(arr, n);

    printf("\nChoose a Sorting Algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &choice);

    stats.comparisons = 0;
    stats.swaps = 0;

    switch (choice) {
        case 1: bubbleSort(arr, n); break;
        case 2: selectionSort(arr, n); break;
        case 3: insertionSort(arr, n); break;
        case 4: mergeSort(arr, 0, n - 1); break;
        default: printf("Invalid choice!\n"); free(arr); return 1;
    }

    printf("\nNumbers (After Sorting):\n");
    printArray(arr, n);

    printf("\n--- Performance Statistics ---\n");
    printf("Comparisons: %lld\n", stats.comparisons);
    printf("Swaps/Movements: %lld\n", stats.swaps);

    free(arr);
    return 0;
}
