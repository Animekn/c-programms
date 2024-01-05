#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the array
void heapify(int arr[], int n, int i, int isMaxHeap) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2;  // Right child

    // Compare left child with root (for max heap)
    if (isMaxHeap && left < n && arr[left] > arr[largest])
        largest = left;

    // Compare right child with root (for max heap)
    if (isMaxHeap && right < n && arr[right] > arr[largest])
        largest = right;

    // Compare left child with root (for min heap)
    if (!isMaxHeap && left < n && arr[left] < arr[largest])
        largest = left;

    // Compare right child with root (for min heap)
    if (!isMaxHeap && right < n && arr[right] < arr[largest])
        largest = right;

    // Swap and heapify recursively if necessary
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest, isMaxHeap);
    }
}

// Function to build a heap (max heap or min heap)
void buildHeap(int arr[], int n, int isMaxHeap) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, isMaxHeap);
}

// Function to print the heap
void printHeap(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, i, isMaxHeap;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter '1' for a max heap or '0' for a min heap: ");
    scanf("%d", &isMaxHeap);

    buildHeap(arr, n, isMaxHeap);

    printf("Heap: ");
    printHeap(arr, n);

    free(arr);

    return 0;
}
