//Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.
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
void traverse(struct Node* head) {
    if (head == NULL) {
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}
int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = head; // Making it circular
    printf("Circular Linked List: ");
    traverse(head);
    return 0;
}
