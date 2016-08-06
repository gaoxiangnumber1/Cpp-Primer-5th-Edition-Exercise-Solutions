#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

void Print(vector<int> &vec)
{
	int length = vec.size();
	for(int index = 0; index < length; ++index)
	{
		cout << vec[index] << " ";
	}
	cout << '\n';
}

int main()
{
	vector<int> vec;
	for(int num = 0; cin >> num; )
	{
		vec.push_back(num);
	}
	Print(vec);

	return 0;
}
