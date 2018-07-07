#include <algorithm>



int GetUglyNumber_Solution(int index) {
	if (index <= 0)
		return 0;

	int *arr = new int[index];

	arr[0] = 1;
	int nextIndex = 1;

	int *multiply2 = arr;
	int *multiply3 = arr;
	int *multiply5 = arr;
	while (nextIndex < index)
	{
		int min = std::min(*multiply2 * 2, std::min(*multiply3 * 3, *multiply5 * 5));

		arr[nextIndex] = min;

		while (*multiply2 * 2 <= arr[nextIndex])
			++multiply2;
		while (*multiply3 * 3 <= arr[nextIndex])
			++multiply3;
		while (*multiply5 * 5 <= arr[nextIndex])
			++multiply5;

		++nextIndex;
	}

	return arr[index - 1];
}


int main()
{
	GetUglyNumber_Solution(1500);

	return 0;
}