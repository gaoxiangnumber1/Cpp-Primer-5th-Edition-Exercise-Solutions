#include <iostream>
#include <string>

using namespace std;

class Quote
{
public:
	Quote() = default;
	Quote(const string &book, double sales_price):
		bookNo(book), price(sales_price) {}
	string isbn() const
	{
		return bookNo;
	}

	virtual double net_price(size_t n) const
	{
		return n * price;
	}
	virtual ~Quote() = default;

private:
	string bookNo; // ISBN number of this item

protected:
	double price = 0.0; // normal, undiscounted price
};

class Bulk_quote: public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const string &book, double p, size_t qty, double disc):
		Quote(book, p), min_qty(qty), discount(disc) {}
	double net_price(size_t) const override;

private:
	size_t min_qty = 0; // minimum purchase for the discount to apply
	double discount = 0.0; // fractional discount to apply
};

// if the specified number of items are purchased, use the discounted price
double Bulk_quote::net_price(size_t cnt) const
{
	if(cnt >= min_qty)
	{
		return cnt * (1 - discount) * price;
	}
	else
	{
		return cnt * price;
	}
}

double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: "
	   << n << " total due: " << ret << endl;
	return ret;
}

int main()
{
	Quote base("hello", 100);
	Bulk_quote derive("world", 100, 5, 0.1);
	print_total(cout, base, 10);
	print_total(cout, derive, 10);

	return 0;
}
/*
Output:
ISBN: hello # sold: 10 total due: 1000
ISBN: world # sold: 10 total due: 900
*/
