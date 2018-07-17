// Ö®×Ö´òÓ¡¶þ²æÊ÷


#include <vector>
#include <queue>
#include <string>
using std::vector;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
};

vector<vector<int> > Print(TreeNode* pRoot)
{
	vector<vector<int> > vec;
	if (pRoot)
	{
		std::deque<TreeNode *> qu;
		qu.push_back(nullptr);
		qu.push_back(pRoot);

		bool leftToRight = true;
		while (qu.size() != 1)
		{
			TreeNode *node = qu.front();
			qu.pop_front();

			vector<int> floor;
			if (node == nullptr)
			{
				if (leftToRight)
				{
					
					for (auto it = qu.begin(); it != qu.end(); ++it)
					{
						floor.push_back((*it)->val);
					}
				}
				else
				{
					
					for (auto it = qu.rbegin(); it != qu.rend(); ++it)
					{
						floor.push_back((*it)->val);
					}
				}

				leftToRight = !leftToRight;

				vec.push_back(floor);
				floor.clear();
				qu.push_back(nullptr);
				continue;
			}

			if (node->left)
				qu.push_back(node->left);

			if (node->right)
				qu.push_back(node->right);
		}
	}

	return vec;
}

int main()
{
	TreeNode *root = new TreeNode(1);
	TreeNode *root1 = new TreeNode(2);
	TreeNode *root2 = new TreeNode(3);
	TreeNode *root3 = new TreeNode(4);
	TreeNode *root4 = new TreeNode(5);
	TreeNode *root5 = new TreeNode(6);
	TreeNode *root6 = new TreeNode(7);
	//TreeNode *root7 = new TreeNode(8);

	root->left = root1;
	root->right = root2;
	root1->left = root3;
	root1->right = root4;
	root2->left = root5;
	root2->right = root6;

	Print(root);
	return 0;
}