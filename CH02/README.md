#CH02

##Exercises Section 2.1.1

###Exercise 2.1

>What are the differences between int, long, long long, and short? Between an unsigned and a signed type? Between a float and a double?

 - C++ guarantees short and int is at least 16 bits, long at least 32 bits, long long at least 64 bits.
 - The signed can represent positive numbers, negative numbers and zero, while unsigned can only represent numbers no less than zero.
 - The C and C++ standards do not specify the representation of float, double and long double. It is possible that all three implemented as IEEE double‐precision. For most architectures, float is a IEEE single-precision floating point number (binary32), and double is a IEEE double-precision floating point number (binary64).

###Exercise 2.2

>To calculate a mortgage payment, what types would you use for the rate, principal, and payment? Explain why you selected each type.

 - Use double, or float. The rate like that: 4.50% per year. The principal like that: $854.36. The payment like that: $1,142.36

##Exercises Section 2.1.2

###Exercise 2.3

> What output will the following code produce?
```cpp
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```

```cpp
32
4294967264
32
-32
0
0
```

###Exercise 2.4

> Write a program to check whether your predictions were correct. If not, study this section until you understand what the problem is.

 - Do it yourself.

##Exercises Section 2.1.3

###Exercise 2.5

> Determine the type of each of the following literals. Explain the differences among the literals in each of the four examples:
(a) 'a', L'a', "a", L"a"
(b) 10, 10u, 10L, 10uL, 012, 0xC
(c) 3.14, 3.14f, 3.14L 
(d) 10, 10u, 10., 10e-2

 - (a): character literal, wide character literal, string literal, string wide character literal.
 - (b): decimal, unsigned decimal, long decimal, unsigned long decimal, octal, hexadecimal.
 - (c): double, float, long double.
 - (d): decimal, unsigned decimal, double, double.

###Exercise 2.6

> What, if any, are the differences between the following definitions:
```cpp
int month = 9, day = 7;
int month = 09, day = 07;
```

 - The first line's integer is decimal.
 - The second line:
1. int month = 09 is invalid, cause octal don't have digit 9.
2. day is octal.

###Exercise 2.7 

>What values do these literals represent? What type does each have?
(a) "Who goes with F\145rgus?\012"
(b) 3.14e1L
(c) 1024f
(d) 3.14L

 - ﴾a﴿: Who goes with Fergus?﴾new line﴿ "string"
 - ﴾b﴿: 31.4 "long double"
 - ﴾c﴿: ERROR: The suffix f is valid only with floating point literals.
```cpp
double dou = 1024f;  // error: unable to find numeric literal operator ‘operator"" f’
```
 - ﴾d﴿: 3.14 "long double"

###Exercise 2.8

> Using escape sequences, write a program to print 2M followed by a newline. Modify the program to print 2, then a tab, then an M, followed by a newline.

```cpp
#include <iostream>

int main()
{
	std::cout << "\062\115\012";
	std::cout << "\062\t\115\012";
}

/*
Output:
2M
2	M
*/
```

##Exercises Section 2.2.1

###Exercise 2.9

>Explain the following definitions. For those that are illegal, explain what’s wrong and how to correct it.
(a) std::cin >> int input_value;
(b) int i = { 3.14 };
(c) double salary = wage = 9999.99;
(d) int i = 3.14;

 - error: expected primary-expression before ‘int’. Correct:
int input_value = 0;
std::cin >> input_value;
 - warning: narrowing conversion of ‘3.1400000000000001e+0’ from ‘double’ to ‘int’ inside { } [-Wnarrowing]|
 - error: ‘wage’ was not declared in this scope. Correct:
double wage = 9999.99, salary = wage;
 - No error or warning, but value will be truncated.

###Exercise 2.10

> What are the initial values, if any, of each of the following variables?
```cpp
std::string global_str;
int global_int;
int main()
{
	int local_int;
	std::string local_str;
}
```

 - global_str is global variable, so the value is empty string.
 - global_int is global variable, so the value is zero.
 - local_int is a local variable which is not uninitialized, so it has a undefined value.
 - local_str is also a local variable which is not uninitialized, but it has a value that is defined by the class. So it is empty string.

##Exercises Section 2.2.2

###Exercise 2.11

> Explain whether each of the following is a declaration or a definition:
(a) extern int ix = 1024;
(b) int iy;
(c) extern int iz;

 - ﴾a﴿: definition.
 - ﴾b﴿: definition.
 - ﴾c﴿: declaration.

##Exercises Section 2.2.3

###Exercise 2.12

> Which, if any, of the following names are invalid?
(a) int double = 3.14;
(b) int _;
(c) int catch-22;
(d) int 1_or_2 = 1;
(e) double Double = 3.14;

 - a, c, and d are invalid.

##Exercises Section 2.2.4

###Exercise 2.13

> What is the value of j in the following program?
```cpp
int i = 42;
int main()
{
	int i = 100;
	int j = i;
}
```

 - 100

###Exercise 2.14

> Is the following program legal? If so, what values are printed?
```cpp
int i = 100, sum = 0;
for (int i = 0; i != 10; ++i)
	sum += i;
std::cout << i << " " << sum << std::endl;
```

 - Legal: 100 45

##Exercises Section 2.3.1

###Exercise 2.15

> Which of the following definitions, if any, are invalid? Why?
```cpp
(a) int ival = 1.01;
(b) int &rval1 = 1.01;
(c) int &rval2 = ival;
(d) int &rval3;
```

 - ﴾a﴿: Valid.
 - ﴾b﴿: Invalid. Initializer must be an object.
 - ﴾c﴿: Valid.
 - ﴾d﴿: Invalid. A reference must be initialized.

###Exercise 2.16

> Which, if any, of the following assignments are invalid? If they are valid, explain what they do.
```cpp
int i = 0, &r1 = i;
double d = 0, &r2 = d;
(a) r2 = 3.14159;
(b) r2 = r1;
(c) i = r2;
(d) r1 = d;
```

 - ﴾a﴿: Valid. d = 3.14159.
 - ﴾b﴿: Valid. Automatic convert will happen.
 - ﴾c﴿: Valid, but value will be truncated.
 - ﴾d﴿: Valid, but value will be truncated.
```cpp
#include <iostream>

using std::cout;

int main()
{
	int i = 0, &r1 = i;
	double d = 0, &r2 = d;
	cout << i << '\t' << r1 << '\t' << d << '\t' << r2 << '\n';

	r2 = 3.14159;
	cout << i << '\t' << r1 << '\t' << d << '\t' << r2 << '\n';

	r2 = r1;
	cout << i << '\t' << r1 << '\t' << d << '\t' << r2 << '\n';

	i = r2;
	cout << i << '\t' << r1 << '\t' << d << '\t' << r2 << '\n';

	r1 = d;
	cout << i << '\t' << r1 << '\t' << d << '\t' << r2 << '\n';

	return 0;
}
/*
Output:
0		0		0		0
0		0		3.14159	3.14159
0		0		0		0
0		0		0		0
0		0		0		0
*/
```

###Exercise 2.17

> What does the following code print?
```cpp
int i, &ri = i;
i = 5;
ri = 10;
std::cout << i << " " << ri << std::endl;
```

 - 10 10

##Exercises Section 2.3.2

###Exercise 2.18

> Write code to change the value of a pointer. Write code to change the value to which the pointer points.

```cpp
#include <iostream>

using std::cout;

int main()
{
	int num1 = 1, num2 = 2;
	int *ptr = &num1;
	cout << num1 << '\t' << num2 << '\t' << ptr << "\t\t" << *ptr << '\n';

	// First: change the value of a pointer:
	ptr = &num2;
	cout << num1 << '\t' << num2 << '\t' << ptr << "\t\t" << *ptr << '\n';

	// Second: change the value to which the pointer points:
	*ptr = 3;
	cout << num1 << '\t' << num2 << '\t' << ptr << "\t\t" << *ptr << '\n';

	return 0;
}
/*
Output:
1	2	0x7ffebbb434e0		1
1	2	0x7ffebbb434e4		2
1	3	0x7ffebbb434e4		3
*/
```

###Exercise 2.19

> Explain the key differences between pointers and references.

 - Definition
 1. Pointer is "points to" any other type.
 2. Reference is "another name" of an object.
 - Key Difference:
 1. A reference is another name of an already existing object. A pointer is an object in its own right.
 2. Once initialized, a reference remains bound to its initial object. There is no way to rebind a reference to refer to a different object. A pointer can be assigned and copied.
 3. A reference always get the object to which the reference was initially bound. A single pointer can point to several different objects over its lifetime.
 4. A reference must be initialized. A pointer need not be initialized when it is defined.

###Exercise 2.20

> What does the following program do?
```cpp
int i = 42;
int *p1 = &i;
*p1 = *p1 * *p1;
```

 - i = i * i, so i = 1764.

###Exercise 2.21

> Explain each of the following definitions. Indicate whether any are illegal and, if so, why.
`int i = 0;`
(a) double* dp = &i;
(b) int *ip = i;
(c) int *p = &i;

 - ﴾a﴿: illegal, cannot initialize a variable of type double * with an rvalue of type int *
 - ﴾b﴿: illegal, cannot initialize a variable of type int * with an lvalue of type int
 - ﴾c﴿: legal.

###Exercise 2.22

> Assuming p is a pointer to int, explain the following code:
```cpp
if (p) // ...
if (*p) // ...
```

 - if ﴾p﴿  // whether p is nullptr?
 - if ﴾*p﴿  // whether the value pointed by p is zero?

###Exercise 2.23

> Given a pointer p, can you determine whether p points to a valid object? If so, how? If not, why not?

 - There is no way to distinguish a valid address from an invalid one from the bits that are in the memory in which the pointer was allocated.

###Exercise 2.24

> Why is the initialization of p legal but that of lp illegal?
```cpp
int i = 42;
void *p = &i;
long *lp = &i;
```

 - Because the type void* is a pointer type that can hold the address of any object. But we cannot initialize a variable of type long * with an rvalue of type int *.

##Exercises Section 2.3.3

###Exercise 2.25

> Determine the types and values of each of the following variables.
(a) int* ip, &r = ip;
(b) int i, *ip = 0;
(c) int* ip, ip2;

 - (a): ip is a pointer to int, r is a reference to a pointer which points to int. 
 - (b): ip is a valid, null pointer, and i is an int. 
 - (c): ip is a pointer to int, and ip2 is an int. 

##Exercises Section 2.4

###Exercise 2.26

> Which of the following are legal? For those that are illegal, explain why.
(a) const int buf;
(b) int cnt = 0;
(c) const int sz = cnt;
(d) ++cnt; ++sz;

 - Illegal, buf is uninitialized const. 
 - Legal. 
 - Legal. 
 - Illegal, attempt to write to const object(sz).

##Exercises Section 2.4.2

###Exercise 2.27

> Which of the following initializations are legal? Explain why.
(a) int i = -1, &r = 0;
(b) int *const p2 = &i2;
(c) const int i = -1, &r = 0;
(d) const int *const p3 = &i2;
(e) const int *p1 = &i2;
(f) const int &const r2;
(g) const int i2 = i, &r = i;

 - Illegal, r must refer to an object.
 - Legal.
 - Legal.
 - Legal.
 - Legal.
 - Illegal, r2 is a reference that cannot be const.
 - Legal.

###Exercise 2.28

> Explain the following definitions. Identify any that are illegal.
(a) int i, *const cp;
(b) int *p1, *const p2;
(c) const int ic, &r = ic;
(d) const int *const p3;
(e) const int *p;

 - Illegal, cp must initialize. 
 - Illegal, p2 must initialize. 
 - Illegal, ic must initialize. 
 - Illegal, p3 must initialize.
 - Legal.

###Exercise 2.29

> Using the variables in the previous exercise, which of the following assignments are legal? Explain why.
(a) i = ic;
(b) p1 = p3;
(c) p1 = &ic;
(d) p3 = &ic;
(e) p2 = p1;
(f) ic = *p3;

 - Legal.
 - Illegal. p3 is a pointer to const int.
 - Illegal. ic is a const int.
 - Illegal. p3 is a const pointer.
 - Illegal. p2 is a const pointer.
 - Illegal. ic is a const int.

##Exercises Section 2.4.3

###Exercise 2.30

> For each of the following declarations indicate whether the object being declared has top-level or low-level const.
```cpp
const int v2 = 0;
int v1 = v2;
int *p1 = &v1, &r1 = v1;
const int *p2 = &v2, *const p3 = &i, &r2 = v2;
```

| object | Top-level | Low-level |
| ----- | ----- | ----- |
| v2 | Yes | No |
| v1 | No | No |
| p1 | No | No |
| r1 | Yes | No |
| p2 | No | Yes |
| p3 | Yes | Yes |
| r2 | Yes | Yes |

###Exercise 2.31

> Given the declarations in the previous exercise determine whether the following assignments are legal. Explain how the top-level or low-level const applies in each case.
```cpp
r1 = v2;
p1 = p2;
p2 = p1;
p1 = p3;
p2 = p3;
```

 - Legal, top-level const in v2 is ignored. 
 - Illegal, p2 has a low-level const but p1 doesn't. 
 - Legal, we can convert int* to const int*. 
 - Illegal, p3 has a low-level const but p1 doesn't. 
 - Legal, p2 has the same low-level const qualification as p3.

##Exercises Section 2.4.4

###Exercise 2.32

> Is the following code legal or not? If not, how might you make it legal?
`int null = 0, *p = null;`

 - Illegal. `int null = 0, *p = nullptr;`

##Exercises Section 2.5.2

###Exercise 2.33

> Using the variable definitions from this section, determine what happens in each of these assignments:
```cpp
a = 42;
b = 42;
c = 42;
d = 42;
e = 42;
g = 42;
```

 - Set 42 to int a. 
 - Set 42 to int b. 
 - Set 42 to int c. 
 - ERROR, d is an int *. correct: *d = 42; 
 - ERROR, e is an const int *. correct: e = &c; 
 - ERROR, g is a const int& that is bound to ci.

###Exercise 2.34

> Write a program containing the variables and assignments from the previous exercise. Print the variables before and after the assignments to check whether your predictions in the previous exercise were correct. If not, study the examples until you can convince yourself you know what led you to the wrong conclusion.

```cpp
#include <iostream>

int main()
{
	int i = 0, &r = i;
	const int ci = i, &cr = ci;

	auto a = r;  // a is an int (r is an alias for i, which has type int)
	auto b = ci;  // b is an int (top-level const in ci is dropped)
	auto c = cr;  // c is an int (cr is an alias for ci whose const is top-level)
	auto d = &i;  // d is an int* (& ofan int objectis int*)
	auto e = &ci;  // e is const int*(& of a const object is low-level const)
	const auto f = ci;  // deduced type of ci is int; f has type const int
	auto &g = ci;  // g is a const int& that is bound to ci

	a = 42;
	b = 42;
	c = 42;
	*d = 42;
	e = &c;

	return 0;
}
```

###Exercise 2.35

> Determine the types deduced in each of the following definitions. Once you’ve figured out the types, write a program to see whether you were correct.

```cpp
const int i = 42;
auto j = i;
const auto &k = i;
auto *p = &i;
const auto j2 = i, &k2 = i;
```
 - i is const int.
 - j is int.
 - k is const int&.
 - p is const int *.
 - j2 is const int.
 - k2 is const int&.
```cpp
#include <iostream>
#include <typeinfo>

using std::cout;

int main()
{
	const int i = 42;
	auto j = i;
	const auto &k = i;
	auto *p = &i;
	const auto j2 = i, &k2 = i;

	// i: int; PKi: pointer to const int.
	cout << "j is " << typeid(j).name() << "\nk is " << typeid(k).name()
	     << "\np is " << typeid(p).name() << "\nj2 is " << typeid(j2).name()
	     << "\nk2 is " << typeid(k2).name() << '\n';

	return 0;
}

/*
Output:
j is i
k is i
p is PKi
j2 is i
k2 is i
*/
```

##Exercises Section 2.5.3

###Exercise 2.36

> In the following code, determine the type of each variable and the value each variable has when the code finishes:
```cpp
int a = 3, b = 4;
decltype(a) c = a;
decltype((b)) d = a;
++c;
++d;
```

 - c is int; d is int &. Result: a = 4, b = 4, c = 4, d = 4.

###Exercise 2.37

> Assignment is an example of an expression that yields a reference type. The type is a reference to the type of the left-hand operand. That is, if i is an int, then the type of the expression i = x is int&. Using that knowledge, determine the type and value of each variable in this code:
```cpp
int a = 3, b = 4;
decltype(a) c = a;
decltype(a = b) d = a;
```

 - c is int, d is int &. Result: a = 3, b = 4, c = 3, d = 3.
Note: decltype doesn’t evaluate the expression, so a is still 3.

###Exercise 2.38

> Describe the differences in type deduction between decltype and auto. Give an example of an expression where auto and decltype will deduce the same type and an example where they will deduce differing types.

 - The way decltype handles top-level const and references differs from the way auto does.
 - Another difference is that the deduction done by decltype depends on the form of its given expression.
int i = 0, &r = i; // same
auto a = i;
decltype(i) b = i;
// different "c" will be int "d" will be int&
auto c = r;
decltype(r) d = r;
http://stackoverflow.com/questions/21369113/what-is-the-difference-between-auto-and-decltypeauto-when-returning-from-a-fun
http://stackoverflow.com/questions/12084040/decltype-vs-auto

##Exercises Section 2.6.1

###Exercise 2.39

> Compile the following program to see what happens when you forget the semicolon after a class definition. Remember the message for future reference.
```cpp
struct Foo { /* empty */ } // Note: no semicolon
int main()
{
	return 0;
}
```

 - error: expected ‘;’ after struct definition

###Exercise 2.40

> Write your own version of the Sales_data class.

```cpp
struct Sale_data
{
	std::string bookNo;
	std::string bookName;
	unsigned units_sold = 0;
	double revenue = 0.0;
	double price = 0.0;
	//...
};
```

##Exercises Section 2.6.2

###Exercise 2.41

> Use your Sales_data class to rewrite the exercises in §1.5.1 (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your Sales_data class in the same file as your main function.

```cpp
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
```
```cpp
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
```
```cpp
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
```

##Exercises Section 2.6.3

###Exercise 2.42

> Write your own version of the Sales_data.h header and use it to rewrite the exercise from § 2.6.2 (p. 76).

```cpp
/****************************** Sales_Data ******************************/
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
```
```cpp
/****************************** 1.5.1 ******************************/
#include "Sales_data.h"

int main()
{
	Sales_data book;
	double price;
	cin >> book.bookNo >> book.units_sold >> price;
	book.CalcRevenue(price);
	book.Print();

	return 0;
}
```
```cpp
/****************************** 1.5.2 ******************************/
#include "Sales_data.h"

int main()
{
	Sales_data book1, book2;
	double price1, price2;
	cin >> book1.bookNo >> book1.units_sold >> price1;
	cin >> book2.bookNo >> book2.units_sold >> price2;
	book1.CalcRevenue(price1);
	book2.CalcRevenue(price2);

	if (book1.bookNo == book2.bookNo)
	{
		book1.AddData(book2);
		book1.Print();

		return 0;
	}
	else
	{
		cerr << "Data must refer to same ISBN" << endl;
		return -1; // indicate failure
	}
}
```
```cpp
/****************************** 1.6 ******************************/
#include "Sales_data.h"

int main()
{
	Sales_data total;
	double totalPrice;
	if (cin >> total.bookNo >> total.units_sold >> totalPrice)
	{
		total.CalcRevenue(totalPrice);
		Sales_data trans;
		double transPrice;

		while (cin >> trans.bookNo >> trans.units_sold >> transPrice)
		{
			trans.CalcRevenue(transPrice);
			if (total.bookNo == trans.bookNo)
			{
				total.AddData(trans);
			}
			else
			{
				total.Print();
				total.SetData(trans);
			}
		}
		total.Print();

		return 0;
	}
	else
	{
		cerr << "No data?!" << endl;
		return -1; // indicate failure
	}
}
```
