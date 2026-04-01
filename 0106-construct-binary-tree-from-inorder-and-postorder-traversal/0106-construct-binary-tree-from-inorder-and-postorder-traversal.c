#include <stdlib.h>

// helper function to find index in inorder
int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

struct TreeNode* helper(int* inorder, int* postorder, int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd)
        return NULL;

    // create root
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[*postIndex];
    (*postIndex)--;

    // if only one node
    if (inStart == inEnd) {
        root->left = root->right = NULL;
        return root;
    }

    int inIndex = findIndex(inorder, inStart, inEnd, root->val);

    // build RIGHT first
    root->right = helper(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left = helper(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int postIndex = postorderSize - 1;
    return helper(inorder, postorder, 0, inorderSize - 1, &postIndex);
}