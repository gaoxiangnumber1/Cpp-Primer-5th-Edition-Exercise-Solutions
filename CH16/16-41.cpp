// Only type that support `this + 0` can be passed. The return type depends on
// the type that operator + returns. In the case below, the return type is Bar.

#include <iostream>
#include <vector>
#include <string>

class Bar {};

Bar operator +(Bar lhs, int)
{
	return lhs;
}

template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
	return *beg;  // return a copy of an element from the range
}

int main()
{
	std::vector<Bar> v;
	v.push_back(Bar());
	Bar b = fcn3(v.begin(), v.end());
}
