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
	string::size_type length1 = str1.size(), length2 = str2.size();
	if(length1 == length2)
	{
		cout << "Same length\n";
	}
	else
	{
		cout << ((length1 > length2) ? str1 : str2) << " is longer.\n";
	}

	return 0;
}
