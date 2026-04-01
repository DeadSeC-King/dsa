//Check whether a given binary tree satisfies the Min-Heap property.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int isComplete(struct Node* root, int index, int totalNodes) {
    if (root == NULL)
        return 1;
    if (index >= totalNodes)
        return 0;
    return isComplete(root->left, 2 * index + 1, totalNodes) &&
           isComplete(root->right, 2 * index + 2, totalNodes);
}
int isMinHeap(struct Node* root) {
    int totalNodes = countNodes(root);
    if (!isComplete(root, 0, totalNodes))
        return 0;
    return isMinHeapUtil(root);
}
int isMinHeapUtil(struct Node* root) {
    if (root == NULL)
        return 1;
    if (root->left != NULL && root->data > root->left->data)
        return 0;
    if (root->right != NULL && root->data > root->right->data)
        return 0;
    return isMinHeapUtil(root->left) && isMinHeapUtil(root->right);
}
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    if (isMinHeap(root))
        printf("The binary tree satisfies the Min-Heap property.\n");
    else
        printf("The binary tree does not satisfy the Min-Heap property.\n");
    return 0;
}
