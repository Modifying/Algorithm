// 求一个字符串的全排列

#include <string>
#include <vector>
#include <set>

using std::vector;
using std::string;

void Permutation(std::vector<string> &vec, string& str, char *begin)
{
	if (*begin == '\0')
		vec.push_back(str);

	else
	{
		for (char *ch = begin; *ch != '\0'; ++ch)
		{
			char tmp = *ch;
			*ch = *begin;
			*begin = tmp;

			Permutation(vec, str, begin + 1);
			tmp = *ch;
			*ch = *begin;
			*begin = tmp;

		}
	}
}

vector<string> Permutation(string str) {
	vector<std::string> vec;
	if (str.size() > 0)
		Permutation(vec, str, const_cast<char *>(str.c_str()));

	std::set<string> set(vec.begin(), vec.end());
	vector<std::string> vec1;
	for (auto element : set)
	{
		vec1.push_back(element);
	}

	return vec1;
}

int main()
{
	Permutation(string("abc"));

	return 0;
}