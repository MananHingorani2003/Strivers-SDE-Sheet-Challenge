vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    if (root == nullptr) return {};
        queue<pair< BinaryTreeNode<int> *,int>> mahi;
        map <int, int> map;
        mahi.push ({root, 0});
        vector <int> final;
        
        while (!mahi.empty()) {
            BinaryTreeNode<int> *curr = mahi.front().first;
            int currLevel = mahi.front().second;
            mahi.pop();
            
            map [currLevel] = curr->data;
            if (curr -> left) mahi.push ({curr->left, currLevel-1});
            if (curr -> right) mahi.push ({curr->right, currLevel+1});
        }
        
        for (auto x: map) {
            final.push_back (x.second);
        }
        
        return final;
    
}
