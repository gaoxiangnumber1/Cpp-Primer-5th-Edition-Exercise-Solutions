#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::istream;
using std::ostream;

struct Sales_data
{
	Sales_data() = default;
	Sales_data(const string &str) : bookNo(str) {}
	Sales_data(const string &str, unsigned n, double p) :
		bookNo(str), units_sold(n), revenue(p * n) {}
	Sales_data(istream &);

	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

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

Sales_data::Sales_data(istream &is)
{
	read(is, *this);
}

int main()
{
	Sales_data obj1;
	Sales_data obj2("gaoxiang");
	Sales_data obj3("gao", 71, 8.8);
	Sales_data obj4(cin);

	print(cout, obj1);
	print(cout, obj2);
	print(cout, obj3);
	print(cout, obj4);

	return 0;
}
