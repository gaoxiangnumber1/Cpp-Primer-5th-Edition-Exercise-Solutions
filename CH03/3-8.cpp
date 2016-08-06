#include <iostream>
#include <string>

using std::cout;
using std::string;

int main()
{
	string str1 = "gaoxiangnumber1";
	string str2 = str1;
	int length = str1.size();

	// First: use while
	int index1 = 0;
	while(index1 < length)
	{
		str1[index1] = 'X';
		++index1;
	}

	// Second, use traditional for
	for(int index2 = 0; index2 < length; ++index2)
	{
		str2[index2] = 'X';
	}
	cout << str1 << '\t' << str2;

	return 0;
}
/*
Output:
XXXXXXXXXXXXXXX	XXXXXXXXXXXXXXX
*/
