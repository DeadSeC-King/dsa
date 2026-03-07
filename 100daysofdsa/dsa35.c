//Queue Using Array - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
struct Queue {
    int front, rear, capacity;
    int* array;
};
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}
int isFull(struct Queue* queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
}
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
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
void freeQueue(struct Queue* queue) {
    free(queue->array);
    free(queue);
}

int main() {
    struct Queue* queue = createQueue(5);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printf("Dequeued item: %d\n", dequeue(queue));
    printf("Dequeued item: %d\n", dequeue(queue));
    freeQueue(queue);
    return 0;
}