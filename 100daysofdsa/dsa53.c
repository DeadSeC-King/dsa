//Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void verticalOrder(struct Node* root, int hd, int* minHd, int* maxHd) {
    if (root == NULL) {
        return;
    }
    if (hd < *minHd) {
        *minHd = hd;
    }
    if (hd > *maxHd) {
        *maxHd = hd;
    }
    verticalOrder(root->left, hd - 1, minHd, maxHd);
    verticalOrder(root->right, hd + 1, minHd, maxHd);
}
void printVerticalOrder(struct Node* root) {
    int minHd = 0, maxHd = 0;
    verticalOrder(root, 0, &minHd, &maxHd);
    for (int hd = minHd; hd <= maxHd; hd++) {
        printVerticalLine(root, hd, 0);
        printf("\n");
    }
}
void printVerticalLine(struct Node* root, int hd, int currentHd) {
    if (root == NULL) {
        return;
    }
    if (currentHd == hd) {
        printf("%d ", root->data);
    }
    printVerticalLine(root->left, hd, currentHd - 1);
    printVerticalLine(root->right, hd, currentHd + 1);
}
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    printf("Vertical Order Traversal:\n");
    printVerticalOrder(root);
    return 0;
}
