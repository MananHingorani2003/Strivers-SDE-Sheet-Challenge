TreeNode <int> *solve (int left, int right, vector<int> &arr, int n) {
    if (left > right) return NULL;
    int mid = left + (right-left)/2;

    TreeNode <int> *root = new TreeNode <int> (arr[mid]);

    root -> left = solve (left, mid-1, arr, n);
    root -> right = solve (mid+1, right, arr, n);

    return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return solve (0, n-1, arr, n);
}
