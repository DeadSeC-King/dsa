/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void preorder(struct TreeNode* root, int* result, int* index){
    if(root == NULL) return;

    result[*index] = root->val;
    (*index)++;

    preorder(root->left, result, index);
    preorder(root->right, result, index);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {

    int* result = (int*)malloc(sizeof(int) * 100); // assume max nodes 100
    *returnSize = 0;

    preorder(root, result, returnSize);

    return result;
}