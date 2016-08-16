#include <iostream>

using std::cout;

void reset(int &num)
{
	num = 0;
}

int main()
{
	int num = 42;
	reset(num);
	cout << num;
	return 0;
}
