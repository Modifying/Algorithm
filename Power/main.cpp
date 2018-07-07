// 计算一个数的n次方,不使用库函数

#include <iostream>

#define PRECISION 0.000001

bool Equal(double lhs, double rhs)
{
	bool ret = false;
	if ((lhs - rhs > -PRECISION) && (lhs - rhs < PRECISION))
		ret = true;

	return ret;
}

double PowerWithUnsignedExpon(double base, int absExponent)
{
	if (absExponent == 0)
		return 1;
	if (absExponent == 1)
		return base;

	double res = PowerWithUnsignedExpon(base, absExponent >> 1);

	res *= res;

	if (absExponent & 1)
		res *= base;

	return res;
}

double Power(double base, int exponent)
{
	if (Equal(base, 0.0))
	{
		return 0.0;
	}

	unsigned int absExponent = (unsigned)exponent;
	if (exponent < 0)
		absExponent = (-exponent);

	double res = PowerWithUnsignedExpon(base, absExponent);

	if (exponent < 0)
		res = 1.0 / res;

	return res;
}

int main()
{
	Power(2, -3);
	return 0;
}