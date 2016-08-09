#include <iostream>
#include <cstring>

using std::cout;

int main()
{
	char arr1[] = "gao", arr2[] = "xiang", arr3[9];
	strcat(arr1, arr2);
	strcpy(arr3, arr1);
	cout << arr3 << '\n';

	return 0;
}
/*
Output:
gaoxiang
*/
