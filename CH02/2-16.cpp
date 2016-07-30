#include <iostream>

using std::cout;

int main()
{
	int i = 0, &r1 = i;
	double d = 0, &r2 = d;
	cout << i << '\t' << r1 << '\t' << d << '\t' << r2 << '\n';

	r2 = 3.14159;
	cout << i << '\t' << r1 << '\t' << d << '\t' << r2 << '\n';

	r2 = r1;
	cout << i << '\t' << r1 << '\t' << d << '\t' << r2 << '\n';

	i = r2;
	cout << i << '\t' << r1 << '\t' << d << '\t' << r2 << '\n';

	r1 = d;
	cout << i << '\t' << r1 << '\t' << d << '\t' << r2 << '\n';

	return 0;
}
/*
Output:
0	0	0	0
0	0	3.14159	3.14159
0	0	0	0
0	0	0	0
0	0	0	0
*/
