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
	Sale_data book1, book2;
	double price1, price2;
	cin >> book1.bookNo >> book1.units_sold >> price1;
	cin >> book2.bookNo >> book2.units_sold >> price2;
	book1.revenue = book1.units_sold * price1;
	book2.revenue = book2.units_sold * price2;

	if(book1.bookNo == book2.bookNo)
	{
		unsigned totalCnt = book1.units_sold + book2.units_sold;
		double totalRevenue = book1.revenue + book2.revenue;
		cout << book1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
		if (totalCnt != 0)
		{
			cout << totalRevenue / totalCnt << endl;
		}
		else
		{
			cout << "(no sales)" << endl;
		}
		return 0;
	}
	else
	{
		cerr << "Data must refer to same ISBN" << endl;
		return -1; // indicate failure
	}
}
