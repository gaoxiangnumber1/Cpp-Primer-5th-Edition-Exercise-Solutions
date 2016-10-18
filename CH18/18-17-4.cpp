#include <iostream>

namespace Exercise
{
int i = 0;
double d = 0;
const int limit = 1000;
}

int i = 0;

void fun()
{
	using namespace Exercise;
	double d = 3.1416;
	int i2 = limit + 1;
	//++i; //error: reference to ‘i’ is ambiguous
	++::i;
	std::cout << "Exercise:: i = " << Exercise::i << ", d = " << Exercise::d << ", limit = "
	          << Exercise::limit << '\n';
	std::cout << "Global:: i = " << ::i << '\n';
	std::cout << "Local:: d = " << d << ", i2 = " << i2 << '\n';
}

int main()
{
	fun();
}
/*
Exercise:: i = 0, d = 0, limit = 1000
Global:: i = 1
Local:: d = 3.1416, i2 = 1001
*/
