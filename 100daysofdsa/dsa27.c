//Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
int count(struct Node* head) {
    int c = 0;
    while (head != NULL) {
        c++;
        head = head->next;
    }
    return c;
}
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
