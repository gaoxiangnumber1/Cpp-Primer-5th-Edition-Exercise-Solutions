#CH5

##Exercises Section 5.1

###Exercise 5.1

>What is a null statement? When might you use a null statement?

 - ;

###Exercise 5.2

>What is a block? When might you might use a block?

 - A compound statement, referred to as a block, is a(possibly empty) sequence of statements and declarations surrounded by a pair of curly braces.

###Exercise 5.3

>Use the comma operator(§ 4.10, p. 157) to rewrite the while loop from §1.4.1 (p. 11) so that it no longer requires a block. Explain whether this rewrite improves or diminishes the readability of this code.

 - diminishes the readability of this code

##Exercises Section 5.2

###Exercise 5.4

>Explain each of the following examples, and correct any problems you detect.
(a)	while(string::iterator iter != s.end()) { /* . . . */ }
(b)	while (bool status = find(word)) { /* . . . */ }
	if (!status) { /* . . . */ }

 - Not initialized.
 - status is out of scope.

##Exercises Section 5.3.1

###Exercise 5.5

>Using an if-else statement, write your own version of the program to generate the letter grade from a numeric grade.

```cpp
#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::vector;
using std::string;

int main()
{
	vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
	for(int grade = 0; cin >> grade;)
	{
		string letter;
		if(grade < 60)
		{
			letter = scores[0];
		}
		else
		{
			letter = scores[(grade - 50) / 10];
			if(grade != 100)
			{
				letter += (grade % 10 > 7 ? "+" : (grade % 10 < 3 ? "-" : ""));
			}
		}
		cout << letter << '\n';
	}

	return 0;
}
```

###Exercise 5.6

>Rewrite your grading program to use the conditional operator(§ 4.7, p. 151) in place of the if-else statement.

```cpp
#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::vector;
using std::string;

int main()
{
	vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
	int grade = 0;
	while(cin >> grade)
	{
		string lettergrade = grade < 60 ? scores[0] : scores[(grade - 50) / 10];
		lettergrade +=
		    (grade == 100 || grade < 60)
		    ? ""
		    : (grade % 10 > 7) ? "+" : (grade % 10 < 3) ? "-" : "";
		cout << lettergrade << '\n';
	}

	return 0;
}
```

###Exercise 5.7

>Correct the errors in each of the following code fragments:
(a)
if (ival1 != ival2)
	ival1 = ival2
else ival1 = ival2 = 0;
(b)
if (ival < minval)
	minval = ival;
	occurs = 1;
(c)
if (int ival = get_value())
	cout << "ival = " << ival << endl;
if (!ival)
	cout << "ival = 0\n";
(d)
if (ival = 0)
	ival = get_value();

 - ival1 = ival2;
 - Add braces
 - out of scope
 - if(ival == 0)

###Exercise 5.8

>What is “dangling else”? How are clauses resolved in C++?

 - dangling else: how do we know to which if a given else belongs?
 - Each else is matched with the closest preceding unmatched if.

##Exercises Section 5.3.2

###Exercise 5.9

>Write a program using a series of if statements to count the number of vowels in text read from cin.

```cpp
#include <iostream>

using std::cin;
using std::cout;

int main()
{
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	char ch;
	while(cin >> ch)
	{
		if (ch == 'a')
		{
			++aCnt;
		}
		else if (ch == 'e')
		{
			++eCnt;
		}
		else if (ch == 'i')
		{
			++iCnt;
		}
		else if (ch == 'o')
		{
			++oCnt;
		}
		else if (ch == 'u')
		{
			++uCnt;
		}
	}
	cout << "Number of vowel a: \t" << aCnt << '\n'
	     << "Number of vowel e: \t" << eCnt << '\n'
	     << "Number of vowel i: \t" << iCnt << '\n'
	     << "Number of vowel o: \t" << oCnt << '\n'
	     << "Number of vowel u: \t" << uCnt << '\n';

	return 0;
}
```

###Exercise 5.10

>There is one problem with our vowel-counting program as we’ve implemented it: It doesn’t count capital letters as vowels. Write a program that counts both lower- and uppercase letters as the appropriate vowel—that is, your program should count both 'a' and 'A' as part of aCnt, and so forth.

```cpp
#include <iostream>

using std::cin;
using std::cout;

int main()
{
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	char ch;
	while(cin >> ch)
	{
		switch (ch)
		{
		case 'a':
		case 'A':
			++aCnt;
			break;
		case 'e':
		case 'E':
			++eCnt;
			break;
		case 'i':
		case 'I':
			++iCnt;
			break;
		case 'o':
		case 'O':
			++oCnt;
			break;
		case 'u':
		case 'U':
			++uCnt;
			break;
		}
	}
	cout << "Number of vowel a(A): \t" << aCnt << '\n'
	     << "Number of vowel e(E): \t" << eCnt << '\n'
	     << "Number of vowel i(I): \t" << iCnt << '\n'
	     << "Number of vowel o(O): \t" << oCnt << '\n'
	     << "Number of vowel u(U): \t" << uCnt << '\n';

	return 0;
}
```

###Exercise 5.11

>Modify our vowel-counting program so that it also counts the number of blank spaces, tabs, and newlines read.

```cpp
#include <iostream>

using std::cin;
using std::cout;

int main()
{
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	int spaceCnt = 0, tabCnt = 0, newlineCnt = 0;
	char ch;
	while(cin >> std::noskipws >> ch)
	{
		switch (ch)
		{
		case 'a':
		case 'A':
			++aCnt;
			break;
		case 'e':
		case 'E':
			++eCnt;
			break;
		case 'i':
		case 'I':
			++iCnt;
			break;
		case 'o':
		case 'O':
			++oCnt;
			break;
		case 'u':
		case 'U':
			++uCnt;
			break;
		case ' ':
			++spaceCnt;
			break;
		case '\t':
			++tabCnt;
			break;
		case '\n':
			++newlineCnt;
			break;
		}
	}
	cout << "Number of vowel a(A): \t" << aCnt << '\n'
	     << "Number of vowel e(E): \t" << eCnt << '\n'
	     << "Number of vowel i(I): \t" << iCnt << '\n'
	     << "Number of vowel o(O): \t" << oCnt << '\n'
	     << "Number of vowel u(U): \t" << uCnt << '\n'
	     << "Number of space: \t" << spaceCnt << '\n'
	     << "Number of tab char: \t" << tabCnt << '\n'
	     << "Number of new line: \t" << newlineCnt << '\n';

	return 0;
}
```

###Exercise 5.12

>Modify our vowel-counting program so that it counts the number of occurrences of the following two-character sequences: ff, fl, and fi.

```cpp
#include <iostream>

using std::cin;
using std::cout;

int main()
{
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	int spaceCnt = 0, tabCnt = 0, newlineCnt = 0, ffCnt = 0, flCnt = 0, fiCnt = 0;
	char ch, prech = '\0';
	while (cin >> std::noskipws >> ch)
	{
		switch (ch)
		{
		case 'a':
		case 'A':
			++aCnt;
			break;
		case 'e':
		case 'E':
			++eCnt;
			break;
		case 'i':
			if (prech == 'f')
			{
				++fiCnt;
			}
		case 'I':
			++iCnt;
			break;
		case 'o':
		case 'O':
			++oCnt;
			break;
		case 'u':
		case 'U':
			++uCnt;
			break;
		case ' ':
			++spaceCnt;
			break;
		case '\t':
			++tabCnt;
			break;
		case '\n':
			++newlineCnt;
			break;
		case 'f':
			if (prech == 'f')
			{
				++ffCnt;
			}
			break;
		case 'l':
			if (prech == 'f')
			{
				++flCnt;
			}
			break;
		}
		prech = ch;
	}

	cout << "Number of vowel a(A): \t" << aCnt << '\n'
	     << "Number of vowel e(E): \t" << eCnt << '\n'
	     << "Number of vowel i(I): \t" << iCnt << '\n'
	     << "Number of vowel o(O): \t" << oCnt << '\n'
	     << "Number of vowel u(U): \t" << uCnt << '\n'
	     << "Number of space: \t" << spaceCnt << '\n'
	     << "Number of tab char: \t" << tabCnt << '\n'
	     << "Number of new line: \t" << newlineCnt << '\n'
	     << "Number of ff: \t" << ffCnt << '\n'
	     << "Number of fl: \t" << flCnt << '\n'
	     << "Number of fi: \t" << fiCnt << '\n';

	return 0;
}
```

###Exercise 5.13

>Each of the programs in the highlighted text on page 184 contains a common programming error. Identify and correct each error.

```
// b:
unsigned index = some_value();
switch (index)
{
case 1:
	int ix = get_value();
	ivec[ ix ] = index;
	break;
default:
	ix = ivec.size()-1;
	ivec[ ix ] = index;
}
//c
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit)
{
case 1, 3, 5, 7, 9:
	oddcnt++;
	break;
case 2, 4, 6, 8, 10:
	evencnt++;
	break;
}
```
 - Omit “break;”
 - ix is out of scope
 - case labels should be one number only.
 - case labels must be constants expressions.

##Exercises Section 5.4.1

###Exercise 5.14

>Write a program to read strings from standard input looking for duplicated words. The program should find places in the input where one word is followed immediately by itself. Keep track of the largest number of times a single repetition occurs and which word is repeated. Print the maximum number of duplicates, or else print a message saying that no word was repeated. For example, if the input is
`how now now now brown cow cow`
the output should indicate that the word now occurred three times.

```cpp
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
	string pre_word = "", word = "", max_repeat_word = "";
	int repeat_times = 0, max_repeat_times = 0;

	while (cin >> word)
	{
		if (word == pre_word)
		{
			++repeat_times;
		}
		else
		{
			repeat_times = 1;
			pre_word = word;
		}

		if (max_repeat_times < repeat_times)
		{
			max_repeat_times = repeat_times;
			max_repeat_word = pre_word;
		}
	}

	if (max_repeat_times <= 1)
	{
		cout << "no word was repeated" << '\n';
	}
	else
	{
		cout << "the word '" << max_repeat_word << "' occurred " << max_repeat_times << " times" << '\n';
	}
}
```

##Exercises Section 5.4.2

###Exercise 5.15

>Explain each of the following loops. Correct any problems you detect.
```c
(a)
for(int ix = 0; ix != sz; ++ix) { /* . . . */ }
if(ix != sz)
	// . . .
(b)
int ix;
for(ix != sz; ++ix) { /* . . . */ }
(c)
for (int ix = 0; ix != sz; ++ix, ++ sz) { /* . . . */ }
```

 - ix is out of scope
 - omit init-statement of for(;;)
 - infinity loop

###Exercise 5.16

>The while loop is particularly good at executing while some condition holds; for example, when we need to read values until end-of-file. The for loop is generally thought of as a step loop: An index steps through a range of values in a collection. Write an idiomatic use of each loop and then rewrite each using the other loop construct. If you could use only one loop, which would you choose? Why?

```cpp
// while idiomatic 
int i; 
while ( cin >> i )
	// ... 
// same as for 
for (int i = 0; cin >> i;)
	// ... 
// for idiomatic 
for (int i = 0; i != size; ++i)
	// ... 
// same as while 
int i = 0; 
while (i != size)
{
	// ...
	++i; 
}
```

###Exercise 5.17

>Given two vectors of ints, write a program to determine whether one vector is a prefix of the other. For vectors of unequal length, compare the number of elements of the smaller vector. For example, given the vectors containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5, 8, respectively your program should return true.

```cpp
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

bool IsPrefix(vector<int> &lhs, vector<int> &rhs)
{
	if(lhs.size() > rhs.size())
	{
		return IsPrefix(rhs, lhs);
	}
	for(int index = 0; index != lhs.size(); ++index)
	{
		if(lhs[index] != rhs[index])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	vector<int> vec1 = { 0, 1, 1, 2 };
	vector<int> vec2 = { 0, 1, 1, 2, 3, 5, 8 };
	cout << (IsPrefix(vec1, vec2) ? "Yes\n" : "No\n");

	return 0;
}
```

##Exercises Section 5.4.4

###Exercise 5.18

>Explain each of the following loops. Correct any problems you detect.
```cpp
(a)
do
{
	int v1, v2;
	cout << "Please enter two numbers to sum:" ;
	if(cin >> v1 >> v2)
	{
		cout << "Sum is: " << v1 + v2 << endl;
	}
}
while(cin);
(b)
do
{
	// . . .
}
while (int ival = get_response());
(c)
do
{
	int ival = get_response();
}
while (ival);
```

 - Right
 - `int ival;` before do{}while();
 - ival is out of scope.

###Exercise 5.19

>Write a program that uses a do while loop to repetitively request two strings from the user and report which string is less than the other.

```cpp
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	string judge, str1, str2;
	do
	{
		cout << "Input two strings: ";
		cin >> str1 >> str2;
		cout << (str1 <= str2 ? str1 : str2) << " is small\n";
		cout << "Continue?(y/n): ";
		cin >> judge;
	}
	while(judge == "y");
	return 0;
}
```

##Exercises Section 5.5.1

###Exercise 5.20

>Write a program to read a sequence of strings from the standard input until either the same word occurs twice in succession or all the words have been read. Use a while loop to read the text one word at a time. Use the break statement to terminate the loop if a word occurs twice in succession. Print the word if it occurs twice in succession, or else print a message saying that no word was repeated.

```cpp
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	string read, tmp;
	while (cin >> read)
	{
		if (read == tmp)
		{
			break;
		}
		else
		{
			tmp = read;
		}
	}
	if (cin.eof())
	{
		cout << "no word was repeated." << endl;
	}
	else
	{
		cout << read << " occurs twice in succession." << endl;
	}
	return 0;
}
```

##Exercises Section 5.5.2

###Exercise 5.21

>Revise the program from the exercise in § 5.5.1 (p. 191) so that it looks only for duplicated words that start with an uppercase letter.

```cpp
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string curr, prev;
	bool no_twice = true;
	while (cin >> curr)
	{
		if(isupper(curr[0]) && prev == curr)
		{
			cout << curr << ": occurs twice in succession." << endl;
			no_twice = false;
			break;
		}
		prev = curr;
	}

	if (no_twice)
	{
		cout << "no word was repeated." << endl;
	}

	return 0;
}
```

##Exercises Section 5.5.3

###Exercise 5.22

>The last example in this section that jumped back to begin could be better written using a loop. Rewrite the code to eliminate the goto.

```cpp
for(int sz = get_size(); sz <= 0; sz = get_size());
```

##Exercises Section 5.6.3

###Exercise 5.23

>Write a program that reads two integers from the standard input and prints the result of dividing the first number by the second.

```cpp
#include <iostream>

using std::cin;
using std::cout;

int main(void)
{
	int a, b;
	cin >> a >> b;
	cout << a / b;

	return 0;
}
```

###Exercise 5.24

>Revise your program to throw an exception if the second number is zero. Test your program with a zero input to see what happens on your system if you don’t catch an exception.

```cpp
#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::runtime_error;

int main()
{
	int a, b;
	cin >> a >> b;
	if(b == 0)
	{
		throw runtime_error("Input Error: 0");
	}
	cout << a / b;

	return 0;
}
```

###Exercise 5.25

>Revise your program from the previous exercise to use a try block to catch the exception. The catch clause should print a message to the user and ask them to supply a new number and repeat the code inside the try.

```cpp
#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main()
{
	int num1, num2;
	cout << "Input two integers: ";
	while(cin >> num1 >> num2)
	{
		try
		{
			if(num2 == 0)
			{
				throw runtime_error("Divisor is 0");
			}
			cout << num1 / num2 << endl;
			cout << "Input two integers: ";
		}
		catch (runtime_error error)
		{
			cout << error.what() << "\n" << "Try again.\nInput two integers: ";
		}
	}

	return 0;
}
```


