//Implement a Priority Queue using an array. An element with smaller value has higher priority.
#include <stdio.h>
#include <stdlib.h>
struct PriorityQueue {
    int* array;
    int capacity;
    int size;
};
struct PriorityQueue* createPriorityQueue(int capacity) {
    struct PriorityQueue* queue = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    queue->capacity = capacity;
    queue->size = 0;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}
int isFull(struct PriorityQueue* queue) {
    return queue->size == queue->capacity;
}
int isEmpty(struct PriorityQueue* queue) {
    return queue->size == 0;
}
void enqueue(struct PriorityQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Priority Queue is full\n");
        return;
    }
    int i = queue->size - 1;
    while (i >= 0 && queue->array[i] > item) {
        queue->array[i + 1] = queue->array[i];
        i--;
    }
    queue->array[i + 1] = item;
    queue->size++;
}
int dequeue(struct PriorityQueue* queue) {
    if (isEmpty(queue)) {
        printf("Priority Queue is empty\n");
        return -1;
    }
    return queue->array[--queue->size];
}
void freePriorityQueue(struct PriorityQueue* queue) {
    free(queue->array);
    free(queue);
}
int main() {
    struct PriorityQueue* queue = createPriorityQueue(5);
    enqueue(queue, 30);
    enqueue(queue, 20);
    enqueue(queue, 10);
    printf("Dequeued item: %d\n", dequeue(queue));
    printf("Dequeued item: %d\n", dequeue(queue));
    freePriorityQueue(queue);
    return 0;
}
