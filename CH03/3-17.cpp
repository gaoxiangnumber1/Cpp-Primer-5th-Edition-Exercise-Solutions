#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

template<typename T>
void Print(vector<T> &vec)
{
	int length = vec.size();
	int cnt = 0;
	for(int index = 0; index < length; ++index)
	{
		cout << vec[index] << " ";
		++cnt;
		if(cnt % 8 == 0)
		{
			cout << '\n';
		}
	}
	cout << '\n';
}

int main()
{
	vector<string> vec;
	for(string str1; cin >> str1; )
	{
		vec.push_back(str1);
	}
	int length1 = vec.size();
	for(int index1 = 0; index1 < length1; ++index1)
	{
		string &str2 = vec[index1];
		int length2 = str2.size();
		for(int index2 = 0; index2 < length2; ++index2)
		{
			char &ch = str2[index2];
			ch = (('a' <= ch && ch <= 'z') ? ch - 32 : ch);
		}
	}
	Print(vec);

	return 0;
}
