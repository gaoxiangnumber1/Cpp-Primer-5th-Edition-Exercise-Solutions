#include <iostream>

using namespace std;

template<typename T, typename ... Args>
void foo(const T &t, const Args& ... rest)
{
	cout << "Args number = " << sizeof...(Args) << '\n';
	cout << "rest number = " << sizeof...(rest) << '\n';
}

int main()
{
	int i = 0;
	double d = 3.14;
	string s = "how now brown cow";
	foo(i, s, 42, d); // three parameters in the pack
	foo(s, 42, "hi"); // two parameters in the pack
	foo(d, s); // one parameter in the pack
	foo("hi"); // empty pack
}
/*
Args number = 3
rest number = 3
Args number = 2
rest number = 2
Args number = 1
rest number = 1
Args number = 0
rest number = 0
*/
