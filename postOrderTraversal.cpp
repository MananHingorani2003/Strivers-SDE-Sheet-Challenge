vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    if (root == nullptr) return {};
        stack <TreeNode *> mahi;
        vector <int> final;
        stack <TreeNode *> mahi2;
        mahi.push (root);

        while (!mahi.empty()) {
            TreeNode *curr = mahi.top();
            mahi.pop();
            mahi2.push (curr);

            if (curr -> left) mahi.push(curr->left);
            if (curr -> right) mahi.push(curr->right);
        }

        while (!mahi2.empty()) {
            TreeNode *curr = mahi2.top();
            mahi2.pop();
            final.push_back (curr->data);
        }

        return final;
}
