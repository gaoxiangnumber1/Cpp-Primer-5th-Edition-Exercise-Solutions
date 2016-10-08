#include <vector>

using namespace std;

class NoDefault
{
public:
	NoDefault(int){}
};

// error: no matching function for call to ‘NoDefault::NoDefault()’|
template class vector<NoDefault>;

int main()
{
	return 0;
}
