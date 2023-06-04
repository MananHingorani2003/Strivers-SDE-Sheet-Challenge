int maxDepth(BinaryTreeNode<int>* root) {
        if (root == nullptr) {
            return 0;
        }
        int height1 = maxDepth (root -> left);
        int height2 = maxDepth (root -> right);

        return 1+max(height1, height2);
        
    }


bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    if (root == nullptr) return true;

    int leftHeight = maxDepth (root -> left);
    int rightHeight = maxDepth (root -> right);

    return abs(leftHeight-rightHeight)<=1 && isBalancedBT (root->left) && isBalancedBT (root->right);
}
