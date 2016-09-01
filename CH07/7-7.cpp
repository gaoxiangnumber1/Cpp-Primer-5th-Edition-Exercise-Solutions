#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::istream;
using std::ostream;

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

istream& read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream& print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << ' ' << item.units_sold << ' ' << item.revenue <<
	   ' ' << item.avg_price() << '\n';
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

int main()
{
	Sales_data total;
	if(read(cin, total))
	{
		Sales_data trans;
		while(read(cin, trans))
		{
			if(total.bookNo == trans.bookNo)
			{
				total.combine(trans);
			}
			else
			{
				print(cout, total);
				total = trans;
			}
		}
		print(cout, total);
	}
	else
	{
		cout << "No data?!" << '\n';
		return -1;
	}
	return 0;
}
