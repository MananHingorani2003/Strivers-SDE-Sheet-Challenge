#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
bool invert(TreeNode<int> *root, TreeNode<int> *parent, TreeNode<int> *leaf) {
    if (!root) return false;

    if (root->data == leaf->data) {
        leaf->left = parent;
        return true;
    }

    if (invert(root->right, root, leaf)) {
        root->right = NULL;
        if (root->left) {
            TreeNode<int> *newNode = root->left;
            root->right = newNode;
        }
        root->left = parent;
        return true;
    } else if (invert(root->left, root, leaf)) {
        root->left = parent;
        return true;
    }

    return false;
}

TreeNode<int> *invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf) {
    bool solve = invert(root, NULL, leaf);
    return leaf;
}
