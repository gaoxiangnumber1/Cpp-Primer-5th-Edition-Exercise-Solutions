#include <iostream>

using std::cout;

int main()
{
	int arr[3][4] = {{ 0, 1, 2, 3 }, { 4, 5, 6, 7 }, { 8, 9, 10, 11 }};

	cout << "Version 1: Range for\n";
	for(int (&row)[4] : arr)
	{
		for(int &col : row)
		{
			cout << col << ' ';
		}
	}

	cout << "\nVersion 2: Ordinary for using subscripts\n";
	for(int index1 = 0; index1 < 3; ++index1)
	{
		for(int index2 = 0; index2 < 4; ++index2)
		{
			cout << arr[index1][index2] << ' ';
		}
	}

	cout << "\nVersion 3: Ordinary for using pointers\n";
	for(int (*row)[4] = arr; row != arr + 3; ++row)
	{
		for(int *col = *row; col != *row + 4; ++col)
		{
			cout << *col << ' ';
		}
	}

	return 0;
}
/*
Version 1: Range for
0 1 2 3 4 5 6 7 8 9 10 11
Version 2: Ordinary for using subscripts
0 1 2 3 4 5 6 7 8 9 10 11
Version 3: Ordinary for using pointers
0 1 2 3 4 5 6 7 8 9 10 11
*/
