#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	string input, total;
	while(cin >> input)
	{
		total = total + ' ' + input;
	}
	cout << total;

	return 0;
}
