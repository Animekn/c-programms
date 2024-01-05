#include <stdio.h>

#define MAX_SIZE 100

void insert(int arr[], int size, int index, int value) {
    if (index >= 0 && index <= size) {
        for (int i = size - 1; i >= index; i--) {
            arr[i + 1] = arr[i];
        }
        arr[index] = value;
        size++;
        printf("Element inserted successfully.\n");
    } else {
        printf("Invalid index.\n");
    }
}

void removeElement(int arr[], int size, int index) {
    if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        printf("Element removed successfully.\n");
    } else {
        printf("Invalid index.\n");
    }
}

int main() {
    int arr[MAX_SIZE] = {1, 2, 3, 4, 5};
    int size = 5;

    insert(arr, size, 2, 10); // Insert 10 at index 2
    // Array after insert: {1, 2, 10, 3, 4, 5}

    removeElement(arr, size, 3); // Remove element at index 3
    // Array after remove: {1, 2, 10, 4, 5}

    return 0;
}
