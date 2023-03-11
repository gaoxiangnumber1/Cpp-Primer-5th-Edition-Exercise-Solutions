#CH01

##Exercises Section 1.1.1

###Exercise1.1:

>Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the main program from page 2.

![](https://raw.githubusercontent.com/gaoxiangnumber1/NotesPhotos/master/Cpp/Cp/EX1-1.png)

###Exercise 1.2

>Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed. Recompile and rerun your program to see how your system treats a failure indicator from main.

![](https://raw.githubusercontent.com/gaoxiangnumber1/NotesPhotos/master/Cpp/Cp/EX1-2.png)

 - Why 255: http://www.tldp.org/LDP/abs/html/exitcodes.html
##Exercises Section 1.2

###Exercise 1.3

>Write a program to print Hello, World on the standard output.

```cpp
#include <iostream>

int main()
{
	std::cout << "Hello, World" << std::endl;
	return 0;
}
```

###Exercise 1.4

>Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, *, to print the product instead.

```cpp
#include <iostream>

int main()
{
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The product of " << v1 << " and " << v2 << " is " << v1 * v2 << std::endl;

	return 0;
}
```

###Exercise 1.5:

>We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.

```cpp
#include <iostream>

int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 * v2;
    std::cout << std::endl;
    return 0;
}
```

###Exercise 1.6:

>Explain whether the following program fragment is legal.

```cpp
std::cout	<< "The sum of " << v1;
<< " and " << v2;
<< " is " << v1 + v2 << std::endl;
```
If the program is legal, what does it do? If the program is not legal, why not? How would you fix it?

 - Illegal: 1-6.cpp|9|error: expected primary-expression before ‘<<’ token|.
 - Fix it: remove the spare semicolons.
 

##Exercises Section 1.3

###Exercise 1.7:

>Compile a program that has incorrectly nested comments.

```cpp
/*
* comment pairs /* */ cannot nest.
* ''cannot nest'' is considered source code,
* as is the rest of the program
*/
int main()
{
	return 0;
}
```

![](https://raw.githubusercontent.com/gaoxiangnumber1/NotesPhotos/master/Cpp/Cp/EX1-7.png)

###Exercise 1.8:

>Indicate which, if any, of the following output statements are legal:
```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```
>After you’ve predicted what will happen, test your answers by compiling a program with each of these statements. Correct any errors you encounter.

![](https://raw.githubusercontent.com/gaoxiangnumber1/NotesPhotos/master/Cpp/Cp/EX1-8.png)

 - Correct: Add a quote to the third cout.
![](https://raw.githubusercontent.com/gaoxiangnumber1/NotesPhotos/master/Cpp/Cp/EX1-8-2.png)

##Exercises Section 1.4.1

###Exercise 1.9:

>Write a program that uses a while to sum the numbers from 50 to 100.

```cpp
#include <iostream>

int main()
{
	int num = 50, sum = 0;
	while(num <= 100)
	{
		sum += num;
		++num;
	}
	std::cout << "The sum from 50 to 100 is " << sum << std::endl;

	return 0;
}
```

###Exercise 1.10:

>In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--) that subtracts 1. Use the decrement operator to write a while that prints the numbers from ten down to zero.

```cpp
#include <iostream>

int main()
{
	int num = 10;
	while(num >= 0)
	{
		std::cout << num << std::endl;
		--num;
	}

	return 0;
}
```

###Exercise 1.11:

>Write a program that prompts the user for two integers. Print each number in the range specified by those two integers. 

```cpp
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
		big = temp;
	}

	// Print integers in the range [num1, num2]:
	while(small <= big)
	{
		cout << small << endl;
		++small;
	}

	return 0;
}
```

##Exercises Section 1.4.2

###Exercise 1.12:

>What does the following for loop do? What is the final value of sum?

```cpp
int sum = 0;
for (int i = -100; i <= 100; ++i)
    sum += i;
```

 - Calculate the sum form -100 to 100, the result is 0.

###Exercise 1.13:

>Rewrite the exercises from § 1.4.1 (p. 13) using for loops.

```cpp
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	/*
	* Exercise 1.9: Write a program that uses a while
	* to sum the numbers from 50 to 100.
	*/
	cout << "Exercise 1.9\n";
	int sum = 0;
	for(int num = 50; num <= 100; ++num)
	{
		sum += num;
	}
	cout << "The sum from 50 to 100 is " << sum << endl;

	/*
	* Exercise 1.10: Use the decrement operator to write a while
	* that prints the numbers from ten down to zero.
	*/
	cout << "Exercise 1.10\n";
	for(int num = 10; num >= 0; --num)
	{
		cout << num << endl;
	}

	/*
	* Exercise 1.11: Write a program that prompts the user for two integers.
	* Print each number in the range specified by those two integers.
	*/
	cout << "Exercise 1.11\n";
	int num1 = 0, num2 = 0;
	cout << "Please input 2 integers: ";
	cin >> num1 >> num2;

	// We make num1 <= num2
	if(num1 > num2)
	{
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}

	// Print integers in the range [num1, num2]:
	for(; num1 <= num2; ++num1)
	{
		cout << num1 << endl;
	}

	return 0;
}
```

###Exercise 1.14:

>Compare and contrast the loops that used a for with those using a while. Are there advantages or disadvantages to using either form?

| Ad/Disad | for | while |
| ----- | ----- | ----- |
| Advantages | 1.Locality, the variable in the scope of the loop. 2.Pattern happens so often: using a variable in a condition and incrementing that variable in the body. | 1.Clear when there is only one static condition. 2.Readable when the global variables incremented in the body. |
| Disadvantages | while’s advantages | for’s advantages|

###Exercise 1.15:

>Write programs that contain the common errors discussed in the box on page 16. Familiarize yourself with the messages the compiler generates.

 - Self-training
##Exercises Section 1.4.3

###Exercise 1.16:

>Write your own version of a program that prints the sum of a set of integers read from cin.

```cpp
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int sum = 0;
	for(int value = 0; cin >> value;)
	{
		sum += value;
	}
	cout << "The sum is " << sum << endl;

	return 0;
}
```

##Exercises Section 1.4.4

###Exercise 1.17:

>What happens in the program presented in this section if the input values are all equal? What if there are no duplicated values?

 - If the input values are all equal, it will print a line which shows the count of the number you input.
 - If there are no duplicated values, when different values input, a new line will be printed if you click Enter.

###Exercise 1.18:

>Compile and run the program from this section giving it only equal values as input. Run it again giving it values in which no number is repeated.

![](https://raw.githubusercontent.com/gaoxiangnumber1/NotesPhotos/master/Cpp/Cp/EX1-18.png)

###Exercise 1.19:

>Revise the program you wrote for the exercises in § 1.4.1 (p. 13) that printed a range of numbers so that it handles input in which the first number is smaller than the second.

```cpp
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
```

##Exercises Section 1.5.1

###Exercise 1.20:

>http://www.informit.com/title/032174113 contains a copy of Sales_item.h in the Chapter 1 code directory. Copy that file to your working directory. Use it to write a program that reads a set of book sales transactions, writing each transaction to the standard output.

```cpp
#include "sales_item.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	for(SalesItem item; cin >> item; cout << item << endl);
	return 0;
}
```

###Exercise 1.21:

>Write a program that reads two Sales_item objects that have the same ISBN and produces their sum.

```cpp
#include "sales_item.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main()
{
	Sales_item item1, item2;
	cin >> item1 >> item2;
	if(item1.isbn() == item2.isbn())
	{
		cout << item1 + item2 << endl;
	}
	else
	{
		cerr << "Input error: different ISBN.\n";
	}
}
```

###Exercise 1.22:

>Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions that were read.

```cpp
#include "sales_item.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main()
{
	Sales_item total;
	if(cin >> total)
	{
		Sales_item trans;
		while (cin >> trans)
		{
			if (total.isbn() == trans.isbn())
			{
				total += trans;
			}
			else
			{
				cout << total << endl;
				total = trans;
			}
		}
		cout << total << endl;
	}
	else
	{
		cerr << "Input Error" << endl;
		return -1;
	}

	return 0;
}
```

##Exercises Section 1.5.2

###Exercise 1.23:

>Write a program that reads several transactions and counts how many transactions occur for each ISBN.

```cpp
#include "Sales_item.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	Sales_item current_item, input_item;
	if (cin >> current_item)
	{
		int cnt = 1;
		while (cin >> input_item)
		{
			if (input_item.isbn() == current_item.isbn())
			{
				++cnt;
			}
			else
			{
				cout << current_item << " occurs " << cnt << " times " << endl;
				current_item = input_item;
				cnt = 1;
			}
		}
		cout << current_item << " occurs " << cnt << " times " << endl;
	}
	return 0;
}
```

###Exercise 1.24:

>Test the previous program by giving multiple transactions representing multiple ISBNs. The records for each ISBN should be grouped together.

![](https://raw.githubusercontent.com/gaoxiangnumber1/NotesPhotos/master/Cpp/Cp/EX1-23.png)

##Exercises Section 1.6

###Exercise 1.25:

>Using the Sales_item.h header from the Web site, compile and execute the bookstore program presented in this section.

 - It is the same as Exercise 1.22.
