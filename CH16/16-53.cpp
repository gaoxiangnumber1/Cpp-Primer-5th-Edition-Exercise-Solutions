#include <iostream>

using namespace std;

template<typename T>
ostream &print(ostream &os, const T &t)
{
	return os << t << '\n';
}
template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest)
{
	os << t << ", ";
	return print(os, rest...);
}

int main()
{
	int obj1 = 0;
	double obj2 = 3.14;
	string obj3 = "gaoxiang";
	char obj4 = 'X';
	bool obj5 = false;

	print(cout, obj1);
	print(cout, obj1, obj2);
	print(cout, obj1, obj2, obj3, obj4, obj5);
}
/*
0
0, 3.14
0, 3.14, gaoxiang, X, 0
*/
