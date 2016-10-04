#include <iostream>

using namespace std;

template<typename T>
int compare(const T &v1, const T &v2)
{
	if(less<T>()(v1, v2))
	{
		return -1;
	}
	if(less<T>()(v2, v1))
	{
		return 1;
	}
	return 0;
}

int main()
{
	cout << compare(1, 2);

	return 0;
}
