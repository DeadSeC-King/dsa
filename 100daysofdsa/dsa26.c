//Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation
#include <stdio.h>
#include <stdlib.h>
int main() {
    struct Node {
        int data;
        struct Node* next;
        struct Node* prev;
    };
    
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // Allocate memory for nodes
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Initialize nodes
    head->data = 1;
    head->next = second;
    head->prev = NULL;

    second->data = 2;
    second->next = third;
    second->prev = head;

    third->data = 3;
    third->next = NULL;
    third->prev = second;

    // Traversal
    struct Node* current = head;
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    
    // Free allocated memory
    free(head);
    free(second);
    free(third);

    return 0;
}