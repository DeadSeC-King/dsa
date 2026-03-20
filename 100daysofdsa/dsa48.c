//Count Leaf Nodes
#include <stdio.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0; // No nodes, so return 0
    }
    
    if (root->left == NULL && root->right == NULL) {
        return 1; // This is a leaf node
    }
    
    // Recursively count leaf nodes in left and right subtrees
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int main() {
    // Create a sample binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    
    // Count leaf nodes
    int leafCount = countLeafNodes(root);
    printf("Number of leaf nodes: %d\n", leafCount);
    
    return 0;
}
