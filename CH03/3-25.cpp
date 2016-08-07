#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int main()
{
	vector<int> scores(11, 0);
	int grade;
	while (cin >> grade)
	{
		if(grade <= 100)
		{
			++(*(scores.begin() + grade / 10));
		}
	}

	for(int score : scores)
	{
		cout << score << " ";
	}
	cout << '\n';

	return 0;
}
