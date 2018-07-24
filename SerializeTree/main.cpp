#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include <set>
#include <algorithm>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
};

char* Serialize(TreeNode *root) {
	if (!root)
		return "#";

	std::string str = std::to_string(root->val);
	str.push_back(',');
	char *left = Serialize(root->left);
	char *right = Serialize(root->right);

	
	char *ret = new char[strlen(left) + strlen(right) + str.size()];
	strcpy(ret, str.c_str());
	strcat(ret, left);
	strcat(ret, right);

	
	return ret;
}

TreeNode *Deserialize(char **str)
{
	if (**str == '#')
	{
		++(*str);
		return nullptr;
	}
	int num = strtol(*str, str, 10);

	TreeNode *node = new TreeNode(num);

	if (**str == 0)
		return node;
	else
		++(*str);

	node->left = Deserialize(str);
	node->right = Deserialize(str);
	return node;
}

TreeNode *Deserialize(char *str)
{
	if (!str)
		return nullptr;

	TreeNode *node = Deserialize(&str);

	return node;
}



int main()
{
	TreeNode *root = new TreeNode(8);
	TreeNode *root1 = new TreeNode(6);
	TreeNode *root2 = new TreeNode(10);
	TreeNode *root3 = new TreeNode(5);
	TreeNode *root4 = new TreeNode(7);
	TreeNode *root5 = new TreeNode(9);
	TreeNode *root6 = new TreeNode(11);

	root->left = root1;
	root->right = root2;
	root1->left = root3;
	root1->right = root4;
	root2->left = root5;
	root2->right = root6;

	char * str = Serialize(root);

	TreeNode *node = Deserialize(str);

	return 0;
}