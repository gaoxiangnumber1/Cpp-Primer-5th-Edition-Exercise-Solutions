#include "Sales_data.h"

int main()
{
	Sales_data book;
	double price;
	cin >> book.bookNo >> book.units_sold >> price;
	book.CalcRevenue(price);
	book.Print();

	return 0;
}
