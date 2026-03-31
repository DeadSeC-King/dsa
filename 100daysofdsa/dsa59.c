//Construct a binary tree from given inorder and postorder traversal arrays.
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
// Function to construct binary tree from inorder and postorder arrays
struct Node* buildTree(int inorder[], int postorder[], int start, int end) {
    static int postIndex = 0;
    if (start > end)
        return NULL;
    // Create a new node with the current value in postorder
    struct Node* node = newNode(postorder[postIndex++]);
    // If the node has no children, return it
    if (start == end)
        return node;
    // Find the index of this node in inorder array
    int inIndex = search(inorder, start, end, node->data);
    // Recursively construct the right and left subtrees
    node->right = buildTree(inorder, postorder, inIndex + 1, end);
    node->left = buildTree(inorder, postorder, start, inIndex - 1);
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
    int inorder[] = {4, 2, 5, 1, 3};
    int postorder[] = {4, 5, 2, 3, 1};
    int length = sizeof(inorder) / sizeof(inorder[0]);
    struct Node* root = buildTree(inorder, postorder, 0, length - 1);
    printf("Inorder traversal of the constructed tree is: ");
    printInorder(root);
    return 0;
}
