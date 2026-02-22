// Stack implementation using Linked List
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// PUSH
void push_kushagra() {
    int x;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Heap Overflow\n");
        return;
    }

    printf("Enter number to push: ");
    scanf("%d", &x);

    newNode->data = x;
    newNode->next = top;
    top = newNode;

    printf("%d pushed into stack\n", x);
}

// POP
int pop_kushagra() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }

    struct Node* temp = top;
    int value = temp->data;

    top = top->next;
    free(temp);

    return value;
}

// PEEK
int peek_kushagra() {
    if (top == NULL) {
        printf("Stack is Empty\n");
        return -1;
    }

    return top->data;
}

// DISPLAY
void display() {
    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack elements (top → bottom):\n");

    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// MAIN
int main() {
    int n, value;

    while (1) {
        printf("\n--- STACK MENU (Linked List) ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &n) != 1) {
            printf("Invalid input\n");
            exit(1);
        }

        switch (n) {
            case 1:
                push_kushagra();
                break;

            case 2:
                value = pop_kushagra();
                if (value != -1)
                    printf("Popped: %d\n", value);
                break;

            case 3:
                value = peek_kushagra();
                if (value != -1)
                    printf("Top element: %d\n", value);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}