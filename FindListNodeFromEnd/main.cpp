// 找到链表的倒数第k个节点

#include <iostream>

struct ListNode
{
	int m_value;
	ListNode *m_next;
};

ListNode *CreateNode(int *arr, int len)
{
	ListNode *root = new ListNode;
	root->m_next = nullptr;

	ListNode *tmpNode = root;
	for (int i = 0; i < len; ++i)
	{
		ListNode *newNode = new ListNode;
		newNode->m_value = arr[i];
		newNode->m_next = nullptr;

		tmpNode->m_next = newNode;
		tmpNode = newNode;
	}

	return root;
}

void DeleteAllNode(ListNode *&root)
{
	while (root)
	{
		ListNode *nextNode = root;
		root = root->m_next;
		delete nextNode;
	}
}

ListNode *FindNodeFromEnd(ListNode *root, int n)
{
	if (!root && !n)
		return nullptr;

	ListNode *tmpNode = root;
	for (int i = 0; i < n - 1; ++i)
	{
		if (tmpNode->m_next)
			tmpNode = tmpNode->m_next;
		else
			return nullptr;
	}

	ListNode *behindNode = root;
	while (tmpNode->m_next)
	{
		tmpNode = tmpNode->m_next;
		behindNode = behindNode->m_next;
	}

	return behindNode;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	ListNode *root = CreateNode(arr, 5);

	ListNode *find = FindNodeFromEnd(root, 3);

	DeleteAllNode(root);
	return 0;
}