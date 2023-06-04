vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    if (root == nullptr) return {};
        stack <TreeNode *> mahi;
        vector <int> final;
        mahi.push (root);

        while (!mahi.empty()) {
            TreeNode *curr = mahi.top();
            mahi.pop();
            


            final.push_back (curr -> data);

            if (curr -> right) mahi.push (curr -> right);
            if (curr -> left) mahi.push (curr -> left);
        }

        return final;

}
