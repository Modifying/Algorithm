// 在一个二维数组中查找某个数
// 二维数组从左至右递增，从上至下递增。


#include <iostream>
#include <vector>

using std::vector;

bool Search(const vector<vector<int> >&vec, int searchNum)
{
	bool ret = false;

	unsigned int size = vec.size();

	if (size > 0)
	{
		int baseNum = vec[0][size - 1];

		int row = 0;
		int column = size - 1;

		while (row < size && column >= 0)
		{
			if (searchNum == vec[row][column])
			{
				ret = true;
				break;
			}
			else if (searchNum > vec[row][column])
				row += 1;
			else
				column -= 1;

		}

	}

	return ret;
}

int main()
{
	int n;
	std::cin >> n;

	vector<vector<int> >vec;
	vec.resize(n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int num = 0;
			std::cin >> num;
			vec[i].push_back(num);
		}
	}

	int searchNum = 0;
	std::cin >> searchNum;

	if (Search(vec, searchNum))
	{
		std::cout << "Yes" << std::endl;
	}
	else
	{
		std::cout << "No" << std::endl;
	}
	
	return 0;
}