//Approach1:

void flatten (TreeNode<int> *root, TreeNode <int> *&prev) {
    if (root == nullptr) return;

    flatten (root -> right, prev);
    flatten (root -> left, prev);

    root -> right = prev;
    root -> left = NULL;
    prev = root;
}


TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    TreeNode <int> *prev = NULL;
    flatten (root, prev);

    return root;
}

//Approach 2 (Morris):
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode <int> *curr = root;
    while (curr != NULL) {
        if (curr -> left) {
            TreeNode <int> *prev = curr -> left;
            while (prev -> right) prev = prev -> right;
            prev -> right = curr -> right;
            curr -> right = curr -> left;
        }

        curr = curr -> right;
    }

    return root;
}
