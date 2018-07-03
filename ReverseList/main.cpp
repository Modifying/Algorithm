// ·´×ªÁ´±í

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

ListNode *ReverseList(ListNode *root)
{
	ListNode *node = root;
	ListNode *prev = nullptr;
	ListNode *reversedHead = nullptr;

	while (node)
	{
		ListNode *nextNode = node->m_next;

		if (!nextNode)
			reversedHead = node;

		node->m_next = prev;

		prev = node;
		node = nextNode;
	}
	return reversedHead;
}


int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	ListNode *root = CreateNode(arr, 5);

	root = ReverseList(root);
	DeleteAllNode(root);
	return 0;
}