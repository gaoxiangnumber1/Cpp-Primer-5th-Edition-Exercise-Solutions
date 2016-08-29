#include <iostream>

using std::cout;
using std::initializer_list;

void Fun(initializer_list<int> ilist)
{
	int sum = 0;
	for(initializer_list<int>::iterator beg = ilist.begin(); beg != ilist.end(); ++beg)
	{
		sum += *beg;
	}
	cout << sum << '\n';
}

int main()
{
	Fun({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

	return 0;
}
/*
Output:
55
*/
