// O(nlog(n))对链表进行排序



struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *Merge(ListNode *left, ListNode *right)
{
	ListNode dummy(0);
	ListNode *tmp = &dummy;

	while (left && right)
	{
		if (left->val < right->val)
		{
			tmp->next = left;
			left = left->next;
		}
		else
		{
			tmp->next = right;
			right = right->next;
		}
		tmp = tmp->next;
	}
	if (left)
		tmp->next = left;

	if (right)
		tmp->next = right;

	return dummy.next;
}

ListNode *SortList(ListNode *head)
{
	if (!head || !head->next)
		return head;

	ListNode *p = head, *q = head->next;
	while (q && q->next)
	{
		p = p->next;
		q = q->next->next;
	}

	ListNode *left = SortList(p->next);
	p->next = nullptr;
	ListNode *right = SortList(head);

	return Merge(left, right);
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
	ListNode *l8 = new ListNode(8);

	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;
	l6->next = l7;
	l7->next = l8;

	SortList(l1);
	return 0;
}



