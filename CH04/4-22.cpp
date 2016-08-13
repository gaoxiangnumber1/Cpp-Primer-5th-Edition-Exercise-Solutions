#include <iostream>

using std::cout;
using std::cin;

int main()
{
	int grade;
	while(cin >> grade)
	{
		cout << ((grade > 90) ? "high pass" :
		         ((grade < 60) ? "fail" :
		          ((grade > 75) ? "pass" : "low pass")));
		cout << '\t';
		if(grade > 90)
		{
			cout << "high pass";
		}
		else if(grade < 60)
		{
			cout << "fail";
		}
		else if(grade > 75)
		{
			cout << "pass";
		}
		else
		{
			cout << "low pass";
		}
		cout << '\n';
	}

	return 0;
}
