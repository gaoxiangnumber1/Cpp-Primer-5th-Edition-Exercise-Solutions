#include <iostream>
#include <string>

using std::cout;
using std::string;

int main()
{
	string str = "gaoxiangnumber1";
	for(char &ch : str)
	{
		ch = 'X';
	}
	cout << str;

	return 0;
}
/*
Output:
XXXXXXXXXXXXXXX
*/
