#CH03

##Exercises Section 3.1

###Exercise 3.1

>Rewrite the exercises from §1.4.1 (p. 13) and §2.6.2 (p. 76) with appropriate using declarations.

```cpp
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
```

##Exercises Section 3.2.2

###Exercise 3.2

>Write a program to read the standard input a line at a time. Modify your program to read a word at a time.

```cpp
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	// One line at a time:
	string str;
	while(getline(cin, str))
	{
		cout << str << endl;
	}

	return 0;
}
```
```cpp
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	// One line at a time:
	string str;
	while(cin >> str)
	{
		cout << str << endl;
	}

	return 0;
}
```

###Exercise 3.3

>Explain how whitespace characters are handled in the string input operator and in the getline function.

 - string input operator: all whitespaces are ignored.
 - getline: keep whitespaces in the same line as a string.

###Exercise 3.4

>Write a program to read two strings and report whether the strings are equal. If not, report which of the two is larger. Now, change the program to report whether the strings have the same length, and if not, report which is longer.

```cpp
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	if(str1 == str2)
	{
		cout << "Equal\n";
	}
	else
	{
		cout << "Not equal: " << ((str1 > str2) ? str1 : str2) << " is larger.\n";
	}

	return 0;
}
```
```cpp
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	string::size_type length1 = str1.size(), length2 = str2.size();
	if(length1 == length2)
	{
		cout << "Same length\n";
	}
	else
	{
		cout << ((length1 > length2) ? str1 : str2) << " is longer.\n";
	}

	return 0;
}
```

###Exercise 3.5

>Write a program to read strings from the standard input, concatenating what is read into one large string. Print the concatenated string. Next, change the program to separate adjacent input strings by a space.

```cpp
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	string input, total;
	while(cin >> input)
	{
		total += input;
	}
	cout << total;

	return 0;
}
```
```cpp
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	string input, total;
	while(cin >> input)
	{
		total = total + ' ' + input;
	}
	cout << total;

	return 0;
}
```

##Exercises Section 3.2.3

###Exercise 3.6

>Use a range for to change all the characters in a string to X.

```cpp
#include <iostream>
#include <string>

using std::cout;
using std::string;

int main()
{
	string str = "gaoxiangnumber1";
	for(char &ch : str)
	{
		ch = 'X';
	}
	cout << str;

	return 0;
}
/*
Output:
XXXXXXXXXXXXXXX
*/
```

###Exercise 3.7

>What would happen if you define the loop control variable in the previous exercise as type char? Predict the results and then change your program to use a char to see if you were right.

```cpp
#include <iostream>
#include <string>

using std::cout;
using std::string;

int main()
{
	string str = "gaoxiangnumber1";
	for(char ch : str)
	{
		ch = 'X';
	}
	cout << str;

	return 0;
}
/*
Output:
gaoxiangnumber1
*/
```

###Exercise 3.8

>Rewrite the program in the first exercise, first using a while and again using a traditional for loop. Which of the three approaches do you prefer and why?

```cpp
#include <iostream>
#include <string>

using std::cout;
using std::string;

int main()
{
	string str1 = "gaoxiangnumber1";
	string str2 = str1;
	int length = str1.size();

	// First: use while
	int index1 = 0;
	while(index1 < length)
	{
		str1[index1] = 'X';
		++index1;
	}

	// Second, use traditional for
	for(int index2 = 0; index2 < length; ++index2)
	{
		str2[index2] = 'X';
	}
	cout << str1 << '\t' << str2;

	return 0;
}
/*
Output:
XXXXXXXXXXXXXXX	XXXXXXXXXXXXXXX
*/
```

###Exercise 3.9

>What does the following program do? Is it valid? If not, why not?

```cpp
string s;
cout << s[0] << endl;
```
Invalid: undefined behavior.

###Exercise 3.10

>Write a program that reads a string of characters including punctuation and writes what was read but with the punctuation removed.

```cpp
#include <iostream>
#include <string>
#include <cctype>  // ispunct(c)

using std::cout;
using std::cin;
using std::string;

int main()
{
	string str;
	cin >> str;
	int length = str.size();
	for(int index = 0; index < length; ++index)
	{
		if(ispunct(str[index]))
		{
			continue;
		}
		cout << str[index];
	}

	return 0;
}
```

###Exercise 3.11

>Is the following range for legal? If so, what is the type of c?

```cpp
const string s = "Keep out!";
for (auto &c : s) { /* ... */ }
```
 - When `c = ‘X’;` error: assignment of read-only reference ‘c’.
So, c is type of “const char &”.

##Exercises Section 3.3.1

###Exercise 3.12

>Which, if any, of the following vector definitions are in error? For those that are legal, explain what the definition does. For those that are not legal, explain why they are illegal.
(a) vector<vector<int>> ivec;
(b) vector<string> svec = ivec;
(c) vector<string> svec(10, "null");

 - Legal in C++11
 - Illegal: different type.
 - Legal, vector have 10 strings: "null".

###Exercise 3.13

>How many elements are there in each of the following vectors? What are the values of the elements?
(a) vector<int> v1; empty
(b) vector<int> v2(10); ten zero
(c) vector<int> v3(10, 42); ten 42
(d) vector<int> v4{10}; 10
(e) vector<int> v5{10, 42}; 10, 42
(f) vector<string> v6{10}; 10 “”
(g) vector<string> v7{10, "hi"};

 - size:0, empty vector.
 - size:10, ten zero.
 - size:10, ten 42.
 - size:1, one 10.
 - size:2, 10 and 42.
 - size:10, ten empty string “”
 - size:10, ten string “hi”

##Exercises Section 3.3.2

###Exercise 3.14

>Write a program to read a sequence of ints from cin and store those values in a vector.

```cpp
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

void Print(vector<int> &vec)
{
	int length = vec.size();
	for(int index = 0; index < length; ++index)
	{
		cout << vec[index] << " ";
	}
	cout << '\n';
}

int main()
{
	vector<int> vec;
	for(int num = 0; cin >> num; )
	{
		vec.push_back(num);
	}
	Print(vec);

	return 0;
}
```

###Exercise 3.15

>Repeat the previous program but read strings this time.

```cpp
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

void Print(vector<string> &vec)
{
	int length = vec.size();
	for(int index = 0; index < length; ++index)
	{
		cout << vec[index] << " ";
	}
	cout << '\n';
}

int main()
{
	vector<string> vec;
	for(string str; cin >> str; )
	{
		vec.push_back(str);
	}
	Print(vec);

	return 0;
}
```

##Exercises Section 3.3.3

###Exercise 3.16

>Write a program to print the size and contents of the vectors from exercise 3.13. Check whether your answers to that exercise were correct. If not, restudy § 3.3.1 (p. 97) until you understand why you were wrong.

```cpp
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

template<typename T>
void Print(vector<T> &vec)
{
	int length = vec.size();
	for(int index = 0; index < length; ++index)
	{
		cout << vec[index] << " ";
	}
	cout << ((length == 0) ? "empty\n" : "\n");
}

int main()
{
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4 {10};
	vector<int> v5 {10, 42};
	vector<string> v6 {10};
	vector<string> v7 {10, "hi"};
	cout << "v1:\t";
	Print(v1);
	cout << "v2:\t";
	Print(v2);
	cout << "v3:\t";
	Print(v3);
	cout << "v4:\t";
	Print(v4);
	cout << "v5:\t";
	Print(v5);
	cout << "v6:\t";
	Print(v6);
	cout << "v7:\t";
	Print(v7);

	return 0;
}
```

###Exercise 3.17

>Read a sequence of words from cin and store the values a vector. After you’ve read all the words, process the vector and change each word to uppercase. Print the transformed elements, eight words to a line.

```cpp
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

template<typename T>
void Print(vector<T> &vec)
{
	int length = vec.size();
	int cnt = 0;
	for(int index = 0; index < length; ++index)
	{
		cout << vec[index] << " ";
		++cnt;
		if(cnt % 8 == 0)
		{
			cout << '\n';
		}
	}
	cout << '\n';
}

int main()
{
	vector<string> vec;
	for(string str1; cin >> str1; )
	{
		vec.push_back(str1);
	}
	int length1 = vec.size();
	for(int index1 = 0; index1 < length1; ++index1)
	{
		string &str2 = vec[index1];
		int length2 = str2.size();
		for(int index2 = 0; index2 < length2; ++index2)
		{
			char &ch = str2[index2];
			ch = (('a' <= ch && ch <= 'z') ? ch - 32 : ch);
		}
	}
	Print(vec);

	return 0;
}
```

###Exercise 3.18

>Is the following program legal? If not, how might you fix it?

```cpp
vector<int> ivec;
ivec[0] = 42;
```
`ivec.push_back(42);`

###Exercise 3.19

>List three ways to define a vector and give it ten elements, each with the value 42. Indicate whether there is a preferred way to do so and why.

```cpp
vector<int> vec1(10, 42);
vector<int> vec2 {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
vector<int> vec3;
for (int index = 0; index != 10; ++index)
{
	vec3.push_back(42);
}
```

###Exercise 3.20

>Read a set of integers into a vector. Print the sum of each pair of adjacent elements. Change your program so that it prints the sum of the first and last elements, followed by the sum of the second and second-to-last, and so on.

```cpp
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int main()
{
	vector<int> vec;
	int input = 0, length = 1;
	cin >> input;
	vec.push_back(input);

	// First print the sum of each pair of adjacent elements:
	cout << "Sum of each pair of adjacent elements:\n";
	int first = input;
	while(cin >> input)
	{
		cout << first + input << ' ';
		first = input;
		vec.push_back(input);
		++length;
	}

	// Second print the sum of the first and last elements, and so on.
	cout << "\nSum of the first and last elements, and so on:\n";
	for(int index = 0; index < length / 2; ++index)
	{
		cout << vec[index] + vec[length - 1 - index] << ' ';
	}

	return 0;
}
```

##Exercises Section 3.4.1

###Exercise 3.21

>Redo the first exercise from §3.3.3(p.105) using iterators.

```cpp
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

template<typename T>
void Print(vector<T> &vec)
{
	typename vector<T>::const_iterator it1 = vec.cbegin(), it2 = vec.cend();
	for(; it1 != it2; ++it1)
	{
		cout << *it1 << " ";
	}
	cout << ((vec.cbegin() == vec.cend()) ? "empty\n" : "\n");
}

int main()
{
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4 {10};
	vector<int> v5 {10, 42};
	vector<string> v6 {10};
	vector<string> v7 {10, "hi"};
	cout << "v1:\t";
	Print(v1);
	cout << "v2:\t";
	Print(v2);
	cout << "v3:\t";
	Print(v3);
	cout << "v4:\t";
	Print(v4);
	cout << "v5:\t";
	Print(v5);
	cout << "v6:\t";
	Print(v6);
	cout << "v7:\t";
	Print(v7);

	return 0;
}
```

###Exercise 3.22

>Revise the loop that printed the first paragraph in text to instead change the elements in text that correspond to the first paragraph to all uppercase. After you’ve updated text, print its contents.

```cpp
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main()
{
	vector<string> text;
	for(string line; getline(cin, line); )
	{
		text.push_back(line);
	}

	vector<string>::iterator it = text.begin();
	for(; it != text.end() && !it->empty(); ++it)
	{
		for(char &ch : *it)
		{
			ch = (('a' <= ch && ch <= 'z') ? ch -32 : ch);
		}
		cout << *it << endl;
	}

	return 0;
}
```

###Exercise 3.23

>Write a program to create a vector with ten int elements. Using an iterator, assign each element a value that is twice its current value. Test your program by printing the vector.

```cpp
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

template<typename T>
void Double(vector<T> &vec)
{
	typename vector<T>::iterator it1 = vec.begin(), it2 = vec.end();
	for(; it1 != it2; ++it1)
	{
		*it1 *= 2;
	}
}

template<typename T>
void Print(vector<T> &vec)
{
	typename vector<T>::const_iterator it1 = vec.cbegin(), it2 = vec.cend();
	for(; it1 != it2; ++it1)
	{
		cout << *it1 << " ";
	}
	cout << ((vec.cbegin() == vec.cend()) ? "empty\n" : "\n");
}

int main()
{
	vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	Double(vec);
	Print(vec);

	return 0;
}
```

##Exercises Section 3.4.2

###Exercise 3.24

>Redo the last exercise from § 3.3.3 (p. 105) using iterators.

```cpp
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int main()
{
	vector<int> vec;
	int input = 0, length = 1;
	cin >> input;
	vec.push_back(input);

	// First print the sum of each pair of adjacent elements:
	cout << "Sum of each pair of adjacent elements:\n";
	int first = input;
	while(cin >> input)
	{
		cout << first + input << ' ';
		first = input;
		vec.push_back(input);
		++length;
	}

	// Second print the sum of the first and last elements, and so on.
	cout << "\nSum of the first and last elements, and so on:\n";
	vector<int>::const_iterator it1 = vec.cbegin(), it2 = it1 + length / 2, it3 = vec.cend() - 1;
	for( ; it1 != it2; ++it1, --it3)
	{
		cout << *it1 + *it3 << ' ';
	}

	return 0;
}
```

###Exercise 3.25

>Rewrite the grade clustering program from § 3.3.3 (p. 104) using iterators instead of subscripts.

```cpp
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int main()
{
	vector<int> scores(11, 0);
	int grade;
	while (cin >> grade)
	{
		if(grade <= 100)
		{
			++(*(scores.begin() + grade / 10));
		}
	}

	for(int score : scores)
	{
		cout << score << " ";
	}
	cout << '\n';

	return 0;
}
```

###Exercise 3.26

>In the binary search program on page 112, why did we write mid = beg + (end - beg) / 2; instead of mid = (beg + end) / 2?

 - Because the iterator of vector don't define the + operator between the two iterators. So, beg + end is illegal. We can only use the subtraction between the two iterators.

##Exercises Section 3.5.1

###Exercise 3.27

>Assuming txt_size is a function that takes no arguments and returns an int value, which of the following definitions are illegal? Explain why.
unsigned buf_size = 1024;
(a) int ia[buf_size]; ok
(b) int ia[4 * 7 - 14]; ok
(c) int ia[txt_size()]; ok
(d) char st[11] = "fundamental"; error

 - Legal.
 - Legal.
 - Legal.
 - Illegal: char st[12] or larger.

###Exercise 3.28

>What are the values in the following arrays?

```cpp
string sa[10];
int ia[10];
int main()
{
	string sa2[10];
	int ia2[10];
}
```
 - Empty string:””
 - 0
 - Empty string: “”
 - Undefined.

###Exercise 3.29

>List some of the drawbacks of using an array instead of a vector.

 - Can’t grow.

##3.5.2. Accessing the Elements of an Array
 - We can use a range for or the subscript(range: [0, array.size - 1]) operator to access elements of an array.
 - Array’s subscripts’ type is size_t which is an unsigned type that is guaranteed to be large enough to hold the size of any object in memory and it is defined in the <cstddef>.

##Exercises Section 3.5.2

###Exercise 3.30

>Identify the indexing errors in the following code:
```cpp
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
	ia[ix] = ix;
```

 - [0, 9]

###Exercise 3.31

>Write a program to define an array of ten ints. Give each element the same value as its position in the array.

```cpp
int arr1[10]
for(int index = 0; index < 10; ++index)
	arr1[index] = index;
```

###Exercise 3.32

>Copy the array you defined in the previous exercise into another array. Rewrite your program to use vectors.

```cpp
int arr2[10];
for(int index = 0; index < 10; ++index)
	arr2[index] = arr1[index];
```

###Exercise 3.33

>What would happen if we did not initialize the scores array in the program on page 116?

 - The results will be undefined!

##Exercises Section 3.5.3

###Exercise 3.34

>Given that p1 and p2 point to elements in the same array, what does the following code do? Are there values of p1 or p2 that make this code illegal?
`p1 += p2 - p1;`
 - Make p1 = p2. Always legal.

###Exercise 3.35

>Using pointers, write a program to set the elements in an array to zero.

```cpp
int arr[10];
for(int *ptr1 = std::begin(arr), *ptr2 = std::end(arr); ptr1 != ptr2; ++ptr1)
{
	*ptr1 = 0;
}
```

###Exercise 3.36

>Write a program to compare two arrays for equality. Write a similar program to compare two vectors.

```cpp
#include <iostream>
#include <vector>

using std::cout;
using std::begin;
using std::end;
using std::vector;

bool CompareArray(int *arr1_begin, int *arr1_end, int *arr2_begin, int *arr2_end)
{
	int length1 = arr1_end - arr1_begin, length2 = arr2_end - arr2_begin;
	if(length1 != length2)
	{
		return false;
	}
	for(int index = 0; index < length1; ++index)
	{
		if(*(arr1_begin + index) != *(arr2_begin + index))
		{
			return false;
		}
	}
	return true;
}

bool CompareVector(vector<int> &vec1, vector<int> &vec2)
{
	if(vec1 == vec2)
	{
		return true;
	}
	return false;
}

int main()
{
	int arr1[] = {1, 2, 3, 4, 5}, arr2[] = {1, 2, 3, 4, 5};
	cout << CompareArray(begin(arr1), end(arr1), begin(arr2), end(arr2)) << '\n';
	vector<int> vec1(5, 6), vec2(5, 7);
	cout << CompareVector(vec1, vec2);

	return 0;
}
/*
Output:
1
0
*/
```

##Exercises Section 3.5.4

###Exercise 3.37

>What does the following program do?
```cpp
const char ca[] = {'h', 'e', 'l', 'l', 'o'};
const char *cp = ca;
while (*cp)
{
	cout << *cp << endl;
	++cp;
}
```

 - Print from ca to the first ‘\0’

###Exercise 3.38

>In this section, we noted that it was not only illegal but meaningless to try to add two pointers. Why would adding two pointers be meaningless?

 - Because it generates a meaningless address.

###Exercise 3.39

>Write a program to compare two strings. Now write a program to compare the values of two C-style character strings.

```cpp
#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::string;

int main()
{
	string str1 = "gao", str2 = "gaoxiang";
	cout << "Larger: " << ((str1 > str2) ? str1 : str2) << '\n';  // gaoxiang

	char arr1[] = "gaoxiang", arr2[] = "gao";
	cout << "Larger: " << (strcmp(arr1, arr2) > 0 ? arr1 : arr2) << '\n';  // gaoxiang

	return 0;
}
```

###Exercise 3.40

>Write a program to define two character arrays initialized from string literals. Now define a third character array to hold the concatenation of the two arrays. Use strcpy and strcat to copy the two arrays into the third.

```cpp
#include <iostream>
#include <cstring>

using std::cout;

int main()
{
	char arr1[] = "gao", arr2[] = "xiang", arr3[9];
	strcat(arr1, arr2);
	strcpy(arr3, arr1);
	cout << arr3 << '\n';

	return 0;
}
/*
Output:
gaoxiang
*/
```

##Exercises Section 3.5.5

###Exercise 3.41

>Write a program to initialize a vector from an array of ints.

```cpp
#include <iostream>
#include <vector>

using std::cout;
using std::begin;
using std::end;
using std::vector;

template<typename T>
void Print(vector<T> &vec)
{
	typename vector<T>::const_iterator it1 = vec.cbegin(), it2 = vec.cend();
	for(; it1 != it2; ++it1)
	{
		cout << *it1 << " ";
	}
	cout << ((vec.cbegin() == vec.cend()) ? "empty\n" : "\n");
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	vector<int> vec(begin(arr), end(arr));
	Print(vec);

	return 0;
}
/*
Output:
1 2 3 4 5
*/
```

###Exercise 3.42

>Write a program to copy a vector of ints into an array of ints.

```cpp
#include <iostream>
#include <vector>

using std::vector;

int main()
{
	vector<int> vec(10, 5);
	int length = vec.size();
	int arr[length];
	for(int index = 0; index < length; ++index)
	{
		arr[index] = vec[index];
	}

	return 0;
}
```

##Exercises Section 3.6

###Exercise 3.43

>Write three different versions of a program to print the elements of ia. One version should use a range for to manage the iteration, the other two should use an ordinary for loop in one case using subscripts and in the other using pointers. In all three programs write all the types directly. That is, do not use a type alias, auto, or decltype to simplify the code.

```cpp
#include <iostream>

using std::cout;

int main()
{
	int arr[3][4] = {{ 0, 1, 2, 3 }, { 4, 5, 6, 7 }, { 8, 9, 10, 11 }};

	cout << "Version 1: Range for\n";
	for(int (&row)[4] : arr)
	{
		for(int &col : row)
		{
			cout << col << ' ';
		}
	}

	cout << "\nVersion 2: Ordinary for using subscripts\n";
	for(int index1 = 0; index1 < 3; ++index1)
	{
		for(int index2 = 0; index2 < 4; ++index2)
		{
			cout << arr[index1][index2] << ' ';
		}
	}

	cout << "\nVersion 3: Ordinary for using pointers\n";
	for(int (*row)[4] = arr; row != arr + 3; ++row)
	{
		for(int *col = *row; col != *row + 4; ++col)
		{
			cout << *col << ' ';
		}
	}

	return 0;
}
/*
Version 1: Range for
0 1 2 3 4 5 6 7 8 9 10 11
Version 2: Ordinary for using subscripts
0 1 2 3 4 5 6 7 8 9 10 11
Version 3: Ordinary for using pointers
0 1 2 3 4 5 6 7 8 9 10 11
*/
```

###Exercise 3.44

>Rewrite the programs from the previous exercises using a type alias for the type of the loop control variables.

```cpp
#include <iostream>

using std::cout;

using int_array = int[4];

int main()
{
	int arr[3][4] = {{ 0, 1, 2, 3 }, { 4, 5, 6, 7 }, { 8, 9, 10, 11 }};

	for(int_array *row = arr; row != arr + 3; ++row)
	{
		for(int *col = *row; col != *row + 4; ++col)
		{
			cout << *col << ' ';
		}
	}

	return 0;
}
/*
0 1 2 3 4 5 6 7 8 9 10 11
*/
```

###Exercise 3.45

>Rewrite the programs again, this time using auto.

```cpp
#include <iostream>

using std::cout;

int main()
{
	int arr[3][4] = {{ 0, 1, 2, 3 }, { 4, 5, 6, 7 }, { 8, 9, 10, 11 }};

	for(auto &row : arr)
	{
		for(auto col : row)
		{
			cout << col << ' ';
		}
	}

	return 0;
}
/*
0 1 2 3 4 5 6 7 8 9 10 11
*/
```


