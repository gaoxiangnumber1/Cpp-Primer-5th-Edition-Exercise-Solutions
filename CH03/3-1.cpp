/************************* 1.9 *************************/
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int num = 50, sum = 0;
	while(num <= 100)
	{
		sum += num;
		++num;
	}
	cout << "The sum from 50 to 100 is " << sum << endl;

	return 0;
}

/************************* 1.10 *************************/
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int num = 10;
	while(num >= 0)
	{
		cout << num << endl;
		--num;
	}

	return 0;
}

/************************* 1.11 *************************/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int small = 0, big = 0;
	cout << "Please input 2 integers: ";
	cin >> small >> big;

	if(small > big)
	{
		int temp = small;
		small = big;
		big = small;
	}

	// Print integers in the range [num1, num2]:
	while(small <= big)
	{
		cout << small << endl;
		++small;
	}

	return 0;
}

/****************************** 1.5.1 ******************************/
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;

struct Sale_data
{
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main()
{
	Sale_data book;
	double price;
	cin >> book.bookNo >> book.units_sold >> price;
	book.revenue = book.units_sold * price;
	cout << book.bookNo << " " << book.units_sold << " " << book.revenue << " " << price;

	return 0;
}

/****************************** 1.5.2 ******************************/
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

struct Sale_data
{
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main()
{
	Sale_data book1, book2;
	double price1, price2;
	cin >> book1.bookNo >> book1.units_sold >> price1;
	cin >> book2.bookNo >> book2.units_sold >> price2;
	book1.revenue = book1.units_sold * price1;
	book2.revenue = book2.units_sold * price2;

	if(book1.bookNo == book2.bookNo)
	{
		unsigned totalCnt = book1.units_sold + book2.units_sold;
		double totalRevenue = book1.revenue + book2.revenue;
		cout << book1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
		if (totalCnt != 0)
		{
			cout << totalRevenue / totalCnt << endl;
		}
		else
		{
			cout << "(no sales)" << endl;
		}
		return 0;
	}
	else
	{
		cerr << "Data must refer to same ISBN" << endl;
		return -1; // indicate failure
	}
}

/****************************** 1.6 ******************************/
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

struct Sale_data
{
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main()
{
	Sale_data total;
	double totalPrice;

	if (cin >> total.bookNo >> total.units_sold >> totalPrice)
	{
		total.revenue = total.units_sold * totalPrice;
		Sale_data trans;
		double transPrice;
		while (cin >> trans.bookNo >> trans.units_sold >> transPrice)
		{
			trans.revenue = trans.units_sold * transPrice;
			if (total.bookNo == trans.bookNo)
			{
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			}
			else
			{
				cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
				if (total.units_sold != 0)
				{
					cout << total.revenue / total.units_sold << endl;
				}
				else
				{
					cout << "(no sales)" << endl;
				}
				total.bookNo = trans.bookNo;
				total.units_sold = trans.units_sold;
				total.revenue = trans.revenue;
			}
		}
		cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
		if (total.units_sold != 0)
		{
			cout << total.revenue / total.units_sold << endl;
		}
		else
		{
			cout << "(no sales)" << endl;
		}
		return 0;
	}
	else
	{
		cerr << "No data?!" << endl;
		return -1;  // indicate failure
	}
}
