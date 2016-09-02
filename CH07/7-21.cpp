#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::istream;
using std::ostream;

class Sales_data;
istream& read(istream &, Sales_data &);
ostream& print(ostream &, const Sales_data &);
Sales_data add(const Sales_data &, const Sales_data &);

class Sales_data
{
	friend istream& read(istream &, Sales_data &);
	friend ostream& print(ostream &, const Sales_data &);
	friend Sales_data add(const Sales_data &, const Sales_data &);

public:
	Sales_data() = default;
	Sales_data(const string &str) : bookNo(str) {}
	Sales_data(const string &str, unsigned n, double p) :
		bookNo(str), units_sold(n), revenue(p * n) {}
	Sales_data(istream &is)
	{
		read(is, *this);
	}
	string isbn() const
	{
		return bookNo;
	}
	Sales_data& combine(const Sales_data &rhs);

private:
	double avg_price() const
	{
		return units_sold == 0 ? 0 : revenue / units_sold;
	}
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
	Sales_data total(cin);
	if(total.isbn().empty() == false)
	{
		while(cin)
		{
			Sales_data trans(cin);
			if(total.isbn() == trans.isbn())
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
