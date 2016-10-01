#include <iostream>
#include <string>

using namespace std;

class base
{
public:
	void name()
	{
		cout << basename << '\n';
	}
	virtual void print()
	{
		cout << "base\n";
	}

private:
	string basename = "default";
};

class derived : public base
{
public:
	void print()
	{
		cout << "derived\n";
	}

private:
	int i = 7188;
};

int main()
{
	base bobj;
	base *bp1 = &bobj;
	base &br1 = bobj;
	derived dobj;
	base *bp2 = &dobj;
	base &br2 = dobj;

	bobj.print();
	dobj.print();
	bp1->name();
	bp2->name();
	br1.print();
	br2.print();

	return 0;
}
/*
Output:
base
derived
default
default
base
derived
*/
