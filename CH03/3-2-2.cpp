#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	// One line at a time:
	string str;
	while(cin >> str)
	{
		cout << str << endl;
	}

	return 0;
}
