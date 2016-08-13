#include <iostream>

using std::cout;

int main()
{
	int x = 1, y = 9;
	cout << (true ? ++x, ++y : --x, --y) << '\n';
	cout << x << '\t' << y << '\n';
	cout << (false ? ++x, ++y : --x, --y) << '\n';
	cout << x << '\t' << y << '\n';

	return 0;
}
