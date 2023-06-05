void ceiling(BinaryTreeNode<int> *root, int X, int &least) {
    if (root == nullptr)
        return;

    if (X == root->data) {
        least = X;
        return;
    }

    if (X < root->data) {
        least = min(least, root->data);
        ceiling(root->left, X, least);
    } else {
        ceiling(root->right, X, least);
    }
}

int findCeil(BinaryTreeNode<int> *root, int X) {
    int least = INT_MAX;
    ceiling(root, X, least);
    if (least == INT_MAX) return -1;
    return least;
}
