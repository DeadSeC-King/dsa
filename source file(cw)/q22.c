#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode =malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void inorder(struct Node* root) {
    if (root == NULL) return;

    display(root->left);        
    printf("%d ", root->data);  
    display(root->right);       
}

void preorder(struct Node* root) {
    if (root == NULL) return;
        
    printf("%d ", root->data);  
    display(root->left);  
    display(root->right);       
}
void preorder(struct Node* root) {
    if (root == NULL) return;
    
    display(root->left);  
    display(root->right);   
    printf("%d ", root->data);     
}

int main() {
    struct Node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);
    display(root);

    return 0;
}

