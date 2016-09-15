#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;

class numbered1
{
	friend void f1(numbered1);

public:
	numbered1()
	{
		num = ++cnt;
		cout << "numbered1(): cnt = " << cnt << '\n';
	}

private:
	int num;
};

void f1(numbered1 s)
{
	cout << s.num << '\n';
}

class numbered2
{
	friend void f2(numbered2);
	friend void f3(const numbered2 &);

public:
	numbered2()
	{
		num = ++cnt;
		cout << "numbered2(): cnt = " << cnt << '\n';
	}
	numbered2(const numbered2 &orig)
	{
		cout << "numbered2(const numbered2 &): old num = " << num;
		num = ++cnt;
		cout << ", new num = " << cnt << '\n';
	}

private:
	int num;
};

void f2(numbered2 s)
{
	cout << s.num << '\n';
}

void f3(const numbered2 &s)
{
	cout << s.num << '\n';
}

int main()
{
	numbered1 a1, b1 = a1, c1 = b1;
	f1(a1);
	f1(b1);
	f1(c1);

	cout << "###" << cnt << "###\n";

	numbered2 a2, b2 = a2, c2 = b2;
	f2(a2);
	f2(b2);
	f2(c2);

	cout << "###" << cnt << "###\n";

	f3(a2);
	f3(b2);
	f3(c2);

	cout << "###" << cnt << "###\n";
	return 0;
}
/*
Output:
numbered1(): cnt = 1
1
1
1
###1###
numbered2(): cnt = 2
numbered2(const numbered2 &): old num = 2, new num = 3
numbered2(const numbered2 &): old num = 1, new num = 4
numbered2(const numbered2 &): old num = 4197328, new num = 5
5
numbered2(const numbered2 &): old num = 5, new num = 6
6
numbered2(const numbered2 &): old num = 6, new num = 7
7
###7###
2
3
4
###7###
*/
