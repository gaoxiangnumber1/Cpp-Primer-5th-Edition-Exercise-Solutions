#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main()
{
	vector<string> text;
	for(string line; getline(cin, line); )
	{
		text.push_back(line);
	}

	vector<string>::iterator it = text.begin();
	for(; it != text.end() && !it->empty(); ++it)
	{
		for(char &ch : *it)
		{
			ch = (('a' <= ch && ch <= 'z') ? ch -32 : ch);
		}
		cout << *it << endl;
	}

	return 0;
}
