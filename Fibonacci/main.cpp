

#include <iostream>

long long Fibonacci(unsigned n)
{
	int result[2] = { 0, 1 };
	if (n < 2)
		return result[n];

	long long fibOne = 0;
	long long fibTwo = 1;
	long long fibN = 0;

	for (int i = 2; i < n; ++i)
	{
		fibN = fibOne + fibTwo;

		fibOne = fibTwo;
		fibTwo = fibN;
	}

	return fibN;
}

int main()
{
	int n;
	std::cin >> n;
	std::cout << Fibonacci(n - 1);

	return 0;
}