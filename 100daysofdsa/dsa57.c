#include <stdio.h>
#include <stdlib.h>

// Definition of tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
// Function to convert tree to its mirror
void mirror(struct Node* root) {
    if (root == NULL)
        return;
    // Swap left and right
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    // Recur for subtrees
    mirror(root->left);
    mirror(root->right);
}