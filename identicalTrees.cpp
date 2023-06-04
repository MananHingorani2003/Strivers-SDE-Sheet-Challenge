bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here. 
    if (root1 == nullptr && root2 == nullptr) return true;
    if (root1 == nullptr && root2 != nullptr) return false;
    if (root1 != nullptr && root2 == nullptr) return false;	


    return identicalTrees(root1 -> left, root2 -> left) && 
    identicalTrees(root1 -> right, root2 -> right) && root1->data==root2->data; 

}
