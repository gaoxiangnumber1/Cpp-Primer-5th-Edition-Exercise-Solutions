#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Print
{
	string operator()(istream &is = cin)
	{
		string ret;
		getline(is, ret);
        return is ? ret : string();
	}
};

int main()
{
	Print obj;
	string str = obj(cin);
	vector<string> vec;
	while(!str.empty())
	{
		vec.push_back(str);
		str = obj(cin);
	}
	for(auto s : vec)
	{
		cout << s << '\n';
	}

	return 0;
}
