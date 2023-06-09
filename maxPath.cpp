int helper (TreeNode<int> *root, int &maxi) {
    if (root == nullptr) return 0;
    int leftSum = max (0, helper (root->left, maxi));
    int rightSum = max (0, helper (root->right, maxi));

    maxi = max (maxi, leftSum+rightSum+root->val);

    return root->val+max(leftSum, rightSum);


}

long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if (root == nullptr) return -1;
    int maxi = INT_MIN;
    int a = helper (root, maxi);
    if(root->left==NULL||root->right==NULL)return -1;
    return maxi;

}
