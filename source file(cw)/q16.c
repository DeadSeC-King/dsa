//insert n delete in doubly linked list at given position

#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head = NULL;

// Count nodes
int countNodes() {
    int count = 0;
    struct node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Insert at position
void insertPosition(int value, int pos) {
    int count = countNodes();

    if (pos < 1 || pos > count + 1) {
        printf("Invalid Position\n");
        return;
    }

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    // Insert at beginning
    if (pos == 1) {
        newnode->next = head;
        if (head != NULL)
            head->prev = newnode;
        head = newnode;
        return;
    }

    struct node* temp = head;

    // Traverse to (pos-1)th node
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    // Insert at end
    if (temp->next == NULL) {
        temp->next = newnode;
        newnode->prev = temp;
        return;
    }

    // Insert in middle
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
}

// Delete at position
void deletePosition(int pos) {
    int count = countNodes();

    if (pos < 1 || pos > count) {
        printf("Invalid Position\n");
        return;
    }

    struct node* temp = head;

    // Delete at beginning
    if (pos == 1) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return;
    }

    // Traverse to pos
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }

    // Delete at end
    if (temp->next == NULL) {
        temp->prev->next = NULL;
        free(temp);
        return;
    }

    // Delete in middle
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

// Display
void display() {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insertPosition(10,1);
    insertPosition(20,2);
    insertPosition(30,3);
    insertPosition(15,2);

    printf("After Insertions:\n");
    display();
    deletePosition(1);
    deletePosition(3);

    printf("After Deletions:\n");
    display();

    return 0;
}