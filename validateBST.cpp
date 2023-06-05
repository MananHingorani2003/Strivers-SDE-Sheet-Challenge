bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    if (root == nullptr) return true;

    if (root -> left) {
        if (root -> left -> data > root -> data) return false;
        if (!validateBST(root -> left)) return false;
    } 

    if (root -> right) {
        if (root -> right -> data < root -> data) return false;
        if (!validateBST(root -> right)) return false;
    }

    return true;
    
}
