#include <iostream>
#include <vector>

using namespace std;

struct X
{
	X(string id) : id_(id)
	{
		cout << "X(): id = " << id_ << "\n";
	}
	X(const X &orig) : id_(orig.id_)
	{
		cout << "X(const X&): id = " << id_ << "\n";
	}
	X &operator=(const X &)
	{
		cout << "X &operator=(const X &): id = " << id_ << "\n";
		return *this;
	}
	~X()
	{
		cout << "~X(): id = " << id_ << "\n";
	}
	string id_;
};

void Fun1(X obj)
{
	cout << "Fun1(X): id = " << obj.id_ << "\n";
}

void Fun2(X &obj)
{
	cout << "Fun2(X&): id = " << obj.id_ << "\n";
}

int main()
{
	X obj1("obj1");
	Fun1(obj1);
	Fun2(obj1);
	X *obj2 = new X("obj2");
	vector<X> vec(5, string("obj3"));
	delete obj2;
	cout << "EXIT\n";

	return 0;
}
/*
Output:
X(): id = obj1
X(const X&): id = obj1
Fun1(X): id = obj1
~X(): id = obj1
Fun2(X&): id = obj1
X(): id = obj2
X(): id = obj3
X(const X&): id = obj3
X(const X&): id = obj3
X(const X&): id = obj3
X(const X&): id = obj3
X(const X&): id = obj3
~X(): id = obj3
~X(): id = obj2
EXIT
~X(): id = obj3
~X(): id = obj3
~X(): id = obj3
~X(): id = obj3
~X(): id = obj3
~X(): id = obj1
*/
