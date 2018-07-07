// 将一个二叉搜索树转化为双向链表, 不准使用额外空间.

#include <cstddef>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
};

void ConvertNode(TreeNode *root, TreeNode **lastNode)
{
	if (!root)
		return;

	TreeNode *currentNode = root;

	if (currentNode->left)
		ConvertNode(currentNode->left, lastNode);

	currentNode->left = *lastNode;

	if (*lastNode)
		(*lastNode)->right = currentNode;

	*lastNode = currentNode;

	if (currentNode->right)
		ConvertNode(currentNode->right, lastNode);
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
	TreeNode *lastNode = nullptr;

	ConvertNode(pRootOfTree, &lastNode);

	TreeNode *headOfList = lastNode;
	while (headOfList && headOfList->left)
		headOfList = headOfList->left;

	return headOfList;
}

int main()
{
	TreeNode *root = new TreeNode(8);
	TreeNode *root1 = new TreeNode(6);
	TreeNode *root2 = new TreeNode(5);
	TreeNode *root3 = new TreeNode(7);
	TreeNode *root4 = new TreeNode(10);
	TreeNode *root5 = new TreeNode(9);
	TreeNode *root6 = new TreeNode(11);

	root->left = root1;
	root->right = root4;

	root1->left = root2;
	root1->right = root3;

	root4->left = root5;
	root4->right = root6;

	Convert(root);

	return 0;
}