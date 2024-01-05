#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

void initialize(CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int is_empty(CircularQueue* queue) {
    return queue->front == -1;
}

int is_full(CircularQueue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(CircularQueue* queue, int item) {
    if (is_full(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (is_empty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = item;
}

int dequeue(CircularQueue* queue) {
    if (is_empty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return item;
}

void remove_rear(CircularQueue* queue) {
    if (is_empty(queue)) {
        printf("Queue is empty, nothing to remove\n");
        return;
    }
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->rear = (queue->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
}

void printQueue(CircularQueue* queue) {
    if (is_empty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->items[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->items[i]);
}

int main() {
    CircularQueue queue;
    initialize(&queue);

    enqueue(&queue, 5);
    enqueue(&queue, 10);
    enqueue(&queue, 15);
    enqueue(&queue, 20);

    printf("Initial queue: ");
    printQueue(&queue);

    remove_rear(&queue);

    printf("Queue after removing rear element: ");
    printQueue(&queue);

    return 0;
}
