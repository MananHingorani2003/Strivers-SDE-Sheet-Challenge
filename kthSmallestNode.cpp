int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    int ans = -1;
    TreeNode <int> *curr = root;
    while (curr) {
        if (curr -> left == NULL) {
            k--;
            if (k==0) {
                ans = curr -> data;
            }
            curr = curr -> right;
        }
        else {
            TreeNode <int> *prev = curr -> left;
            while (prev -> right && prev -> right != curr) prev = prev -> right;

            if (prev -> right == NULL) {
                prev -> right = curr;
                curr = curr -> left;
            }
            else {
                
                k--;
                if (k==0) {
                    ans = curr -> data;
                }
                prev -> right = NULL;
                curr = curr->right;
            }
        }
    }
    return ans;

    

}
