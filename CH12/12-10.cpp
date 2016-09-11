#include <iostream>
#include <memory>

using namespace std;

void process(shared_ptr<int> ptr)
{
	cout << "ptr =\t" << ptr << ": reference_count = " << ptr.use_count() << '\n';
}

int main()
{
	shared_ptr<int> p(new int(1));
	process(shared_ptr<int>(p));

	return 0;
}
