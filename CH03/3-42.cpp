#include <iostream>
#include <vector>

using std::vector;

int main()
{
	vector<int> vec(10, 5);
	int length = vec.size();
	int arr[length];
	for(int index = 0; index < length; ++index)
	{
		arr[index] = vec[index];
	}

	return 0;
}
