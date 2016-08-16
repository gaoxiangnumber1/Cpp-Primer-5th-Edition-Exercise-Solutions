#include <iostream>

using std::cout;

void Swap(int &ref1, int &ref2)
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

int main()
{
	int num1 = 10, num2 = 20;
	int &ref1 = num1, &ref2 = num2;
	Swap(ref1, ref2);
	cout << num1 << '\t' << num2;  // 20 10

	return 0;
}
