#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

struct Sales_data
{
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	void CalcRevenue(double price);
	double CalcAveragePrice();
	void SetData(Sales_data data);
	void AddData(Sales_data data);
	void Print();
};

void Sales_data::CalcRevenue(double price)
{
	revenue = units_sold * price;
}

void Sales_data::SetData(Sales_data data)
{
	bookNo = data.bookNo;
	units_sold = data.units_sold;
	revenue = data.revenue;
}

void Sales_data::AddData(Sales_data data)
{
	if (bookNo != data.bookNo)
	{
		return;
	}
	units_sold += data.units_sold;
	revenue += data.revenue;
}

double Sales_data::CalcAveragePrice()
{
	if (units_sold != 0)
	{
		return revenue / units_sold;
	}
	else
	{
		return 0.0;
	}
}

void Sales_data::Print()
{
	cout << bookNo << " " << units_sold << " " << revenue << " ";
	double averagePrice = CalcAveragePrice();
	if (averagePrice != 0.0)
	{
		cout << averagePrice << endl;
	}
	else
	{
		cout << "(no sales)" << endl;
	}
}

#endif // SALES_DATA_H
