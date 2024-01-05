#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void printHeap(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void removeValue(int arr[], int *n, int value) {
    int i;
    int found = 0;

    for (i = 0; i < *n; i++) {
        if (arr[i] == value) {
            swap(&arr[i], &arr[*n - 1]);
            (*n)--;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Value not found in the heap.\n");
        return;
    }

    heapify(arr, *n, i);
}

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    buildHeap(arr, n);

    printf("Heap before removal: ");
    printHeap(arr, n);

    int value;
    printf("Enter the value to remove: ");
    scanf("%d", &value);

    removeValue(arr, &n, value);

    printf("Heap after removal: ");
    printHeap(arr, n);

    free(arr);

    return 0;
}
