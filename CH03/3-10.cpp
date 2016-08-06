#include <iostream>
#include <string>
#include <cctype>  // ispunct(c)

using std::cout;
using std::cin;
using std::string;

int main()
{
	string str;
	cin >> str;
	int length = str.size();
	for(int index = 0; index < length; ++index)
	{
		if(ispunct(str[index]))
		{
			continue;
		}
		cout << str[index];
	}

	return 0;
}
