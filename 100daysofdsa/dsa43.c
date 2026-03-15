//Construct a Binary Tree from the given level-order traversal.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
struct Queue {
    int front, rear, capacity;
    struct Node** array;
};
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = 0;
    queue->array = (struct Node**)malloc(queue->capacity * sizeof(struct Node*));
    return queue;
}
int isFull(struct Queue* queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}
int isEmpty(struct Queue* queue) {
    return queue->front == queue->rear;
}
void enqueue(struct Queue* queue, struct Node* item) {
    if (isFull(queue))
        return;
    queue->array[queue->rear] = item;
    queue->rear = (queue->rear + 1) % queue->capacity;
}
struct Node* dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return NULL;
    struct Node* item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    return item;
}