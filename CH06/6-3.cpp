#include <iostream>

using std::cin;
using std::cout;

int fact(int val)
{
	int result = 0;
	if(val < 0)
	{
		cout << "Input error! Try Again.\n";
	}
	else if(val == 0 || val == 1)
	{
		result = 1;
	}
	else
	{
		result = val * fact(val - 1);
	}
	return result;
}

int main()
{
	for(int num = 0; cin >> num; )
	{
		cout << fact(num) << '\n';
	}

	return 0;
}
