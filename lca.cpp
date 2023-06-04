TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return NULL;
        }
        if (root -> val == p->val || root -> val == q -> val) {
            return root;
        }
        TreeNode *curr = root;
        TreeNode *a = lowestCommonAncestor (root -> left, p, q);
        TreeNode *b = lowestCommonAncestor (root -> right, p, q);
        
        if (a==NULL && b==NULL) {
            return NULL;
        }        
        else if (a==NULL && b!=NULL) {
            return b;
        }
        else if (a!=NULL && b==NULL) {
            return a;
        }
        else {
            return curr;
            
        }
        return NULL;
        
        
    }
