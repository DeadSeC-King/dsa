 //Count Nodes in Linked List
#include <stdio.h>
#include <stdlib.h>
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}
struct Node {
    int data;
    struct Node* next;
};
