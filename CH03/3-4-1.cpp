#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	if(str1 == str2)
	{
		cout << "Equal\n";
	}
	else
	{
		cout << "Not equal: " << ((str1 > str2) ? str1 : str2) << " is larger.\n";
	}

	return 0;
}
