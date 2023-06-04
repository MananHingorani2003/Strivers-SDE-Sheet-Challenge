void preorder(BinaryTreeNode<int> *root, vector<int> &res){
    
    if(root == NULL){
        return;
    }
    res.push_back(root->data);
    preorder(root->left, res);
    preorder(root->right, res);
}

void inorder(BinaryTreeNode<int> *root, vector<int> &res){
    
    if(root == NULL){
        return;
    }
    
    inorder(root->left, res);
    res.push_back(root->data);
    inorder(root->right, res);
}
void postorder(BinaryTreeNode<int> *root, vector<int> &res){
    
    if(root == NULL){
        return;
    }
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> res;
    vector<int> res1, res2, res3;
    
    inorder(root, res1);
    preorder(root, res2);
    postorder(root, res3);
    
    res.push_back(res1);
    res.push_back(res2);
    res.push_back(res3);

    return res;
}
