#include <unordered_map>
TreeNode<int>* buildTree (vector<int>& inOrder, int inStart, int inEnd, vector<int>& postOrder, int postStart, int postEnd, unordered_map <int, int> &inMap) {
     TreeNode <int> *root = new TreeNode <int> (postOrder[postEnd]);

     if (postStart>postEnd || inStart>inEnd) return NULL;

     int inRoot = inMap [root -> data];
     int numsLeft = inRoot - inStart;

     root -> left = buildTree (inOrder, inStart, inRoot-1, postOrder, postStart, postStart+numsLeft-1, inMap);
     root -> right = buildTree (inOrder, inRoot+1, inEnd, postOrder, postStart+numsLeft, postEnd-1, inMap);
     return root;

}


TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
    int n = inOrder.size();
    unordered_map <int, int> inMap;
    for (int i=0; i<n; i++) inMap [inOrder[i]] = i;
    return buildTree (inOrder, 0, n-1, postOrder, 0, n-1, inMap);
}
