// 计算二进制中1的个数

#include <iostream>
#include <vector>
#include <algorithm>

// 常规解法
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

// 位运算, 但是负数会导致死循环
// 负数右移时会以1填充
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

// 位运算常规解法
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

// 最佳解法
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
