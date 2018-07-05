// 两棵树A,B,判断B是不是A的子树

#include <iostream>

struct BinTreeNode
{
	BinTreeNode *m_lChild;
	BinTreeNode *m_rChild;
	char m_value;
};

BinTreeNode * CreateTree()
{
	BinTreeNode *root = new BinTreeNode;
	root->m_lChild = nullptr;
	root->m_rChild = nullptr;

	char ch;
	std::cin >> ch;
	if (ch != '#')
	{
		root->m_value = ch;
		root->m_lChild = CreateTree();
		root->m_rChild = CreateTree();
	}

	return root;
}

bool DoesTree1HaveTree2(BinTreeNode *root1, BinTreeNode *root2)
{
	if (!root2)
		return true;

	if (!root1)
		return false;

	if (root1->m_value != root2->m_value)
		return false;

	return DoesTree1HaveTree2(root1->m_lChild, root2->m_lChild) &&
		DoesTree1HaveTree2(root1->m_rChild, root2->m_rChild);
}

bool HasSubTree(BinTreeNode *root1, BinTreeNode *root2)
{
	bool ret = false;

	if (root1 && root2)
	{
		if (root1->m_value == root2->m_value)
		{
			ret = DoesTree1HaveTree2(root1, root2);
		}
		if (!ret)
		{
			ret = HasSubTree(root1->m_lChild, root2);
		}

		if (!ret)
		{
			ret = HasSubTree(root1->m_rChild, root2);
		}
	}
	return ret;
}

int main()
{
	BinTreeNode *root1 = CreateTree();
	BinTreeNode *root2 = CreateTree();

	bool ret = HasSubTree(root1, root2);

	return 0;
}