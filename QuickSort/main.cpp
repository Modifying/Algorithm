// ¿ìÅÅ

#include <cstdlib>
#include <algorithm>

int RandomInRange(int start, int end)
{
	int ret = -1;

	if (start <= end)
	{
		ret = (rand() % (end - start)) + start;
	}
	return ret;
}

int Partition(int *data, int len, int start, int end)
{
	if (!data || len <= 0 || start < 0 || end >= len)
		return -1;

	int index = RandomInRange(start, end);
	std::swap(data[index], data[end]);

	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (data[index] < data[end])
		{
			++small;

			if (small < index)
				std::swap(data[small], data[index]);
		}
	}
	++small;
	std::swap(data[small], data[end]);

	return small;
}

void QuickSort(int *data, int len, int start, int end)
{
	if (start == end)
		return;

	int index = Partition(data, len, start, end);

	if (index > start)
		QuickSort(data, len, start, index - 1);
	else
		QuickSort(data, len, index + 1, end);
}

int main()
{
	int arr[] = { 3, 2, 4,5,8,1, 0,7 };

	QuickSort(arr, 8, 0, 7);

	return 0;
}