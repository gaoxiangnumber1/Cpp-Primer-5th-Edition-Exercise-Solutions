#include <iostream>
#include <vector>

using std::cout;
using std::begin;
using std::end;
using std::vector;

template<typename T>
void Print(vector<T> &vec)
{
	typename vector<T>::const_iterator it1 = vec.cbegin(), it2 = vec.cend();
	for(; it1 != it2; ++it1)
	{
		cout << *it1 << " ";
	}
	cout << ((vec.cbegin() == vec.cend()) ? "empty\n" : "\n");
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	vector<int> vec(begin(arr), end(arr));
	Print(vec);

	return 0;
}
/*
Output:
1 2 3 4 5
*/
