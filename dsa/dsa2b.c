#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initialize(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int is_empty(Queue* queue) {
    return queue->front == -1;
}

int is_full(Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(Queue* queue, int item) {
    if (is_full(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (is_empty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    queue->items[queue->rear] = item;
}

int dequeue(Queue* queue) {
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

void remove_front(Queue* queue) {
    if (is_empty(queue)) {
        printf("Queue is empty, nothing to remove\n");
        return;
    }
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
}

int front(Queue* queue) {
    if (is_empty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->items[queue->front];
}

int main() {
    Queue queue;
    initialize(&queue);

    enqueue(&queue, 5);
    enqueue(&queue, 10);
    enqueue(&queue, 15);
    enqueue(&queue, 20);

    printf("Initial queue:\n");
    for (int i = queue.front; i != queue.rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", queue.items[i]);
    }
    printf("%d\n", queue.items[queue.rear]);

    remove_front(&queue);

    printf("Queue after removing the front element:\n");
    for (int i = queue.front; i != queue.rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", queue.items[i]);
    }
    printf("%d\n", queue.items[queue.rear]);

    return 0;
}
