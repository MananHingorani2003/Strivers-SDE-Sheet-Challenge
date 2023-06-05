void flooring  (TreeNode<int> * root, int X, int &greatest) {
    if (root == nullptr) return;
    if (X == root -> val) {
        greatest = X;
        return;
    }
    if (X > root -> val) {
        greatest = max (greatest, root -> val);
        flooring (root -> right, X, greatest);
    }
    else {
        flooring (root -> left, X, greatest);
    }
    
}

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int greatest = INT_MIN;
    flooring (root, X, greatest);

    return greatest;
    
}
