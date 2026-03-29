void flatten(struct TreeNode* root) {
    struct TreeNode* curr = root;

    while (curr != NULL) {
        if (curr->left != NULL) {
            // Find rightmost node of left subtree
            struct TreeNode* temp = curr->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }

            // Attach original right subtree
            temp->right = curr->right;

            // Move left subtree to right
            curr->right = curr->left;
            curr->left = NULL;
        }

        // Move to next node
        curr = curr->right;
    }
}