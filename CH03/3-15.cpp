#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

void Print(vector<string> &vec)
{
	int length = vec.size();
	for(int index = 0; index < length; ++index)
	{
		cout << vec[index] << " ";
	}
	cout << '\n';
}

int main()
{
	vector<string> vec;
	for(string str; cin >> str; )
	{
		vec.push_back(str);
	}
	Print(vec);

	return 0;
}
