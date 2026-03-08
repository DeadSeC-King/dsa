//Circular Queue Using Array - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
struct CircularQueue {
    int front, rear, capacity;
    int* array;
};
struct CircularQueue* createCircularQueue(int capacity) {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}
int isFull(struct CircularQueue* queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}
int isEmpty(struct CircularQueue* queue) {
    return queue->front == -1;
}
void enqueue(struct CircularQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Circular Queue is full\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
}
int dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular Queue is empty\n");
        return -1;
    }
    int item = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return item;
}
void freeCircularQueue(struct CircularQueue* queue) {
    free(queue->array);
    free(queue);
}

int main() {
    struct CircularQueue* queue = createCircularQueue(5);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printf("Dequeued item: %d\n", dequeue(queue));
    printf("Dequeued item: %d\n", dequeue(queue));
    freeCircularQueue(queue);
    return 0;
}