// ����ջ����, ��һ��Ϊѹջ����, �ڶ���Ϊ��ջ����. �жϵڶ��������Ƿ�Ϊ��һ�����еĳ�ջ����

#include <stack>

bool IsPopOrder(const int *push, const int *pop, int len)
{
	bool ret = false;

	if (push && pop && len > 0)
	{
		const int *nextPush = push;
		const int *nextPop = pop;

		std::stack<int> stack;
		while (nextPop - pop < len)
		{
			while (stack.empty() || stack.top() != *nextPop)
			{
				if (nextPush - push == len)
					break;

				stack.push(*nextPush);
				++nextPush;
			}

			if (stack.top() != *nextPop)
				break;

			stack.pop();
			++nextPop;
		}

		if (stack.empty() && nextPop - pop == len)
			ret = true;
	}

	return ret;
}

int main()
{
	int push[] = { 1, 2, 3, 4, 5 };
	int pop[] = { 4, 5, 3, 2, 1 };

	bool ret = IsPopOrder(push, pop, 5);

	return 0;
}