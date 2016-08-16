#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::runtime_error;

int main()
{
	int a, b;
	cin >> a >> b;
	if(b == 0)
	{
		throw runtime_error("Input Error: 0");
	}
	cout << a / b;

	return 0;
}
