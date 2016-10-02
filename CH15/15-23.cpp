#include <iostream>

using namespace std;

class Base
{
public:
	virtual int fcn()
	{
		cout << "Base::fcn()\n";
		return 0;
	}
};

class D1 : public Base
{
public:
	int fcn() override
	{
		cout << "D1::fcn()\n";
		return 0;
	}
	virtual void f2()
	{
		cout << "D1::f2()\n";
	}
};

class D2 : public D1
{
public:
	int fcn(int)
	{
		cout << "D2::fcn(int)\n";
	}
	int fcn() override
	{
		cout << "D2::fcn()\n";
		return 0;
	}
	void f2() override
	{
		cout << "D2::f2()\n";
	}
};

int main()
{
	Base bobj;
	D1 d1obj;
	D2 d2obj;

	Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
	bp1->fcn(); // virtual call, will call Base::fcn at run time
	bp2->fcn(); // virtual call, will call D1::fcn at run time
	bp3->fcn(); // virtual call, will call D2::fcn at run time

	D1 *d1p = &d1obj;
	D2 *d2p = &d2obj;
	//bp2->f2(); // error: ‘class Base’ has no member named ‘f2’
	d1p->f2(); // virtual call, will call D1::f2() at run time
	d2p->f2(); // virtual call, will call D2::f2() at run time

	return 0;
}
/*
Output:
Base::fcn()
D1::fcn()
D2::fcn()
D1::f2()
D2::f2()
*/
