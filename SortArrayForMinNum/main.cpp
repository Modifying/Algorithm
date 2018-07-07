


#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

bool Compare(string lhs, string rhs)
{
	string tmp1 = lhs + rhs;
	string tmp2 = rhs + lhs;

	return tmp1 < tmp2;
}

string PrintMinNumber(vector<int> numbers) {
	string str;

	vector<string> vec;
	if (numbers.size() > 0)
	{
		for (int i = 0; i < numbers.size(); ++i)
		{
			char tmp[10] = { 0 };
			sprintf_s(tmp, "%d", numbers[i]);
			std::string tmpStr(tmp);	
			vec.push_back(tmpStr);
		}

		std::sort(vec.begin(), vec.end(), Compare);

		for (int i = 0; i < vec.size(); ++i)
			str += vec[i];
	}
	return str;
}

int main()
{
	PrintMinNumber({ 3,32, 321 });
	return 0;
}
