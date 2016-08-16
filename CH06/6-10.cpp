#include <iostream>

using std::cout;

void Swap(int *ptr1, int *ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

int main()
{
	int num1 = 10, num2 = 20;
	int *ptr1 = &num1, *ptr2 = &num2;
	Swap(ptr1, ptr2);
	cout << num1 << '\t' << num2;  // 20 10

	return 0;
}
