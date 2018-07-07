// 找出数组中最小的k个数字

#include <vector>
#include <set>
#include <functional>

void GetLeastNumbers(const std::vector<int> &data, std::vector<int> &vec, int k)
{
	std::multiset<int, std::greater<int> > set;

	if (k < 1 || data.size() < k)
		return;

	for (auto value : data)
	{
		if (set.size() < k)
			set.insert(value);
		else
		{
			if (value < *set.begin())
			{
				set.erase(set.begin());
				set.insert(value);
			}
		}

	}

	for (auto value : set)
	{
		vec.push_back(value);
	}
}

std::vector<int> GetLeastNumbers_Solution(std::vector<int> input, int k) {
	std::vector<int> vec;
	GetLeastNumbers(input, vec, k);
	return vec;
}

int main()
{
	GetLeastNumbers_Solution({ 1,2,3,5, 7,3,2,1,0}, 4);
	return 0;
}