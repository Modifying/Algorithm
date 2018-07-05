// ¶þ²æÊ÷µÄ¾µÏñ


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

void Mirror(BinTreeNode *root)
{
	if (!root || !(root->m_rChild && root->m_lChild))
		return;

	BinTreeNode *tmpNode = root->m_lChild;
	root->m_lChild = root->m_rChild;
	root->m_rChild = tmpNode;

	if (root->m_lChild)
		Mirror(root->m_lChild);
	if (root->m_rChild)
		Mirror(root->m_rChild);
}

int main()
{
	BinTreeNode *root = CreateTree();

	Mirror(root);

	return 0;
}