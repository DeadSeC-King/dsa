#include <stdlib.h>

// Queue structure
struct Queue {
    struct TreeNode** data;
    int front, rear, size, capacity;
};

struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = 0;
    q->size = 0;
    q->rear = capacity - 1;
    q->data = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    return q;
}

int isEmpty(struct Queue* q) {
    return q->size == 0;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = node;
    q->size++;
}

struct TreeNode* dequeue(struct Queue* q) {
    struct TreeNode* node = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return node;
}

// MAIN FUNCTION
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int capacity = 2000; // max nodes
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    struct Queue* q = createQueue(capacity);
    enqueue(q, root);

    int level = 0;

    while (!isEmpty(q)) {
        int size = q->size;

        result[level] = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[level] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue(q);

            result[level][i] = node->val;

            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }

        level++;
    }

    *returnSize = level;
    return result;
}