#include <iostream>
#include <vector>

using std::cout;
using std::vector;

void Print(vector<int> &vec, int index)
{
	if(index == 0)
	{
		cout << vec[0] << ' ';
		return;
	}
	Print(vec, index - 1);
	cout << vec[index] << ' ';
}

int main()
{
	vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	Print(vec, vec.size() - 1);
}
/*
Output:
1 2 3 4 5 6 7 8 9 10
*/
