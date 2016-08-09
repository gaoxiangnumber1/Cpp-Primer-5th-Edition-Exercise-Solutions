#include <iostream>
#include <vector>

using std::cout;
using std::begin;
using std::end;
using std::vector;

bool CompareArray(int *arr1_begin, int *arr1_end, int *arr2_begin, int *arr2_end)
{
	int length1 = arr1_end - arr1_begin, length2 = arr2_end - arr2_begin;
	if(length1 != length2)
	{
		return false;
	}
	for(int index = 0; index < length1; ++index)
	{
		if(*(arr1_begin + index) != *(arr2_begin + index))
		{
			return false;
		}
	}
	return true;
}

bool CompareVector(vector<int> &vec1, vector<int> &vec2)
{
	if(vec1 == vec2)
	{
		return true;
	}
	return false;
}

int main()
{
	int arr1[] = {1, 2, 3, 4, 5}, arr2[] = {1, 2, 3, 4, 5};
	cout << CompareArray(begin(arr1), end(arr1), begin(arr2), end(arr2)) << '\n';
	vector<int> vec1(5, 6), vec2(5, 7);
	cout << CompareVector(vec1, vec2);

	return 0;
}
/*
Output:
1
0
*/
