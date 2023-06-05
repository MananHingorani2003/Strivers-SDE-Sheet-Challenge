
void connectNodes(BinaryTreeNode< int > *root) {
    if (root == nullptr) return;
        queue <BinaryTreeNode< int > *> mahi;
        mahi.push (root);

        while (!mahi.empty()) {
            BinaryTreeNode< int > *prev = NULL;
            int n = mahi.size();

            while (n--) {
                BinaryTreeNode< int > *front = mahi.front();
                mahi.pop();
                front -> next = prev;
                prev = front;

                if (front -> right) mahi.push (front -> right);
                if (front -> left) mahi.push (front -> left);
            }
        }

}
