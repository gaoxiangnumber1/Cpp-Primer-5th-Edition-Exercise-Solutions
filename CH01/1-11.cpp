#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int num1 = 0, num2 = 0;
	cout << "Please input 2 integers: ";
	cin >> num1 >> num2;

	// We make num1 <= num2
	if(num1 > num2)
	{
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}

	// Print integers in the range [num1, num2]:
	while(num1 <= num2)
	{
		cout << num1 << endl;
		++num1;
	}

	return 0;
}
