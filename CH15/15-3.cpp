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
	virtual ~Quote() = default; // dynamic binding for the destructor

private:
	string bookNo; // ISBN number of this item

protected:
	double price = 0.0; // normal, un-discounted price
};

class Bulk_quote: public Quote // Bulk_quote inherits from Quote
{
public:
	double net_price(size_t) const override;
};

double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: "
	   << n << " total due: " << ret << endl;
	return ret;
}
