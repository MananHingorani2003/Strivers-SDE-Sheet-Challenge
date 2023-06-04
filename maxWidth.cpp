int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if (root == nullptr) return {};
        vector <vector <int>> final;
        vector <int> temp;
        TreeNode<int> *curr = root;
        queue <TreeNode<int> *> mahi;

        mahi.push (root);
        mahi.push (NULL);
        int maxi = INT_MIN;

        while (true) { 
            TreeNode<int> *top = mahi.front();
            mahi.pop();
            if (top) temp.push_back (top -> val);
            
            if (top==NULL) {
                final.push_back (temp);
                int a = temp.size();
                maxi = max (maxi, a);
                temp.clear();
                if (mahi.size()==0) break;
                mahi.push (NULL);
            } else {
              if (top->left)
                mahi.push(top->left);
              if (top->right)
                mahi.push(top->right);
            }
        }

        return maxi;
}
