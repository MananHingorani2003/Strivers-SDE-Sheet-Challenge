vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    if (root == nullptr) return {};
        TreeNode *curr = root;
        stack <TreeNode *> mahi;
        vector <int> final;

        while (true) {
            if (curr != NULL) {
                mahi.push (curr);
                curr = curr -> left;
            }
            else {
                if (mahi.empty()) break;
                else {
                    curr = mahi.top();
                    mahi.pop();
                    final.push_back (curr->data);
                    curr = curr -> right;
                }       
            }
        }

        return final;
 }
