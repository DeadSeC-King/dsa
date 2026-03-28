//Check whether a given binary tree is symmetric around its center.
#include <stdbool.h>
#include <stdlib.h>

// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to check mirror
bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    // Both NULL → symmetric
    if (t1 == NULL && t2 == NULL)
        return true;

    // One NULL → not symmetric
    if (t1 == NULL || t2 == NULL)
        return false;

    // Check values + mirror structure
    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

// Main function
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;

    return isMirror(root->left, root->right);
}