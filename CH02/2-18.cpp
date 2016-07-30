#include <iostream>

using std::cout;

int main()
{
	int num1 = 1, num2 = 2;
	int *ptr = &num1;
	cout << num1 << '\t' << num2 << '\t' << ptr << "\t\t" << *ptr << '\n';

	// First: change the value of a pointer:
	ptr = &num2;
	cout << num1 << '\t' << num2 << '\t' << ptr << "\t\t" << *ptr << '\n';

	// Second: change the value to which the pointer points:
	*ptr = 3;
	cout << num1 << '\t' << num2 << '\t' << ptr << "\t\t" << *ptr << '\n';

	return 0;
}
/*
Output:
1	2	0x7ffebbb434e0		1
1	2	0x7ffebbb434e4		2
1	3	0x7ffebbb434e4		3
*/
