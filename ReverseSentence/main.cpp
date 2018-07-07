#include <string>

using std::string;

void Reverse(string::iterator begin, string::iterator end)
{
	while (begin < end)
	{
		std::swap(*begin, *end);

		++begin;
		--end;
	}
}

string ReverseSentence(string str)
{
	if (str.length() > 0)
	{
		string::iterator begin = str.begin();
		string::iterator end = str.end() - 1;
		str.length();
		Reverse(begin, end);

		begin = end = str.begin();
		while (begin != str.end())
		{
			if (*begin == ' ')
			{
				++begin;
				++end;
			}
			else if (end == str.end() || *end == ' ')
			{
				Reverse(begin, --end);
				begin = ++end;
			}
			else
			{
				++end;
			}
		}
	}
	return str;
}

int main()
{
	ReverseSentence("I am a student.");
	
	return 0;
}