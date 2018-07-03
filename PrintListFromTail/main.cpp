// 从尾到头打印链表

#include <iostream>
#include <list>
#include <stack>

int main()
{
	int n;
	std::cin >> n;

	std::list<int> list;
	for (int i = 0; i < n; ++i)
	{
		int num = 0;
		std::cin >> num;
		list.push_back(num);
	}

	std::stack<int> stack;

	for (auto value : list)
	{
		stack.push(value);
	}

	while (!stack.empty())
	{
		std::cout << stack.top();
		stack.pop();
	}

	return 0;
}