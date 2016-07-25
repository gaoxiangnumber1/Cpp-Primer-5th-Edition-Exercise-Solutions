#include "Sales_item.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	for(Sales_Item item; cin >> item; cout << item << endl);
	return 0;
}
