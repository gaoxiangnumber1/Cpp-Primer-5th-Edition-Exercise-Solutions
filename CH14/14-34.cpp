#include <iostream>

using namespace std;

struct Choose
{
	int operator()(int a, int b, int c)
	{
		return a != 0 ? b : c;
	}
};

int main()
{
	Choose obj;
	cout << obj(1, 2, 3) << '\n'; // 2
	cout << obj(0, -1, 1); // 1

	return 0;
}
