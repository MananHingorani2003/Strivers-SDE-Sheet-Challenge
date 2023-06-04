bool solve(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }

    if(root1->data != root2->data){
        return false;
    }

    bool ans1 = solve(root1->left, root2->right);
    bool ans2 = solve(root1->right, root2->left);

    return ans1&&ans2;
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(root == NULL){
        return -1;
    }
    return solve(root->left, root->right);
}
