#include <iostream>
#include <string>

using std::string;
using std::istream;

struct Sales_data;
istream& read(istream &is, Sales_data &item);

struct Sales_data
{
	Sales_data() = default;
	Sales_data(const string &str) : bookNo(str) {}
	Sales_data(const string &str, unsigned n, double p) :
		bookNo(str), units_sold(n), revenue(p * n) {}
	Sales_data(istream &is)
	{
		read(is, *this);
	}

	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
