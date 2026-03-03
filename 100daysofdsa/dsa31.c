//: Implement a stack data structure using an array with the following operations: push, pop, and display.
#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
// push operation
void push(int val) {
    if (top >= MAX - 1) {
        printf("Stack overflow! Cannot push %d\n", val);
        return;
    }
    stack[++top] = val;
    printf("Pushed: %d\n", val);
}
// pop operation
void pop() {
    if (top < 0) {
        printf("Stack underflow! Cannot pop from an empty stack\n");
        return;
    }
    printf("Popped: %d\n", stack[top--]);
}
// display operation
void display() {
    if (top < 0) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    pop();
    pop();
    pop(); // This will show stack underflow
    return 0;
}