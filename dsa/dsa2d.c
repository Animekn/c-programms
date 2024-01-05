#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Deque;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

int is_empty(Deque* deque) {
    return deque->front == NULL;
}

void addFront(Deque* deque, int data) {
    Node* newNode = createNode(data);

    if (is_empty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

void addRear(Deque* deque, int data) {
    Node* newNode = createNode(data);

    if (is_empty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

int removeFront(Deque* deque) {
    if (is_empty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }

    Node* frontNode = deque->front;
    int data = frontNode->data;

    if (deque->front == deque->rear) {
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->front = deque->front->next;
        deque->front->prev = NULL;
    }

    free(frontNode);
    return data;
}

int removeRear(Deque* deque) {
    if (is_empty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }

    Node* rearNode = deque->rear;
    int data = rearNode->data;

    if (deque->front == deque->rear) {
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
    }

    free(rearNode);
    return data;
}

void printDeque(Deque* deque) {
    if (is_empty(deque)) {
        printf("Deque is empty\n");
        return;
    }

    Node* temp = deque->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Deque deque;
    deque.front = NULL;
    deque.rear = NULL;

    addFront(&deque, 10);
    addRear(&deque, 20);
    addFront(&deque, 5);

    printf("Deque: ");
    printDeque(&deque);

    int removedFront = removeFront(&deque);
    printf("Removed front element: %d\n", removedFront);

    int removedRear = removeRear(&deque);
    printf("Removed rear element: %d\n", removedRear);

    printf("Deque after removals: ");
    printDeque(&deque);

    return 0;
}
