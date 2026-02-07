#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

/* Insert at Beginning */
void insertAtBeginning(int data) {

    struct Node* newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = data;
    newNode->next = head;
    head = newNode;
}
/* Insert at End */
void insertAtEnd(int data) {

    struct Node* newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

/* Insert at Position */
void insertAtPosition(int data, int pos) {

    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = data;

    struct Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

/* Delete at Start */
void deleteAtStart() {

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

/* Delete at End */
void deleteAtEnd() {

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

/* Delete at Position */
void deleteAtPosition(int pos) {

    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 1) {
        deleteAtStart();
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

/* Display */
void display() {

    struct Node* temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    // Initial Liked List 
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);

    int choice, data, pos;

    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("Enter choice: ");

    scanf("%d", &choice);

    if (choice == 1) {

        printf("1. Beginning\n2. End\n3. Position\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        printf("Enter data: ");
        scanf("%d", &data);

        if (choice == 1)
            insertAtBeginning(data);

        else if (choice == 2)
            insertAtEnd(data);

        else if (choice == 3) {
            printf("Enter position: ");
            scanf("%d", &pos);
            insertAtPosition(data, pos);
        }

        else
            printf("Invalid choice\n");
    }

    else if (choice == 2) {

        printf("1. Start\n2. End\n3. Position\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        if (choice == 1)
            deleteAtStart();

        else if (choice == 2)
            deleteAtEnd();

        else if (choice == 3) {
            printf("Enter position: ");
            scanf("%d", &pos);
            deleteAtPosition(pos);
        }

        else
            printf("Invalid choice\n");
    }

    else {
        printf("Invalid choice\n");
    }

    display();

    return 0;
}
