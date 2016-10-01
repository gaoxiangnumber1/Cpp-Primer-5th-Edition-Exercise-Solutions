#include <iostream>

using namespace std;

class Base
{
public:
	int pub_mem;
protected:
	int prot_mem;
private:
	char priv_mem;
};

struct Pub_Derv: public Base {};
struct Priv_Derv: private Base {};
struct Prot_Derv: protected Base {};

struct Derived_from_Public: public Pub_Derv {};
struct Derived_from_Private: public Priv_Derv {};
struct Derived_from_Protected: public Prot_Derv {};

int main()
{
	Pub_Derv d1;
	Priv_Derv d2;
	Prot_Derv d3;
	Derived_from_Public dd1;
	Derived_from_Private dd2;
	Derived_from_Protected dd3;

	Base *p = &d1; // d1 has type Pub_Derv
//	p = &d2; // d2 has type Priv_Derv
//	p = &d3; // d3 has type Prot_Derv
	p = &dd1; // dd1 has type Derived_from_Public
//	p = &dd2; // dd2 has type Derived_from_Private
//	p = &dd3; // dd3 has type Derived_from_Protected

	return 0;
}
