//Implement push and pop operations on a stack and verify stack operations.
#include <stdio.h>
#define MAX 100
struct Stack {
    int items[MAX];
    int top;
};
void initStack(struct Stack* s) {
    s->top = -1;
}
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}
int isEmpty(struct Stack* s) {
    return s->top == -1;
}
void push(struct Stack* s, int item) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++s->top] = item;
}
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1; // Return -1 to indicate stack is empty
    }
    return s->items[s->top--];
}
int main() {
    struct Stack s;
    initStack(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printf("Popped item: %d\n", pop(&s)); // Should print 30
    printf("Popped item: %d\n", pop(&s)); // Should print 20
    printf("Popped item: %d\n", pop(&s)); // Should print 10
    printf("Popped item: %d\n", pop(&s)); // Should indicate stack is empty
    return 0;
}