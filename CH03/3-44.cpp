#include <iostream>

using std::cout;

using int_array = int[4];

int main()
{
	int arr[3][4] = {{ 0, 1, 2, 3 }, { 4, 5, 6, 7 }, { 8, 9, 10, 11 }};

	for(int_array *row = arr; row != arr + 3; ++row)
	{
		for(int *col = *row; col != *row + 4; ++col)
		{
			cout << *col << ' ';
		}
	}

	return 0;
}
/*
0 1 2 3 4 5 6 7 8 9 10 11
*/
