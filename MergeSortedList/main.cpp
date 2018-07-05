// 合并两个排序的链表, 使得合并后的链表也是已排序的.


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
	root->m_value = arr[0];

	ListNode *tmpNode = root;
	for (int i = 1; i < len; ++i)
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

ListNode *Merge(ListNode *root1, ListNode *root2)
{
	if (!root1)
		return root2;

	if (!root2)
		return root1;

	ListNode *mergeRoot = nullptr;

	if (root1->m_value < root2->m_value)
	{
		mergeRoot = root1;
		mergeRoot->m_next = Merge(root1->m_next, root2);
	}
	else
	{
		mergeRoot = root2;
		mergeRoot->m_next = Merge(root1, root2->m_next);
	}

	return mergeRoot;
}

int main()
{
	int arr1[] = { 1, 3, 5, 7, 9 };
	int arr2[] = { 2, 4, 6, 8 };

	ListNode *root1 = CreateNode(arr1, 5);
	ListNode *root2 = CreateNode(arr2, 4);

	ListNode *root = Merge(root1, root2);

	DeleteAllNode(root);
	return 0;
}