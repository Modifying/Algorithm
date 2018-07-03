// 给出二叉树的前序和中序 序列,重建二叉树


#include <iostream>
#include <array>

struct BinTreeNode
{
	BinTreeNode *m_lChild;
	BinTreeNode *m_rChild;
	int m_value;
};



BinTreeNode* Build(int *preOrder, int *inOrder, int len)
{
	BinTreeNode *root = nullptr;
	if (preOrder && inOrder && len > 0)
	{
		if (len <= 0)
			return nullptr;

		root = new BinTreeNode;
		root->m_lChild = nullptr;
		root->m_rChild = nullptr;
		root->m_value = *preOrder;

		int *rootInOrder = inOrder;
		while (rootInOrder < inOrder + len)
		{
			if (*rootInOrder == *preOrder)
				break;

			++rootInOrder;
		}

		int index = rootInOrder - inOrder;

		root->m_lChild = Build(preOrder + 1, inOrder, index);
		root->m_rChild = Build(preOrder + index + 1, rootInOrder + 1, len - index - 1);

	}
	return root;
}

void PrintPreOrder(BinTreeNode *root)
{
	if (root)
	{
		printf("%c", root->m_value);
		PrintPreOrder(root->m_lChild);
		PrintPreOrder(root->m_rChild);
	}
}

int main()
{
	int preOrder[20] = { 0 };
	int inOrder[20] = { 0 };

	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> preOrder[i];
	}

	for (int i = 0; i < n; ++i)
	{
		std::cin >> inOrder[i];
	}

	BinTreeNode *root = Build(preOrder, inOrder, n);
	PrintPreOrder(root);

	return 0;
}
