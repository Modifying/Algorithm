// ˳ʱ���ӡ����

#include <iostream>

void PrintMatrixInCircle(int arr[][10], int columns, int rows, int start)
{
	int endX = columns - start - 1;
	int endY = rows - start - 1;

	// ��������
	for (int i = start; i <= endX; ++i)
	{
		std::cout << arr[start][i];
	}

	// ��������

	if (start < endY)
	{
		for (int i = start + 1; i <= endY; ++i)
		{
			std::cout << arr[i][endX];
		}
	}
	
	// ��������
	if (start < endX && start < endY)
	{
		for (int i = endX - 1; i >= start; --i)
		{
			std::cout << arr[endY][i];
		}
	}
	

	// ��������

	if (start < endX && start < endY - 1)
	{
		for (int i = endY - 1; i >= start + 1; --i)
		{
			std::cout << arr[i][start];
		}
	}
}

void PrintMatrix(int arr[][10], int columns, int rows)
{
	if (!arr || columns <= 0 || rows <= 0)
		return;

	int start = 0;

	while (columns > start * 2 && rows > start * 2)
	{
		PrintMatrixInCircle(arr, columns, rows, start);
		++start;
	}
}

int main()
{
	int arr[10][10] = { 0 };

	int columns = 0, rows = 0;
	std::cin >> rows >> columns;

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			std::cin >> arr[i][j];
		}
	}

	PrintMatrix(arr, columns, rows);

	return 0;
}