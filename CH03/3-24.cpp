#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int main()
{
	vector<int> vec;
	int input = 0, length = 1;
	cin >> input;
	vec.push_back(input);

	// First print the sum of each pair of adjacent elements:
	cout << "Sum of each pair of adjacent elements:\n";
	int first = input;
	while(cin >> input)
	{
		cout << first + input << ' ';
		first = input;
		vec.push_back(input);
		++length;
	}

	// Second print the sum of the first and last elements, and so on.
	cout << "\nSum of the first and last elements, and so on:\n";
	vector<int>::const_iterator it1 = vec.cbegin(), it2 = it1 + length / 2, it3 = vec.cend() - 1;
	for( ; it1 != it2; ++it1, --it3)
	{
		cout << *it1 + *it3 << ' ';
	}

	return 0;
}
