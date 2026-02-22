// Stack implementation using array
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];
int top = -1;

// PUSH
void push_kushagra() {
    int x;
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter number to push: ");
    scanf("%d", &x);

    arr[++top] = x;
    printf("%d pushed into stack\n", x);
}

// POP
int pop_kushagra() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }

    int value = arr[top--];
    return value;
}

// PEEK
int peek_kushagra() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return -1;
    }

    return arr[top];
}

// DISPLAY
void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements (top → bottom):\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", arr[i]);
    }
}

// MAIN
int main() {
    int n, value;

    while (1) {
        printf("\n--- STACK MENU ---\n");
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