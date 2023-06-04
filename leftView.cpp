vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    if (root == nullptr) {
            return {};
        }
        vector <int> toReturn;
        queue<TreeNode<int>*>q ; 
        vector< vector<int> > ans ;
        vector<int>help;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            TreeNode<int>* curr = q.front() ;
            q.pop() ; 
            
            if(curr==nullptr){
                ans.push_back(help) ; 
                help.clear() ; 
                if(!q.empty()){
                    q.push(nullptr) ; 
                }
            }
            else{
                help.push_back(curr->data);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            
        }

        for (int i=0; i<ans.size(); i++) {
            toReturn.push_back (ans[i][0]);
        }
        return toReturn;
}
