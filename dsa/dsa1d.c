#include <stdio.h>
#include <stdlib.h>

// Structure for deque node
struct DequeNode {
    int data;
    struct DequeNode* prev;
    struct DequeNode* next;
};

// Structure for deque
struct Deque {
    struct DequeNode* front;
    struct DequeNode* rear;
};

// Function to create a new node
struct DequeNode* createNode(int value) {
    struct DequeNode* newNode = (struct DequeNode*)malloc(sizeof(struct DequeNode));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty deque
struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

// Function to check if the deque is empty
int isEmpty(struct Deque* deque) {
    return (deque->front == NULL);
}

// Function to insert an element at the front of the deque
void insertFront(struct Deque* deque, int value) {
    struct DequeNode* newNode = createNode(value);
    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

// Function to insert an element at the rear of the deque
void insertRear(struct Deque* deque, int value) {
    struct DequeNode* newNode = createNode(value);
    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

// Function to print the elements of the deque from front to rear
void printDeque(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }
    struct DequeNode* temp = deque->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Deque* deque = createDeque();

    // Inserting elements at the front of the deque
    insertFront(deque, 10);
    insertFront(deque, 20);
    insertFront(deque, 30);

    // Printing the deque from front to rear
    printf("Deque from front to rear: ");
    printDeque(deque);

    // Inserting elements at the rear of the deque
    insertRear(deque, 40);
    insertRear(deque, 50);
    insertRear(deque, 60);

    // Printing the deque from front to rear
    printf("Updated deque from front to rear: ");
    printDeque(deque);

    return 0;
}
