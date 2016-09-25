#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
public:
	friend void swap(HasPtr&, HasPtr&);
	HasPtr(const string& s = string());
	HasPtr(const HasPtr& hp);
	HasPtr(HasPtr&& p) noexcept;
	HasPtr& operator=(HasPtr rhs);
	/*
	HasPtr& operator=(const HasPtr &rhs);
	HasPtr& operator=(HasPtr &&rhs) noexcept;
	*/
	~HasPtr();

private:
	string* ps;
	int i;
};

inline void swap(HasPtr& lhs, HasPtr& rhs)
{
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	cout << "call swap" << endl;
}

HasPtr::HasPtr(const string& s) : ps(new string(s)), i(0)
{
	cout << "call constructor" << endl;
}

HasPtr::HasPtr(const HasPtr& hp) : ps(new string(*hp.ps)), i(hp.i)
{
	cout << "call copy constructor" << endl;
}

HasPtr::HasPtr(HasPtr&& p) noexcept :
ps(p.ps), i(p.i)
{
	p.ps = 0;
	cout << "call move constructor" << endl;
}

HasPtr& HasPtr::operator=(HasPtr rhs)
{
	swap(*this, rhs);
	return *this;
}

/*
HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    cout << "call copy assignment" << endl;
    return *this;
}

HasPtr& HasPtr::operator=(HasPtr &&rhs) noexcept
{
    if (this != &rhs)
    {
        delete ps;
        ps = rhs.ps;
        i = rhs.i;
        rhs.ps = nullptr;
        cout << "call move assignment" << endl;
    }
    return *this;
}
*/

HasPtr::~HasPtr()
{
	cout << "call destructor" << endl;
	delete ps;
}

int main()
{
	HasPtr hp1("hello"), hp2("World"), *pH = new HasPtr("World");
	hp1 = hp2;
	hp1 = move(*pH);
}
