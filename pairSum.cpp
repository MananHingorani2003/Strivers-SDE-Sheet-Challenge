bool dfs(BinaryTreeNode<int>* root, int target, unordered_map<int,int>& mp) {
        if(root == nullptr) return false;
        if(mp.find(target - root->data) != mp.end()) return true;
        
        mp[root->data] ++;

        return  dfs(root->left, target, mp) || dfs(root->right, target, mp);
    }

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    if(root == nullptr) return false;
    unordered_map<int,int> mp;
    return dfs(root, k, mp);  
}
