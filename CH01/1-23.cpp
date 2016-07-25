#include "Sales_item.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	Sales_item current_item, input_item;
	if (cin >> current_item)
	{
		int cnt = 1;
		while (cin >> input_item)
		{
			if (input_item.isbn() == current_item.isbn())
			{
				++cnt;
			}
			else
			{
				cout << current_item << " occurs " << cnt << " times " << endl;
				current_item = input_item;
				cnt = 1;
			}
		}
		cout << current_item << " occurs " << cnt << " times " << endl;
	}
	return 0;
}
