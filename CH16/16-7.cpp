#include <iostream>
#include <string>

using namespace std;

template<typename T, unsigned int N>
constexpr int Size(T (&arr)[N])
{
	return N;
}

int main()
{
	int arr1[] = {1, 2, 3, 4, 5, 6, 7};
	string arr2[] = { "gao", "xiang", "number", "one" };
	cout << Size(arr1) << ' ' << Size(arr2) << '\n';

	return 0;
}
