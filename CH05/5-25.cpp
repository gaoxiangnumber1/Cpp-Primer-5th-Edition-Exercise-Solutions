#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main()
{
	int num1, num2;
	cout << "Input two integers: ";
	while(cin >> num1 >> num2)
	{
		try
		{
			if(num2 == 0)
			{
				throw runtime_error("Divisor is 0");
			}
			cout << num1 / num2 << endl;
			cout << "Input two integers: ";
		}
		catch (runtime_error error)
		{
			cout << error.what() << "\n" << "Try again.\nInput two integers: ";
		}
	}

	return 0;
}
