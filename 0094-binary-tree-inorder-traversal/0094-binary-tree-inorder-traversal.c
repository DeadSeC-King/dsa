/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorder(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) return;

    inorder(root->left, arr, index);
    arr[*index] = root->val;
    (*index)++;
    inorder(root->right, arr, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(sizeof(int) * 100); // assuming max nodes <=100
    *returnSize = 0;

    inorder(root, arr, returnSize);

    return arr;
}