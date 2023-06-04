int helper (TreeNode<int> *root, int &diameter) {
    if (root == nullptr) return 0;
    int lh = helper (root -> left, diameter);
    int lr = helper (root -> right, diameter);

    diameter = max (diameter, lh+lr);
    return 1+max (lh, lr);
}


int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    int diameter = 0;
    int a = helper (root, diameter);
    return diameter;
}
