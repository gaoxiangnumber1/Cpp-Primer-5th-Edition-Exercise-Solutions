#include <iostream>
#include <string>

using std::cout;
using std::string;

// Whether a string contains any capital letters
bool HasCapitalLetter(const string &str)
{
	for(char ch : str)
	{
		if('A' <= ch && ch <= 'Z')
		{
			return true;
		}
	}
	return false;
}

// Change a string to all lowercase
void ToAllLowercase(string &str)
{
	for(char &ch : str)
	{
		ch = (('A' <= ch && ch <= 'Z') ? ch + ('a' - 'A') : ch);
	}
}

int main()
{
	string str1 = "Gaoxiangnumber1";
	string str2 = "gaoxiangnumber1";
	cout << HasCapitalLetter(str1) << '\t' << HasCapitalLetter(str2) << '\t' <<
	     HasCapitalLetter("gaoxiangNumber1") << '\n';  // 1 0 1

	ToAllLowercase(str1);
	cout << str1;  // gaoxiangnumber1

	return 0;
}
/*
1	0	1
gaoxiangnumber1
*/
