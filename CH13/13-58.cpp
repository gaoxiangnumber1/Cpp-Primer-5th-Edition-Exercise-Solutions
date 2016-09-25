#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Foo
{
public:
	Foo sorted() &&;
	Foo sorted() const &;

private:
	vector<int> data;
};

Foo Foo::sorted() &&
{
	sort(data.begin(), data.end());
	cout << "&&" << endl; // debug
	return *this;
}

Foo Foo::sorted() const &
{
//    Foo ret(*this);
//    sort(ret.data.begin(), ret.data.end());
//    return ret;

	cout << "const &" << endl; // debug

//    Foo ret(*this);
//    ret.sorted();     // Exercise 13.56
//    return ret;

	return Foo(*this).sorted(); // Exercise 13.57
}

int main()
{
	Foo().sorted(); // call "&&"
	Foo f;
	f.sorted(); // call "const &"
}
