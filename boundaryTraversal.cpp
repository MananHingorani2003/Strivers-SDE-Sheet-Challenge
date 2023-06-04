void leftBoundary(TreeNode<int>* root, vector<int>& ans){
    if((root == NULL) || (root->left == NULL && root->right == NULL)) return;
    ans.push_back(root->data);
    if(root->left != NULL)
        leftBoundary(root->left, ans);
    else
        leftBoundary(root->right, ans);
}

void leafNode(TreeNode<int>* root, vector<int>& ans){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }
    if(root->left != NULL)
        leafNode(root->left, ans);
    if(root->right != NULL)
        leafNode(root->right, ans);
}

void rightBoundary(TreeNode<int>* root, vector<int>& ans){
    if((root == NULL) || (root->left == NULL && root->right == NULL)) return;

    if(root->right != NULL)
        rightBoundary(root->right, ans);
    else
        rightBoundary(root->left, ans);

    ans.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int>* root){

    vector<int> ans;
    if(root == NULL) return ans;
    
    // Caase 0: add root seperatly.
    ans.push_back(root->data);
    if(root->left == NULL && root->right == NULL) return ans;

    // Case 1:
    leftBoundary(root->left, ans);

    // Case 2:
    leafNode(root, ans);

    // Case 3:
    vector<int> temp;
    rightBoundary(root->right, ans);

    return ans;
}
