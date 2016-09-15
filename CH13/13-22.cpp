#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
public:
	HasPtr(const string &s = string()) : ps(new string(s)), id(0) {}
	HasPtr(const HasPtr &orig) : ps(new string(*(orig.ps))), id(orig.id) {}
	HasPtr &operator=(const HasPtr &rhs)
	{
		ps = new string(*(rhs.ps));
		id = rhs.id;
	}
	~HasPtr()
	{
		delete ps;
	}

	void get_ps() const
	{
		cout << *ps << '\n';
	}
	void set_ps(const string &str)
	{
		delete ps;
		ps = new string(str);
	}

private:
	string *ps;
	int id;
};

int main()
{
	HasPtr obj1("gao"), obj2 = obj1;
	obj1.get_ps();
	obj2.get_ps();

	cout << "After modify obj2:\n";
	obj2.set_ps(string("xiang"));
	obj1.get_ps();
	obj2.get_ps();

	return 0;
}
/*
Output:
gao
gao
After modify obj2:
gao
xiang
*/
