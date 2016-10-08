#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename Container>
void PrintUseSize(Container &obj)
{
	typename Container::size_type length = obj.size(), index = 0;
	typename Container::iterator it = obj.begin();
	for(; index < length; ++index)
	{
		cout << *it << ' ';
		++it;
	}
	cout << '\n';
}

template<typename Container>
void PrintUseIter(Container &obj)
{
	typename Container::iterator it = obj.begin(), last = obj.end();
	for(; it != last; ++it)
	{
		cout << *it << ' ';
	}
	cout << '\n';
}

int main()
{
	vector<string> vec_string = { "gao", "xiang", "number", "one" };
	vector<int> vec_int = { 71, 88, 80, 7188 };
	PrintUseSize(vec_string);
	PrintUseSize(vec_int);

	PrintUseIter(vec_string);
	PrintUseIter(vec_int);

	return 0;
}
/*
Output:
gao xiang number one
71 88 80 7188
gao xiang number one
71 88 80 7188
*/
