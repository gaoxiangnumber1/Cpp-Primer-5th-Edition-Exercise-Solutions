#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
	friend void swap(HasPtr &, HasPtr&);

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

	const string &get_ps() const
	{
		return *ps;
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

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
	cout << "\nswap value-like HasPtr\n";
	swap(lhs.ps, rhs.ps);
	swap(lhs.id, rhs.id);
}

int main()
{
	HasPtr obj1("gao"), obj2 = obj1;
	cout << "obj1.get_ps() = " << obj1.get_ps() << '\n';
	cout << "obj2.get_ps() = " << obj2.get_ps() << '\n';

	cout << "\nAfter modify obj2:\n";
	obj2.set_ps(string("xiang"));
	cout << "obj1.get_ps() = " << obj1.get_ps() << '\n';
	cout << "obj2.get_ps() = " << obj2.get_ps() << '\n';

	swap(obj1, obj2);
	cout << "\nAfter swap obj1 and obj2:\n";
	cout << "obj1.get_ps() = " << obj1.get_ps() << '\n';
	cout << "obj2.get_ps() = " << obj2.get_ps() << '\n';

	return 0;
}
/*
Output:
obj1.get_ps() = gao
obj2.get_ps() = gao

After modify obj2:
obj1.get_ps() = gao
obj2.get_ps() = xiang

swap value-like HasPtr

After swap obj1 and obj2:
obj1.get_ps() = xiang
obj2.get_ps() = gao
*/
