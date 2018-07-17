
#include <algorithm>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
};

int GetMinDepth(TreeNode *root) {
	if (!root)
		return 0;

	if (!root->left)
		return GetMinDepth(root->right) + 1;

	if (!root->right)
		return GetMinDepth(root->left) + 1;

	int leftDepth = GetMinDepth(root->left);
	int rightDepth = GetMinDepth(root->right);
	return std::min(leftDepth, rightDepth) + 1;
}

int main()
{
	TreeNode *root = new TreeNode(1);
	TreeNode *root1 = new TreeNode(2);
	root->left = root1;

	GetMinDepth(root);
	

	return 0;
}