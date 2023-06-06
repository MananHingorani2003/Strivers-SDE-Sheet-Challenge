void helper (vector <int> &path, TreeNode<int> *root, int x) {
	if (root == nullptr) return;
	if (root -> data == x) {
		path.push_back (x);
		return;
	}
	path.push_back (root -> data);
	helper (path, root-> left, x);
	helper (path, root->right, x);

	if (path[path.size()-1]!=x) path.pop_back();

}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector <int> path;
	helper (path, root, x);
	return path;

	
}
