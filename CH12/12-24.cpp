#include <iostream>

using namespace std;

int main()
{
	int length = 0;
	while(true)
	{
		cout << "Input your string length: ";
		cin >> length;
		char *str = new char[length + 1]();
		cout << "Input string: ";
		cin >> str;
		cout << str << '\n';
		delete[] str;
	}
}
