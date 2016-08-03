#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

struct Sale_data
{
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main()
{
	Sale_data total;
	double totalPrice;

	if (cin >> total.bookNo >> total.units_sold >> totalPrice)
	{
		total.revenue = total.units_sold * totalPrice;
		Sale_data trans;
		double transPrice;
		while (cin >> trans.bookNo >> trans.units_sold >> transPrice)
		{
			trans.revenue = trans.units_sold * transPrice;
			if (total.bookNo == trans.bookNo)
			{
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			}
			else
			{
				cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
				if (total.units_sold != 0)
				{
					cout << total.revenue / total.units_sold << endl;
				}
				else
				{
					cout << "(no sales)" << endl;
				}
				total.bookNo = trans.bookNo;
				total.units_sold = trans.units_sold;
				total.revenue = trans.revenue;
			}
		}
		cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
		if (total.units_sold != 0)
		{
			cout << total.revenue / total.units_sold << endl;
		}
		else
		{
			cout << "(no sales)" << endl;
		}
		return 0;
	}
	else
	{
		cerr << "No data?!" << endl;
		return -1;  // indicate failure
	}
}
