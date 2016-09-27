#include <iostream>
#include <string>
#include <map>
#include <functional>

using namespace std;

int add(int i, int j)
{
	return i + j;
}

auto mod = [](int i, int j)
{
	return i % j;
};

struct Div
{
	int operator ()(int i, int j) const
	{
		return i / j;
	}
};

map<string, function<int(int, int)>> binops =
{
	{ "+", add }, // function pointer
	{ "-", minus<int>() }, // library functor
	{ "/", Div() }, // user-defined functor
	{ "*", [](int i, int j) { return i*j; }}, // unnamed lambda
	{ "%", mod } // named lambda object
};

int main()
{
	while(1)
	{
		cout << "Input: operand1 operator operand2\n";
		int lhs, rhs;
		string op;
		cin >> lhs >> op >> rhs;
		cout << binops[op](lhs, rhs) << endl;
	}

	return 0;
}
