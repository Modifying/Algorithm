#include <iostream>
#include <stack>

template<typename Tp>
class CQueue
{
public:
	CQueue(){}
	~CQueue(){}

	void Push(const Tp &element)
	{
		m_stack1.push(element);
	}

	Tp Pop()
	{
		if (m_stack2.empty())
		{
			while (!m_stack1.empty())
			{
				m_stack2.push(m_stack1.top());
				m_stack1.pop();
			}
		}

		Tp head;
		if (!m_stack2.empty())
		{
			head = m_stack2.top();
			m_stack2.pop();
		}
		return head;
	}


private:
	std::stack<Tp> m_stack1;
	std::stack<Tp> m_stack2;
};



int main()
{
	CQueue<std::string> que;
	que.Push("123");
	que.Push("456");
	que.Push("789");
	que.Pop();
	return 0;
}
