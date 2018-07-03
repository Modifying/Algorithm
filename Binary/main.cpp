// �����������1�ĸ���

#include <iostream>
#include <vector>
#include <algorithm>

// ����ⷨ
int Fun1(int num)
{
	std::vector<int> vec;
	while (num)
	{
		vec.push_back(num % 2);
		num /= 2;
	}
	return std::count(vec.begin(), vec.end(), 1);
}

// λ����, ���Ǹ����ᵼ����ѭ��
// ��������ʱ����1���
int Fun2(int num)
{
	int count = 0;

	while (num)
	{
		if (num & 1)
			++count;

		num = num >> 1;
	}

	return count;
}

// λ���㳣��ⷨ
int Fun3(int num)
{
	int count = 0;
	unsigned flag = 1;
	while (flag)
	{
		if (num % flag)
			++count;

		flag = flag << 1;
	}

	return count;
}

// ��ѽⷨ
int Fun4(int num)
{
	int count = 0;

	while (num)
	{
		++count;
		num = (num - 1) & num;
	}

	return count;
}

int main()
{
	int num;
	std::cin >> num;

	Fun1(num);
	Fun2(num);
	Fun3(num);
	Fun4(num);
	return 0;
}
