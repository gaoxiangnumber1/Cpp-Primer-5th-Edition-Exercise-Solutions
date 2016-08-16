#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	string judge, str1, str2;
	do
	{
		cout << "Input two strings: ";
		cin >> str1 >> str2;
		cout << (str1 <= str2 ? str1 : str2) << " is small\n";
		cout << "Continue?(y/n): ";
		cin >> judge;
	}
	while(judge == "y");
	return 0;
}
