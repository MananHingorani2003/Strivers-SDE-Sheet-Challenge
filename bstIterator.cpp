class BSTiterator
{
private:
    stack <TreeNode<int> *> mahi;
    void pushAll (TreeNode<int> *node) {
        while (node!=NULL) {
            mahi.push (node);
            node = node -> left;
        }
    }    
public:
    BSTiterator(TreeNode<int> * root) {
        pushAll (root);
    }
    
    int next() {
        TreeNode<int> *curr = mahi.top();
        mahi.pop();
        pushAll (curr -> right);
        return curr -> data;
    }
    
    bool hasNext() {
        return !mahi.empty();
    }
};
