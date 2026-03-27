//Print the nodes visible when the binary tree is viewed from the right side.
#include <stdio.h>
#include <stdlib.h>

// Tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue node
struct Queue {
    struct Node* treeNode;
    struct Queue* next;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Enqueue
void enqueue(struct Queue** front, struct Queue** rear, struct Node* node) {
    struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->treeNode = node;
    temp->next = NULL;

    if (*rear == NULL) {
        *front = *rear = temp;
        return;
    }
    (*rear)->next = temp;
    *rear = temp;
}

// Dequeue
struct Node* dequeue(struct Queue** front, struct Queue** rear) {
    if (*front == NULL) return NULL;

    struct Queue* temp = *front;
    struct Node* node = temp->treeNode;

    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;

    free(temp);
    return node;
}

// Right view function
void rightView(struct Node* root) {
    if (root == NULL) return;

    struct Queue *front = NULL, *rear = NULL;
    enqueue(&front, &rear, root);

    while (front != NULL) {
        int size = 0;
        struct Queue* temp = front;

        // Count nodes at current level
        while (temp) {
            size++;
            temp = temp->next;
        }

        for (int i = 0; i < size; i++) {
            struct Node* curr = dequeue(&front, &rear);

            // Print last node of level
            if (i == size - 1)
                printf("%d ", curr->data);

            if (curr->left)
                enqueue(&front, &rear, curr->left);
            if (curr->right)
                enqueue(&front, &rear, curr->right);
        }
    }
}