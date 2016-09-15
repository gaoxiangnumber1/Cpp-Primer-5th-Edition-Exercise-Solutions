#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
public:
	HasPtr(const string &s1, const string &s2) :
		name(s1), ps(new string(s2)), id(0), use(new size_t(1))
	{
		cout << "Constructor:\tname = " << name << ", *ps = " << *ps
		     << ", ref_count = " << *use << '\n';
	}
	HasPtr(const HasPtr &orig) : ps(orig.ps), id(orig.id), use(orig.use)
	{
		++*use;
		cout << "Copy-Construct:\tname = " << name << ", *ps = " << *ps
		     << ", ref_count = " << *use << '\n';
	}
	HasPtr &operator=(const HasPtr &rhs)
	{
		cout << "Copy-operator:\t";
		cout << "left-hand: name = " << name << ", *ps = " << *ps
		     << ", ref_count = " << *use << '\n';
		cout << "\t\tright-hand: name = " << rhs.name << ", *ps = " << *rhs.ps
		     << ", ref_count = " << *rhs.use << '\n';
		++*rhs.use;
		if(--*use == 0)
		{
			cout << "\t\tRunning left-hand obj's Destructor.\n";
			delete ps;
			delete use;
		}
		ps = rhs.ps;
		id = rhs.id;
		use = rhs.use;
		cout << "Copy-op finish:\tname = " << name << ", *ps = " << *ps
		     << ", ref_count = " << *use << '\n';
		return *this;
	}
	~HasPtr()
	{
		cout << "Destructor:\tBefore --*use: name = " << name << ", *ps = " << *ps
		     << ", ref_count = " << *use << '\n';
		if(--*use == 0)
		{
			delete ps;
			delete use;
			cout << "\t\t--*use = 0: destroy object.\n";
		}
		else
		{
			cout << "\t\t--*use = " << *use << ", not destroy object.\n";
		}
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
	string name = "default";
	string *ps;
	int id;
	size_t *use;
};

int main()
{
	HasPtr obj1("obj1", "gao");
	HasPtr obj2(obj1);
	HasPtr obj3("obj3", "xiang");
	obj3 = obj2;
	obj2.set_ps("gaoxiangnumber1");

	return 0;
}
/*
Output:
Constructor:	name = obj1, *ps = gao, ref_count = 1
Copy-Construct:	name = default, *ps = gao, ref_count = 2
Constructor:	name = obj3, *ps = xiang, ref_count = 1
Copy-operator:	left-hand: name = obj3, *ps = xiang, ref_count = 1
		right-hand: name = default, *ps = gao, ref_count = 2
		Running left-hand obj's Destructor.
Copy-op finish:	name = obj3, *ps = gao, ref_count = 3
Destructor:	Before --*use: name = obj3, *ps = gaoxiangnumber1, ref_count = 3
		--*use = 2, not destroy object.
Destructor:	Before --*use: name = default, *ps = gaoxiangnumber1, ref_count = 2
		--*use = 1, not destroy object.
Destructor:	Before --*use: name = obj1, *ps = gaoxiangnumber1, ref_count = 1
		--*use = 0: destroy object.
*/
