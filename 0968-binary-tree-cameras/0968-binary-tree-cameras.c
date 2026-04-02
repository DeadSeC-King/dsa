int cameras;

// DFS function to determine state of each node
int dfs(struct TreeNode* root) {
    if (!root) return 1;  // NULL nodes are covered

    int left = dfs(root->left);
    int right = dfs(root->right);

    // If any child is not covered → place camera here
    if (left == -1 || right == -1) {
        cameras++;
        return 0; // node has camera
    }

    // If any child has camera → this node is covered
    if (left == 0 || right == 0) {
        return 1; // covered
    }

    // Otherwise → not covered
    return -1;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;  // 🔥 reset for each test case

    // If root is not covered, place a camera
    if (dfs(root) == -1) {
        cameras++;
    }

    return cameras;
}