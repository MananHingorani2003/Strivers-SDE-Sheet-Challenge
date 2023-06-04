vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector <vector <int>> final;
        vector <int> temp;
        TreeNode *curr = root;
        queue <TreeNode *> mahi;

        mahi.push (root);
        mahi.push (NULL);

        while (true) { 
            TreeNode *top = mahi.front();
            mahi.pop();
            if (top) temp.push_back (top -> val);
            
            if (top==NULL) {
                final.push_back (temp);
                temp.clear();
                if (mahi.size()==0) break;
                mahi.push (NULL);
            }
            else {
                if (top -> left) mahi.push (top -> left);
                if (top -> right) mahi.push (top -> right);
            }

        }

        return final;

    }
