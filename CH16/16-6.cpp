#include <iostream>
#include <string>

using namespace std;

template<typename T, unsigned int N>
T* Begin(T (&arr)[N])
{
	return arr;
}

template<typename T, unsigned int N>
T* End(T (&arr)[N])
{
	return arr + N;
}

int main()
{
	int arr1[] = {1, 2, 3, 4, 5, 6, 7};
	cout << *Begin(arr1) << ' ' << *(End(arr1) - 1) << '\n';
	string arr2[] = { "gao", "xiang", "number", "one" };
	cout << *Begin(arr2) << ' ' << *(End(arr2) - 1) << '\n';

	return 0;
}
