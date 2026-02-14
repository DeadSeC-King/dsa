// 15. Write a C program to implement circular linked list with the following operations:
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;
void insertStart(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if(head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node* temp = head;
    while(temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}
void insertEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if(head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node* temp = head;
    while(temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}
void insertPosition(int value, int pos) {
    if(pos == 1) {
        insertStart(value);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* temp = head;
    for(int i = 1; i < pos-1 && temp->next != head; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteStart() {
    if(head == NULL)
        return;

    if(head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    struct Node* last = head;

    while(last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;

    free(temp);
}
void deleteEnd() {
    if(head == NULL)
        return;

    if(head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while(temp->next->next != head)
        temp = temp->next;

    struct Node* last = temp->next;
    temp->next = head;
    free(last);
}
void deletePosition(int pos) {
    if(pos == 1) {
        deleteStart();
        return;
    }

    struct Node* temp = head;
    for(int i = 1; i < pos-1 && temp->next != head; i++)
        temp = temp->next;

    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}
void display() {
    if(head == NULL)
        return;

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("\n");
}
int main() {
    int choice, value, pos;

    while(1) {
        printf("\n----- Circular Linked List -----\n");
        printf("1. Insert at Start\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Start\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertStart(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertPosition(value, pos);
                break;

            case 4:
                deleteStart();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePosition(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
