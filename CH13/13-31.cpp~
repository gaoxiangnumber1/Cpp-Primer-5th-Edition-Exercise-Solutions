#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class HasPtr
{
	friend bool operator<(const HasPtr &, const HasPtr&);

public:
	HasPtr(const string &s = string()) : ps(new string(s)), id(0) {}
	HasPtr(const HasPtr &orig) : ps(new string(*(orig.ps))), id(orig.id) {}
	//HasPtr &operator=(HasPtr rhs) = delete;
	HasPtr &operator=(HasPtr rhs)
	{
		cout << "operator=: left-obj = " << *ps <<
		     ", right-obj = " << *rhs.ps << ". -> ";
		this->swap(rhs);
		return *this;
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

	void swap(HasPtr &rhs)
	{
		cout << *ps << ".swap(" << *rhs.ps << ")\n";
		std::swap(ps, rhs.ps);
		std::swap(id, rhs.id);
	}

private:
	string *ps;
	int id;
};

bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
	return *lhs.ps < *rhs.ps;
}

int main()
{
	HasPtr obj1("d"), obj2("c"), obj3("b"), obj4("a");
	vector<HasPtr> vec {obj1, obj2, obj3, obj4};
	cout << "Before sort:\t";
	for(int index = 0; index < 4; ++index)
	{
		cout << vec[index].get_ps() << ' ';
	}
	cout << "\n\n";
	sort(vec.begin(), vec.end());

	cout << "\nAfter sort:\t";
	for(int index = 0; index < 4; ++index)
	{
		cout << vec[index].get_ps() << ' ';
	}

	return 0;
}
/*
Output1: when define copy-assignment operator
Before sort:	d c b a

operator=: left-obj = c, right-obj = d. -> c.swap(d)
operator=: left-obj = d, right-obj = c. -> d.swap(c)
operator=: left-obj = b, right-obj = d. -> b.swap(d)
operator=: left-obj = d, right-obj = c. -> d.swap(c)
operator=: left-obj = c, right-obj = b. -> c.swap(b)
operator=: left-obj = a, right-obj = d. -> a.swap(d)
operator=: left-obj = d, right-obj = c. -> d.swap(c)
operator=: left-obj = c, right-obj = b. -> c.swap(b)
operator=: left-obj = b, right-obj = a. -> b.swap(a)

After sort:	a b c d
*/
/*
Output2: when not define copy-assignment operator
Before sort:	d c b a


*** Error in `cpp': free(): invalid pointer: 0x0000000001d57148 ***
After sort:	!�q� !�q� !�q� d Aborted
*/
/*
Output3: when "HasPtr &operator=(HasPtr rhs) = delete;"
error: use of deleted function ‘HasPtr& HasPtr::operator=(HasPtr)’
*/
