#include <iostream>
#include <string>

using namespace std;

template<typename T, unsigned int N>
void Print(const T (&arr)[N])
{
	for(int index = 0; index < N; ++index)
	{
		cout << arr[index] << ' ';
	}
	cout << '\n';
}

int main()
{
	int arr1[] = {1, 2, 3, 4, 5, 6, 7};
	string arr2[] = { "gao", "xiang", "number", "one" };
	Print(arr1);
	Print(arr2);

	return 0;
}
