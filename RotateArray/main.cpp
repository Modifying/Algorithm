// 求旋转数组中的最小值, 将一个递增的数组进行旋转.

#include <iostream>
#include <algorithm>
#include <exception>

int Min(int *arr, int len)
{
	if (!arr || len < 0)
		throw new std::exception("Invalid parameters");

	int indexHead = 0;
	int indexTail = len - 1;
	int indexMid = indexHead;

	while (arr[indexHead] >= arr[indexTail])
	{
		if (indexTail - indexHead == 1)
		{
			indexMid = indexTail;
			break;
		}

		indexMid = (indexHead + indexTail) / 2;

		if (arr[indexHead] == arr[indexMid] && arr[indexHead] == arr[indexTail])
		{
			int *num = std::min_element(arr, arr + len);
			return *num;
		}

		if (arr[indexHead] >= arr[indexMid])
			indexTail = indexMid;
		else if (arr[indexHead] <= arr[indexMid])
			indexHead = indexMid;
	}

	return arr[indexMid];
}

int main()
{
	int n;
	std::cin >> n;

	int arr[100] = { 0 };
	for (int i = 0; i < n; ++i)
	{
		std::cin >> arr[i];
	}

	std::cout << Min(arr, n);

	return 0;
}