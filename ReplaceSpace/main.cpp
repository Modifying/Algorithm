// 将字符串的所有空格替换为%20

#include <iostream>
#include <algorithm>
#include <string>

std::string Replace(const std::string &str)
{
	int spaceNum = std::count(str.begin(), str.end(), ' ');

	if (spaceNum == 0)
		return str;

	int size = str.length() + spaceNum * 2;

	if (size == 0)
		return "";

	std::string newStr(size + 1, 0);

	int j = size - 1;
	for (int i = str.length() - 1; i >= 0; --i)
	{
		if (str[i] == ' ')
		{
			newStr[j--] = '0';
			newStr[j--] = '2';
			newStr[j--] = '%';
		}
		else
			newStr[j--] = str[i];
	}
	return newStr;
}

int main()
{
	std::string str;
	
	char ch = 0;
	while ((ch = getchar()) != '\n')
	{
		str.push_back(ch);	
	}

	std::cout << Replace(str);

	return 0;
}