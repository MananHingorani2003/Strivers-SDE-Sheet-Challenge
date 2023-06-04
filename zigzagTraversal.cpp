vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    if (root==nullptr) return {};
        vector <vector <int>> final;
        vector <int> help;
        queue <BinaryTreeNode<int> *> mahi;
        mahi.push (root);
        mahi.push (nullptr);
        bool flag = 1;

        while (!mahi.empty()) {
            BinaryTreeNode<int> *curr=mahi.front();
            mahi.pop();

            if (curr==nullptr) {
                flag = !flag;
                if (flag==0) {
                    final.push_back (help);
                }
                else {
                    reverse (help.begin(), help.end());
                    final.push_back (help);               
                }
                help.clear();
                if(!mahi.empty()){
                    mahi.push(nullptr) ;
                }
                continue;
            }
            help.push_back (curr -> data);
            if (curr->left) mahi.push (curr->left);
            if (curr->right) mahi.push (curr->right);

        }
        vector <int> final2;

        for (int i=0; i<final.size(); i++) {
            for (int j=0; j<final[i].size(); j++) {
                final2.push_back (final[i][j]);
            }
        }

        return final2;
}
