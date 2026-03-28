#include <stdlib.h>

// Queue structure
struct Queue {
    struct TreeNode* node;
    struct Queue* next;
};

// Enqueue
void enqueue(struct Queue** front, struct Queue** rear, struct TreeNode* node) {
    struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->node = node;
    temp->next = NULL;

    if (*rear == NULL) {
        *front = *rear = temp;
        return;
    }
    (*rear)->next = temp;
    *rear = temp;
}

// Dequeue
struct TreeNode* dequeue(struct Queue** front, struct Queue** rear) {
    if (*front == NULL) return NULL;

    struct Queue* temp = *front;
    struct TreeNode* node = temp->node;

    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;

    free(temp);
    return node;
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*)malloc(1000 * sizeof(int)); // safe size
    int index = 0;

    struct Queue *front = NULL, *rear = NULL;
    enqueue(&front, &rear, root);

    while (front != NULL) {
        int size = 0;
        struct Queue* temp = front;

        // count nodes in current level
        while (temp) {
            size++;
            temp = temp->next;
        }

        for (int i = 0; i < size; i++) {
            struct TreeNode* curr = dequeue(&front, &rear);

            // last node of level → right view
            if (i == size - 1) {
                result[index++] = curr->val;
            }

            if (curr->left) enqueue(&front, &rear, curr->left);
            if (curr->right) enqueue(&front, &rear, curr->right);
        }
    }

    *returnSize = index;
    return result;
}