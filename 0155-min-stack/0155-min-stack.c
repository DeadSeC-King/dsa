#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

typedef struct {
    int val;
    int min;
} Node;

typedef struct {
    Node* data;
    int top_idx;
} MinStack;

/** Initialize the stack object */
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->data = (Node*)malloc(MAX_SIZE * sizeof(Node));
    obj->top_idx = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->top_idx++;
    obj->data[obj->top_idx].val = val;
    
    // If it's the first element, it's the minimum.
    // Otherwise, compare val with the minimum of the element below it.
    if (obj->top_idx == 0) {
        obj->data[obj->top_idx].min = val;
    } else {
        int current_min = obj->data[obj->top_idx - 1].min;
        obj->data[obj->top_idx].min = (val < current_min) ? val : current_min;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top_idx >= 0) {
        obj->top_idx--;
    }
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->top_idx].val;
}

int minStackGetMin(MinStack* obj) {
    return obj->data[obj->top_idx].min;
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj);
}