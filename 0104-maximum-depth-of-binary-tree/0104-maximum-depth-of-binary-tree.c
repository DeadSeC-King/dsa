int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    
    // Return the maximum of left and right depth + 1 for current node
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}