#include <iostream>
#include <string>

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
	cout << obj();

	return 0;
}
