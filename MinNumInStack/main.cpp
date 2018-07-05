// 用O(1)的复杂度找到栈中最下元素

#include <iostream>
#include <stack>

template<typename Tp>
class MinStack
{
public:
	void Push(const Tp& value)
	{
		m_stack.push(value);

		if (m_min.empty() || m_min.top() < value)
		{
			m_min.push(value);
		}
		else
		{
			m_min.push(m_min.top());
		}
	}

	void Pop()
	{
		if (!m_stack.empty() && !m_min.empty())
		{
			m_stack.pop();
			m_min.pop();
		}
	}

	Tp &GetMin()
	{
		return m_min.top();
	}
private:
	std::stack<Tp> m_stack;
	std::stack<Tp> m_min;
};

int main()
{
	

	return 0;
}