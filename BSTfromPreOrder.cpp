TreeNode <int> *buildTree (vector<int> &inorder, int inStart, int inEnd, vector<int> &preorder, int preStart, int preEnd, unordered_map <int, int> &inMap) {
    TreeNode <int> *root = new TreeNode <int> (preorder[preStart]);

    if (preStart>preEnd || inStart>inEnd) return NULL;

    int inRoot = inMap [root->data];
    int numsLeft = inRoot - inStart;

    root -> left = buildTree(inorder, inStart, inRoot-1, preorder, preStart+1, preStart+numsLeft, inMap);
    root -> right = buildTree(inorder, inRoot+1, inEnd, preorder, preStart+numsLeft+1, preEnd, inMap);

    return root;
}


TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    int n = inorder.size();
    unordered_map <int, int> inMap;
    for (int i=0; i<n; i++) inMap [inorder[i]] = i;
    return buildTree (inorder, 0, n-1, preorder, 0, n-1, inMap);
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    vector <int> inOrder;
    for (int i=0; i<preOrder.size(); i++) inOrder.push_back (preOrder[i]);

    sort (inOrder.begin(), inOrder.end());
    return buildBinaryTree(inOrder, preOrder);
}
