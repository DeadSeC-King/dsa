//Given a queue of integers, reverse the queue using a stack.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue {
    int front, rear, capacity;
    int* array;
};
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = 0;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
int isFull(struct Queue* queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}
int isEmpty(struct Queue* queue) {
    return queue->front == queue->rear;
}
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->array[queue->rear] = item;
    queue->rear = (queue->rear + 1) % queue->capacity;
}
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    return item;
}
int isStackFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}
int isStackEmpty(struct Stack* stack) {
    return stack->top == -1;
}
void push(struct Stack* stack, int item) {
    if (isStackFull(stack))
        return;
    stack->array[++stack->top] = item;
}
int pop(struct Stack* stack) {
    if (isStackEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
void reverseQueue(struct Queue* queue) {
    struct Stack* stack = createStack(queue->capacity);
    while (!isEmpty(queue)) {
        push(stack, dequeue(queue));
    }
    while (!isStackEmpty(stack)) {
        enqueue(queue, pop(stack));
    }
}
void printQueue(struct Queue* queue) {
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->array[i]);
        i = (i + 1) % queue->capacity;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue(100);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    printf("Original Queue: ");
    printQueue(queue);
    reverseQueue(queue);
    printf("Reversed Queue: ");
    printQueue(queue);
    return 0;
}


