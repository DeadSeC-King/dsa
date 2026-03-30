//Construct a binary tree from given preorder and inorder traversal array
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
// Function to find the index of value in inorder array
int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1; // Not found
}
// Function to construct binary tree from preorder and inorder arrays
struct Node* buildTree(int preorder[], int inorder[], int start, int end) {
    static int preIndex = 0;
    if (start > end)
        return NULL;
    // Create a new node with the current value in preorder
    struct Node* node = newNode(preorder[preIndex++]);
    // If the node has no children, return it
    if (start == end)
        return node;
    // Find the index of this node in inorder array
    int inIndex = search(inorder, start, end, node->data);
    // Recursively construct the left and right subtrees
    node->left = buildTree(preorder, inorder, start, inIndex - 1);
    node->right = buildTree(preorder, inorder, inIndex + 1, end);
    return node;
}
// Function to print inorder traversal of the tree
void printInorder(struct Node* node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
int main() {
    int preorder[] = {1, 2, 4, 5, 3};
    int inorder[] = {4, 2, 5, 1, 3};
    int length = sizeof(preorder) / sizeof(preorder[0]);
    struct Node* root = buildTree(preorder, inorder, 0, length - 1);
    printf("Inorder traversal of the constructed tree is: ");
    printInorder(root);
    return 0;
}
