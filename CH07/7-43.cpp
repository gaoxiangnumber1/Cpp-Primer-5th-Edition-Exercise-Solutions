#include <iostream>

class NoDefault
{
public:
	NoDefault(int) {}
};

class C
{
public:
	C() : no_default_(0) {}

private:
	NoDefault no_default_;
};

int main()
{
	C obj_c;
	NoDefault obj_no_default(0);

	return 0;
}
