#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int sum = 0;
	for(int value = 0; cin >> value;)
	{
		sum += value;
	}
	cout << "The sum is " << sum << endl;

	return 0;
}
