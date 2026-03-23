//lowest commmon ancestor of bst
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

struct Node* lca(struct Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }
    
    if (root->data > n1 && root->data > n2) {
        return lca(root->left, n1, n2);
    }
    
    if (root->data < n1 && root->data < n2) {
        return lca(root->right, n1, n2);
    }
    
    return root;
}

int main() {
    struct Node* root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(30);
    root->left->left = newNode(5);
    root->left->right = newNode(15);
    
    int n1 = 5, n2 = 15;
    struct Node* ancestor = lca(root, n1, n2);
    
    if (ancestor != NULL) {
        printf("Lowest Common Ancestor of %d and %d is: %d\n", n1, n2, ancestor->data);
    } else {
        printf("Lowest Common Ancestor does not exist.\n");
    }
    
    return 0;
}