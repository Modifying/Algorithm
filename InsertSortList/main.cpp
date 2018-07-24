
#include <algorithm>
#include <stack>
#include <queue>

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *insertionSortList(ListNode *head) 
{
	if (!head || !head->next)
		return head;

	ListNode *cursor = head;
	ListNode *current = head->next;
	ListNode *prveNode = head;

	while (current)
	{
		if (current->val < head->val)
		{
			prveNode->next = current->next;
			current->next = head;
			head = current;
		}
		else
		{
			ListNode *tmpCur = cursor;
			cursor = tmpCur->next;

			while (cursor != current && cursor->val < current->val)
			{
				tmpCur = cursor;
				cursor = cursor->next;
			}
			
			if (current == cursor)
			{
				prveNode = current;
				current = prveNode->next;
			}
			else
			{
				prveNode->next = current->next;
				tmpCur->next = current;
				current->next = cursor;
			}
		}

		cursor = head;
		current = prveNode->next;
	}
	return head;
}

void reorderList(ListNode *head) 
{
	int len = 0;
	std::queue<ListNode *> qu;
	std::stack<ListNode *> st;
	ListNode *tmpNode = head;
	while (tmpNode)
	{
		tmpNode = tmpNode->next;
		++len;
	}

	if (len >= 2)
	{
		ListNode *midNode = head;

		for (int i = 0; i < len / 2; ++i)
			midNode = midNode->next;

		tmpNode = head;
		while (tmpNode != midNode)
		{
			qu.push(tmpNode);
			tmpNode = tmpNode->next;

		}

		while (midNode)
		{
			st.push(midNode);
			midNode = midNode->next;
		}

		ListNode *newHead = qu.front();
		while (!qu.empty())
		{
			tmpNode = qu.front();
			qu.pop();
			tmpNode->next = st.top();
			st.pop();

			if (qu.empty() && !st.empty())
				tmpNode->next->next = st.top();
			else if (!qu.empty())
				tmpNode->next->next = qu.front();
			else
				tmpNode->next->next = nullptr;
		}
		head = newHead;
	}

}

int main()
{
	ListNode *l1 = new ListNode(3);
	ListNode *l2 = new ListNode(2);
	ListNode *l3 = new ListNode(6);
	ListNode *l4 = new ListNode(4);
	ListNode *l5 = new ListNode(5);
	ListNode *l6 = new ListNode(9);
	ListNode *l7 = new ListNode(7);
	//ListNode *l8 = new ListNode(8);

	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;
	l6->next = l7;
	//l7->next = l8;

	reorderList(l1);

	insertionSortList(l1);


	return 0;
}