#include <string>

int FirstNotRepeatingChar(std::string str) {
	int pos = -1;

	if (str.length() > 0)
	{
		int hashTab[256] = { 0 };

		for (int i = 0; i < str.length(); ++i)
			++hashTab[str[i]];

		for (int i = 0; i < str.length(); ++i)
		{
			if (hashTab[str[i]] == 1)
				pos = i;
		}
	}


	return pos;
}

int main()
{
	FirstNotRepeatingChar("google");
	return 0;
}