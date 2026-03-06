//Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *top = NULL;
void push(int value) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}
int pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        return -1; // Return -1 to indicate stack is empty
    }
    struct node *temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
int evaluatePostfix(char* expression) {
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        if (ch >= '0' && ch <= '9') {
            push(ch - '0'); // Convert char to int
        } else if (isOperator(ch)) {
            int val2 = pop();
            int val1 = pop();
            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop(); // The final result will be on top of the stack
}
int main() {
    char expression[] = "231*+9-";
    int result = evaluatePostfix(expression);
    printf("Result of postfix expression '%s' is: %d\n", expression, result); // Should print -4
    return 0;
}
