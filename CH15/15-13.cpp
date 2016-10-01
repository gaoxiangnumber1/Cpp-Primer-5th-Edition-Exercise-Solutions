#include <iostream>
#include <string>

using namespace std;

class base
{
public:
	string name()
	{
		return basename;
	}
	virtual void print(ostream &os)
	{
		os << basename << '\n';
	}
private:
	string basename = "default";
};

class derived : public base
{
public:
	void print(ostream &os)
	{
		base::print(os);
		os << i << '\n';
	}
private:
	int i = 7188;
};

int main()
{
	base obj1;
	derived obj2;
	obj1.print(cout);
	obj2.print(cout);

	return 0;
}
