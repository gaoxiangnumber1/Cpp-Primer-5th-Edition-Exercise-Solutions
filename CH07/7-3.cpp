#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

struct Sales_data
{
	string isbn() const
	{
		return bookNo;
	}
	Sales_data& combine(const Sales_data &rhs);
	double avg_price() const;

	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

double Sales_data::avg_price() const
{
	return units_sold == 0 ? 0 : revenue / units_sold;
}

int main()
{
	Sales_data total;
	if(cin >> total.bookNo >> total.units_sold >> total.revenue)
	{
		Sales_data trans;
		while(cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
		{
			if(total.bookNo == trans.bookNo)
			{
				total.combine(trans);
			}
			else
			{
				cout << total.bookNo << " " << total.units_sold << " " << total.revenue << '\n';
				total = trans;
			}
		}
		cout << total.bookNo << " " << total.units_sold << " " << total.revenue << '\n';
	}
	else
	{
		cout << "No data?!" << '\n';
		return -1;
	}
	return 0;
}
