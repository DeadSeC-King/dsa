//. Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || k == 0) {
        return head;
    }
    struct Node* temp = head;
    int length = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }
    temp->next = head; // Make it circular
    k = k % length; // Handle cases where k >= length
    for (int i = 0; i < length - k; i++) {
        temp = temp->next;
    }
    head = temp->next; // New head after rotation
    temp->next = NULL; // Break the circular link
    return head;
}