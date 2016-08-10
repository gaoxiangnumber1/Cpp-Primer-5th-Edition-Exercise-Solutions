#include <iostream>

using std::cout;

int main()
{
	int arr[3][4] = {{ 0, 1, 2, 3 }, { 4, 5, 6, 7 }, { 8, 9, 10, 11 }};

	for(auto &row : arr)
	{
		for(auto col : row)
		{
			cout << col << ' ';
		}
	}

	return 0;
}
/*
0 1 2 3 4 5 6 7 8 9 10 11
*/
