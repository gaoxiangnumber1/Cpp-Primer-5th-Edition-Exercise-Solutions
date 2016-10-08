#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename elemType> class ListItem;
template <typename elemType>
class List
{
public:
	List<elemType>(){}
	List<elemType>(const List<elemType> &);
	List<elemType>& operator=(const List<elemType> &);
	~List(){}
	void insert(ListItem<elemType> *ptr, elemType value);//error: ‘ListItem’ is not a type|
private:
	ListItem<elemType> *front, *end;//error: invalid use of template-name ‘ListItem’ without an argument list|
};

int main()
{
	List<int> obj;

	return 0;
}
