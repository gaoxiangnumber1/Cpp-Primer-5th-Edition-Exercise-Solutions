#include <iostream>
#include <typeinfo>

using std::cout;

int main()
{
	const int i = 42;
	auto j = i;
	const auto &k = i;
	auto *p = &i;
	const auto j2 = i, &k2 = i;

	// i: int; PKi: pointer to const int.
	cout << "j is " << typeid(j).name() << "\nk is " << typeid(k).name()
	     << "\np is " << typeid(p).name() << "\nj2 is " << typeid(j2).name()
	     << "\nk2 is " << typeid(k2).name() << '\n';

	return 0;
}

/*
Output:
j is i
k is i
p is PKi
j2 is i
k2 is i
*/
