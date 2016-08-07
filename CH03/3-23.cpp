#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

template<typename T>
void Double(vector<T> &vec)
{
	typename vector<T>::iterator it1 = vec.begin(), it2 = vec.end();
	for(; it1 != it2; ++it1)
	{
		*it1 *= 2;
	}
}

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
	vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	Double(vec);
	Print(vec);

	return 0;
}
