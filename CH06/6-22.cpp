#include <iostream>

using std::cout;

void Fun(int* &ptr1, int* &ptr2)
{
	int *tmp = ptr1;
	ptr1 = ptr2;
	ptr2 = tmp;
}

int main()
{
	int num1 = 1, num2 = 2, *ptr1 = &num1, *ptr2 = &num2;
	cout << ptr1 << '\t' << *ptr1 << '\t' << ptr2 << '\t' << *ptr2 << '\n';
	Fun(ptr1, ptr2);
	cout << ptr1 << '\t' << *ptr1 << '\t' << ptr2 << '\t' << *ptr2 << '\n';
	return 0;
}
/*
0x7ffce66860d8	1	0x7ffce66860dc	2
0x7ffce66860dc	2	0x7ffce66860d8	1
*/
