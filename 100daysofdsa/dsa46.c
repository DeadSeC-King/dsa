//Level Order Traversal
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void levelOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct Node* currentNode = queue[front++];
        printf("%d ", currentNode->data);
        if (currentNode->left != NULL) {
            queue[rear++] = currentNode->left;
        }
        if (currentNode->right != NULL) {
            queue[rear++] = currentNode->right;
        }
    }
}
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    return 0;
}
