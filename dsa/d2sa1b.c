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

void modifyNode(int arr[], int n, int index, int newValue) {
    if (index < 0 || index >= n) {
        printf("Invalid index\n");
        return;
    }

    arr[index] = newValue;

    int parent = (index - 1) / 2;

    // Check if the modified value is greater than its parent (for max heap)
    if (index > 0 && arr[index] > arr[parent]) {
        while (index != 0 && arr[index] > arr[parent]) {
            swap(&arr[index], &arr[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }
    // Check if the modified value is smaller than its children (for max heap)
    else {
        heapify(arr, n, index);
    }
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

    printf("Heap before modification: ");
    printHeap(arr, n);

    int index, newValue;
    printf("Enter the index of the node to modify (0-%d): ", n - 1);
    scanf("%d", &index);
    printf("Enter the new value: ");
    scanf("%d", &newValue);

    modifyNode(arr, n, index, newValue);

    printf("Heap after modification: ");
    printHeap(arr, n);

    free(arr);

    return 0;
}
