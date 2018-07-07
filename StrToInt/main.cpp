#include <string>

class Solution {
public:
	Solution() :m_status(kValid)
	{}
	int StrToIntCore(std::string::iterator &it, const std::string::iterator &end, bool minus)
	{
		long long num = 0;
		int flag = minus ? -1 : 1;
		while (it != end)
		{
			
			if (*it >= '0' && *it <= '9')
			{
				num = num * 10 + flag * (*it - '0');

				if ((!minus && num > 0x7fffffff) || (minus && num < (int)0x80000000))
				{
					num = 0;
					break;
				}
				++it;
			}
			else
			{
				num = 0;
				break;
			}
		}

		if (it == end)
			m_status = kValid;

		return (int)num;
	}

	int StrToInt(std::string str) {
		m_status = kInvalid;
		int num = 0;
		if (str.size() > 0)
		{
			bool minus = false;
			std::string::iterator it = str.begin();
			if (*it == '+')
				++it;
			else if (*it == '-')
			{
				++it;
				minus = true;
			}

			if (it != str.end())
			{
				num = StrToIntCore(it, str.end(), minus);
			}
		}
		return num;
	}

private:
	enum Status
	{
		kValid,
		kInvalid
	};

	int m_status;
};

int main()
{
	Solution so;
	so.StrToInt("-123");

	return 0;
}
