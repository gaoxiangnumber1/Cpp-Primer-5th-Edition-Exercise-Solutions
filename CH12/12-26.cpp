#include <iostream>
#include <string>

using namespace std;

void Fun(int n)
{
	allocator<string> alloc;
	auto const p = alloc.allocate(n);
	string s;
	auto q = p;
	while (cin >> s && q != p + n)
	{
		alloc.construct(q++, s);
	}

	while (q != p)
	{
		cout << *--q << " ";
		alloc.destroy(q);
	}
	alloc.deallocate(p, n);
}

int main()
{
	Fun(3);
}
