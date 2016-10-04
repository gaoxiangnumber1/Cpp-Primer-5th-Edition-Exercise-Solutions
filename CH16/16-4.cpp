#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template<typename Iterator, typename Value>
Iterator Find(Iterator first, Iterator last, const Value& value)
{
	for(; first != last && *first != value; ++first);
	return first;
}

int main()
{
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	bool is_in_vector = (v.cend() != Find(v.cbegin(), v.cend(), 5));
	cout << (is_in_vector ? "found\n" : "not found\n");

	list<string> l = { "aa", "bb", "cc", "dd", "ee", "ff", "gg" };
	bool is_in_list = (l.cend() != Find(l.cbegin(), l.cend(), "zz"));
	cout << (is_in_list ? "found\n" : "not found\n");

	return 0;
}
