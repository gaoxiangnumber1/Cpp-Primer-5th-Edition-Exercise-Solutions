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
	virtual void Debug() const
	{
		cout << "bookNo = " << bookNo << ", price = " << price << '\n';
	}

protected:
	string bookNo = ""; // ISBN number of this item
	double price = 0.0; // normal, undiscounted price
};

// class to hold the discount rate and quantity
// derived classes will implement pricing strategies using these data
class Disc_quote : public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const string& book, double price, size_t qty, double disc):
		Quote(book, price), quantity(qty), discount(disc) {}
	double net_price(size_t) const = 0;

protected:
	size_t quantity = 0; // purchase size for the discount to apply
	double discount = 0.0; // fractional discount to apply
};

// the discount kicks in when a specified number of copies of the same book are sold
// the discount is expressed as a fraction to use to reduce the normal price
class Bulk_quote: public Disc_quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const string& book, double price, size_t qty, double disc):
		Disc_quote(book, price, qty, disc) {}
	// overrides the base version to implement the bulk purchase discount policy
	double net_price(size_t) const override;
};

// if the specified number of items are purchased, use the discounted price
double Bulk_quote::net_price(size_t cnt) const
{
	if(cnt >= quantity)
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
	Quote obj1;
	//Disc_quote obj2;
	Bulk_quote obj3;//("", 0, 0, 0);

	return 0;
}
