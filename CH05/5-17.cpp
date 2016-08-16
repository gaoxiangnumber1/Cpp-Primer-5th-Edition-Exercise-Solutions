#include <iostream>
#include <vector>

using std::cout;
using std::vector;

bool IsPrefix(vector<int> &lhs, vector<int> &rhs)
{
	if(lhs.size() > rhs.size())
	{
		return IsPrefix(rhs, lhs);
	}
	for(int index = 0; index != lhs.size(); ++index)
	{
		if(lhs[index] != rhs[index])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	vector<int> vec1 = { 0, 1, 1, 2 };
	vector<int> vec2 = { 0, 1, 1, 2, 3, 5, 8 };
	cout << (IsPrefix(vec1, vec2) ? "Yes\n" : "No\n");

	return 0;
}
