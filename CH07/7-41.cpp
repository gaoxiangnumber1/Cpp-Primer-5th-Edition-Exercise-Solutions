#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::istream;

class Sales_data
{
public:
	Sales_data(string s, unsigned cnt, double price) :
		bookNo(s), units_sold(cnt), revenue(cnt*price)
	{
		cout << "Sales_data(string s, unsigned cnt, double price)\n";
	}

	Sales_data() : Sales_data("", 0, 0)
	{
		cout << "Sales_data() : Sales_data("", 0, 0)\n";
	}
	Sales_data(string s) : Sales_data(s, 0,0)
	{
		cout << "Sales_data(string s) : Sales_data(s, 0,0)\n";
	}
	Sales_data(istream &is) : Sales_data()
	{
		cout << "Sales_data(istream &is) : Sales_data()\n";
	}

private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main()
{
	cout << "Sales_data obj1:\n";
	Sales_data obj1;
	cout << "\nSales_data obj2(""gaoxiangnumber1""):\n";
	Sales_data obj2("gaoxiangnumber1");
	cout << "\nSales_data obj3(cin):\n";
	Sales_data obj3(cin);
	cout << "\nSales_data obj4(""gao"", 71, 8.8):\n";
	Sales_data obj4("gao", 71, 8.8);

	return 0;
}
/*
Output:
Sales_data obj1:
Sales_data(string s, unsigned cnt, double price)
Sales_data() : Sales_data(, 0, 0)

Sales_data obj2(gaoxiangnumber1):
Sales_data(string s, unsigned cnt, double price)
Sales_data(string s) : Sales_data(s, 0,0)

Sales_data obj3(cin):
Sales_data(string s, unsigned cnt, double price)
Sales_data() : Sales_data(, 0, 0)
Sales_data(istream &is) : Sales_data()

Sales_data obj4(gao, 71, 8.8):
Sales_data(string s, unsigned cnt, double price)
*/
