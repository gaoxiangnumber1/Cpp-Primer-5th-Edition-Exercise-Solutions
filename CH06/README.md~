# CH6

##Exercises Section 6.1

###Exercise 6.1

>What is the difference between a parameter and an argument?

 - Parameters: Local variable declared inside the function parameter list. They are initialized by the arguments provided in the each function call.
 - Arguments: Values supplied in a function call that are used to initialize the function's parameters.

###Exercise 6.2

>Indicate which of the following functions are in error and why. Suggest how you might correct the problems.
(a)
int f()
{
	string s;
	// ...
	return s;
}
(b) f2(int i) { /* ... */ }
(c) int calc(int v1, int v1) {/* ... */ } 
(d) double square(double x) return x * x;

 - Return type don’t match. `string f()`
 - Omit return type. `Type f2(int i)`
 - Duplicate parameter name. `int calc(int v1, int v2) {/* ... */ }`
 - Right

###Exercise 6.3

>Write and test your own version of fact.

```cpp
#include <iostream>

using std::cin;
using std::cout;

int fact(int val)
{
	int result = 0;
	if(val < 0)
	{
		cout << "Input error! Try Again.\n";
	}
	else if(val == 0 || val == 1)
	{
		result = 1;
	}
	else
	{
		result = val * fact(val - 1);
	}
	return result;
}

int main()
{
	for(int num = 0; cin >> num; )
	{
		cout << fact(num) << '\n';
	}

	return 0;
}
```

###Exercise 6.4

>Write a function that interacts with the user, asking for a number and generating the factorial of that number. Call this function from main.

 - Same as 6.3

###Exercise 6.5

>Write a function to return the absolute value of its argument.

```cpp
template<typename T>
T Abs(T obj)
{
	return(obj >= 0 ? obj : -obj);
}
```

##Exercises Section 6.1.1

###Exercise 6.6

>Explain the differences between a parameter, a local variable, and a local static variable. Give an example of a function in which each might be useful.

 - local variable: Variables defined inside a block;
 - parameter: Local variables declared inside the function parameter list
 - local static variable: local static variable(object) is initialized before the first time execution passes through the object’s definition.Local statics are not destroyed when a function ends; they are destroyed when the program terminates.
```cpp
size_t count_add(int n)// n is a parameter.
{
	static size_t ctr = 0;// ctr is a static variable.
	ctr += n;
	return ctr;
}

int main()
{
	for(size_t i = 0; i != 10; ++i)// i is a local variable.
	{
		cout << count_add(i) << endl;
	}

	return 0;
}
```

###Exercise 6.7

>Write a function that returns 0 when it is first called and then generates numbers in sequence each time it is called again.

```cpp
size_t generate()
{
	static size_t ctr = 0;
	return ctr++;
}
```

##Exercises Section 6.1.2

###Exercise 6.8

>Write a header file named Chapter6.h that contains declarations for the functions you wrote for the exercises in § 6.1(p. 205).

```cpp
int fact(int val);
int func();

template <typename T>
T Abs(T obj)
{
    return obj >= 0 ? obj : -obj;
}
```

##Exercises Section 6.1.3

###Exercise 6.9

>Write your own versions of the fact.cc and factMain.cc files. These files should include your Chapter6.h from the exercises in the previous section. Use these files to understand how your compiler supports separate compilation.

```cpp
// fact.cc
#include "Chapter6.h"

int fact(int val)
{
	if(val == 0 || val == 1)
	{
		return 1;
	}
	else
	{
		return val * fact(val - 1);
	}
}
```
```cpp
// factMain.cc
#include <iostream>
#include "Chapter6.h"

using std::cout;

int main()
{
    cout << "5! = " << fact(5) << '\n';
    cout << Abs(-7188) << '\n';
}
```
```cpp
$ g++ fact.cc factMain.cc -o main
$ ./main 
5! = 120
7188
```

##Exercises Section 6.2.1

###Exercise 6.10

>Using pointers, write a function to swap the values of two ints. Test the function by calling it and printing the swapped values.

```cpp
#include <iostream>

using std::cout;

void Swap(int *ptr1, int *ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

int main()
{
	int num1 = 10, num2 = 20;
	int *ptr1 = &num1, *ptr2 = &num2;
	Swap(ptr1, ptr2);
	cout << num1 << '\t' << num2;  // 20 10

	return 0;
}
```

##Exercises Section 6.2.2

###Exercise 6.11

>Write and test your own version of reset that takes a reference.

```cpp
#include <iostream>

using std::cout;

void reset(int &num)
{
	num = 0;
}

int main()
{
	int num = 42;
	reset(num);
	cout << num;
	return 0;
}
```

###Exercise 6.12

>Rewrite the program from exercise 6.10 in § 6.2.1(p. 210) to use references instead of pointers to swap the value of two ints. Which version do you think would be easier to use and why?

```cpp
#include <iostream>

using std::cout;

void Swap(int &ref1, int &ref2)
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

int main()
{
	int num1 = 10, num2 = 20;
	int &ref1 = num1, &ref2 = num2;
	Swap(ref1, ref2);
	cout << num1 << '\t' << num2;  // 20 10

	return 0;
}
```

###Exercise 6.13

>Assuming T is the name of a type, explain the difference between a function declared as void f(T) and void f(T&).

 - `void f(T)` pass arguments by value.
 - `void f(T&)` pass arguments by references.

###Exercise 6.14

>Give an example of when a parameter should be a reference type. Give an example of when a parameter should not be a reference.

 - Should: we need change it or it is large.
 - Should not:
```cpp
void print(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for(std::vector<int>::iterator iter = begin; iter != end; ++iter)
	{
		std::cout << *iter << std::endl;
	}
}
```

###Exercise 6.15

>Explain the rationale for the type of each of find_char’s parameters In particular, why is s a reference to const but occurs is a plain reference? Why are these parameters references, but the char parameter c is not? What would happen if we made s a plain reference? What if we made occurs a reference to const?

 - Why is s a reference to const but occurs is a plain reference?
cause the s should not be changed by this function. but occurs' result must be calculated by the function.
 - Why are these parameters references, but the char parameter c is not?
cause c maybe a temp variable. such as find_char(s, 'a', occurs)
 - What would happen if we made s a plain reference? What if we made occurs a reference to const?
s could be changed in the function, and occurs would not be changed. so occurs = 0; is an error.

##Exercises Section 6.2.3

###Exercise 6.16

>The following function, although legal, is less useful than it might be. Identify and correct the limitation on this function:
`bool is_empty(string& s) { return s.empty(); }`

```cpp
bool is_empty(const string &s)
{
	return s.empty();
}
```

###Exercise 6.17

>Write a function to determine whether a string contains any capital letters. Write a function to change a string to all lowercase. Do the parameters you used in these functions have the same type? If so, why? If not, why not?

```cpp
#include <iostream>
#include <string>

using std::cout;
using std::string;

// Whether a string contains any capital letters
bool HasCapitalLetter(const string &str)
{
	for(char ch : str)
	{
		if('A' <= ch && ch <= 'Z')
		{
			return true;
		}
	}
	return false;
}

// Change a string to all lowercase
void ToAllLowercase(string &str)
{
	for(char &ch : str)
	{
		ch =(('A' <= ch && ch <= 'Z') ? ch +('a' - 'A') : ch);
	}
}

int main()
{
	string str1 = "Gaoxiangnumber1";
	string str2 = "gaoxiangnumber1";
	cout << HasCapitalLetter(str1) << '\t' << HasCapitalLetter(str2) << '\t' <<
	     HasCapitalLetter("gaoxiangNumber1") << '\n';  // 1 0 1

	ToAllLowercase(str1);
	cout << str1;  // gaoxiangnumber1

	return 0;
}
/*
1	0	1
gaoxiangnumber1
*/
```

###Exercise 6.18

>Write declarations for each of the following functions. When you write these declarations, use the name of the function to indicate what the function does.
(a) A function named compare that returns a bool and has two parameters that are references to a class named matrix.
(b) A function named change_val that returns a vector<int> iterator and takes two parameters: One is an int and the other is an iterator for a vector<int>.

 - bool compare(const matrix &obj1, const matrix &obj2);
 - vector<int>::iterator change_val(int num, vector<int>::iterator &it);

###Exercise 6.19

>Given the following declarations, determine which calls are legal and which are illegal. For those that are illegal, explain why.
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);
(a) calc(23.4, 55.1);
(b) count("abcda", 'a');
(c) calc(66);
(d) sum(vec.begin(), vec.end(), 3.8);

 - Illegal: too many arguments
 - Legal
 - Legal
 - Legal

###Exercise 6.20

>When should reference parameters be references to const? What happens if we make a parameter a plain reference when it could be a reference to const?

 - When we don’t change parameters’ value.
 - Compile error.

##Exercises Section 6.2.4

###Exercise 6.21

>Write a function that takes an int and a pointer to an int and returns the larger of the int value or the value to which the pointer points. What type should you use for the pointer?

```cpp
int Fun(const int num, const int *ptr)
{
	return((num > *ptr) ? num : *ptr);
}
```

###Exercise 6.22

>Write a function to swap two int pointers.

```cpp
#include <iostream>

using std::cout;

void Fun(int* &ptr1, int* &ptr2)
{
	int *tmp = ptr1;
	ptr1 = ptr2;
	ptr2 = tmp;
}

int main()
{
	int num1 = 1, num2 = 2, *ptr1 = &num1, *ptr2 = &num2;
	cout << ptr1 << '\t' << *ptr1 << '\t' << ptr2 << '\t' << *ptr2 << '\n';
	Fun(ptr1, ptr2);
	cout << ptr1 << '\t' << *ptr1 << '\t' << ptr2 << '\t' << *ptr2 << '\n';
	return 0;
}
/*
0x7ffce66860d8	1	0x7ffce66860dc	2
0x7ffce66860dc	2	0x7ffce66860d8	1
*/
```

###Exercise 6.23

>Write your own versions of each of the print functions presented in this section. Call each of these functions to print i and j defined as follows:
`int i = 0, j[2] = {0, 1};`

```cpp
#include <iostream>

using std::cout;
using std::endl;
using std::begin;
using std::end;

void print(const int *pi)
{
	if(pi)
	{
		cout << *pi << endl;
	}
}

void print(const char *p)
{
	if(p)
	{
		while(*p)
		{
			cout << *p++;
		}
	}
	cout << endl;
}

void print(const int *beg, const int *end)
{
	while(beg != end)
	{
		cout << *beg++ << endl;
	}
}

void print(const int ia[], size_t size)
{
	for(size_t i = 0; i != size; ++i)
	{
		cout << ia[i] << endl;
	}
}

void print(int(&arr)[2])
{
	for(auto i : arr)
	{
		cout << i << endl;
	}
}

int main()
{
	int i = 0, j[2] = { 0, 1 };

	print(begin(j), end(j));
	print(&i);
	print(j, end(j)-begin(j));
	print(j);

	return 0;
}
```

###Exercise 6.24

>Explain the behavior of the following function. If there are problems in the code, explain what they are and how you might fix them.

```cpp
void print(const int ia[10])
{
	for(size_t i = 0; i != 10; ++i)
		cout << ia[i] << endl;
}
```
 - The size of array is may not be 10. We should provide explicitly size argument.

##Exercises Section 6.2.5

###Exercise 6.25

>Write a main function that takes two arguments. Concatenate the supplied arguments and print the resulting string.

```cpp
#include <cstdio>

int main(int argc, char **argv)
{
	for(int index = 0; index < argc; ++index)
	{
		printf("argv[%d]: %s\n", index, argv[index]);
	}

	return 0;
}
```

###Exercise 6.26

>Write a program that accepts the options presented in this section. Print the values of the arguments passed to main.

 - Same as 6.25.

##Exercises Section 6.2.6

###Exercise 6.27

>Write a function that takes an initializer_list<int> and produces the sum of the elements in the list.

```cpp
#include <iostream>

using std::cout;
using std::initializer_list;

void Fun(initializer_list<int> ilist)
{
	int sum = 0;
	for(initializer_list<int>::iterator beg = ilist.begin(); beg != ilist.end(); ++beg)
	{
		sum += *beg;
	}
	cout << sum << '\n';
}

int main()
{
	Fun({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

	return 0;
}
/*
Output:
55
*/
```

###Exercise 6.28

>In the second version of error_msg that has an ErrCode parameter, what is the type of elem in the for loop?

 - const std::string&

###Exercise 6.29

>When you use an initializer_list in a range for would you ever use a reference as the loop control variable? If so, why? If not, why not?

 - Depends on the type of elements of initializer_list.
1. When the type is POD-Type, reference is unnecessary. Because POD is cheap to copy(such as int).
2. Otherwise, Using reference( const) is the better choice.

##Exercises Section 6.3.2

###Exercise 6.30

>Compile the version of str_subrange as presented on page 223 to see what your compiler does with the indicated errors.

 - g++: error: return-statement with no value, in function returning ‘bool’

###Exercise 6.31

>When is it valid to return a reference? A reference to const?

 - When you can find the pre-exited object that the reference referred.

###Exercise 6.32

>Indicate whether the following function is legal. If so, explain what it does; if not, correct any errors and then explain it.

```cpp
int &get(int *arry, int index)
{
	return arry[index];
}
int main()
{
	int ia[10];
	for(int i = 0; i != 10; ++i)
		get(ia, i) = i;
}
```
 - Legal, it gave the values(0 ~ 9) to array ia .

###Exercise 6.33

>Write a recursive function to print the contents of a vector.

```cpp
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

void Print(vector<int> &vec, int index)
{
	if(index == 0)
	{
		cout << vec[0] << ' ';
		return;
	}
	Print(vec, index - 1);
	cout << vec[index] << ' ';
}

int main()
{
	vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	Print(vec, vec.size() - 1);
}
/*
Output:
1 2 3 4 5 6 7 8 9 10
*/
```

###Exercise 6.34

>What would happen if the stopping condition in factorial were
`if(val != 0)`

 - Case 1: If argument is positive, recursion stops at 0.
 - case 2 : If argument is negative, recursion would never stop. A stack overflow would occur.

###Exercise 6.35

>In the call to fact, why did we pass val - 1 rather than val--?

 - Recursive function will always use val as the parameter, so a recursion loop would happen.

##Exercises Section 6.3.3

###Exercise 6.36

>Write the declaration for a function that returns a reference to an array of ten strings, without using either a trailing return, decltype, or a type alias.

```cpp
string(&Fun(string(&array)[10]))[10]
```

###Exercise 6.37

>Write three additional declarations for the function in the previous exercise. One should use a type alias, one should use a trailing return, and the third should use decltype. Which form do you prefer and why?

```cpp
using Array = string [10];
Array &Fun(string(&array)[10]);

auto Fun(string(&array)[10]) -> string(&) [10]

string array[10];
decltype(array) &Fun(string(&array)[10])
```

###Exercise 6.38

>Revise the arrPtr function on to return a reference to the array.

```cpp
decltype(arrStr)& arrPtr(int i)
{
	return(i % 2) ? odd : even;
}
```

##Exercises Section 6.4

###Exercise 6.39

>Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.
```cpp
(a)
int calc(int, int);
int calc(const int, const int);
(b)
int get();
double get();
(c)
int *reset(int *);
double *reset(double *);
```

 - Illegal: top-level const is ignored.
 - Illegal: functions can’t differ only in return type.
 - ok.

##Exercises Section 6.5.1

###Exercise 6.40

>Which, if either, of the following declarations are errors? Why?
```cpp
(a) int ff(int a, int b = 0, int c = 0);
(b) char *init(int ht = 24, int wd, char bckgrnd);
```

 - Right
 - Error: miss the default value for wd and bckgrnd.

###Exercise 6.41

>Which, if any, of the following calls are illegal? Why? Which, if any, are legal but unlikely to match the programmer’s intent? Why?

```cpp
char *init(int ht, int wd = 80, char bckgrnd = ' ');
(a) init();
(b) init(24,10);
(c) init(14, '*');
```

 - Illegal: miss value for at least “ht”
 - Right
 - Right, but unlikely to match the programmer’s intent. We should provide value for “ht”.

###Exercise 6.42

>Give the second parameter of make_plural(§6.3.2, p.224) a default argument of 's'. Test your program by printing singular and plural versions of the words success and failure.

```cpp
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string make_plural(size_t ctr, const string& word, const string& ending = "s")
{
	return (ctr > 1) ? word + ending : word;
}

int main()
{
	cout << "singual: " << make_plural(1, "success", "es") << " "
	     << make_plural(1, "failure") << endl;
	cout << "plural : " << make_plural(2, "success", "es") << " "
	     << make_plural(2, "failure") << endl;

	return 0;
}
```

##Exercises Section 6.5.2

###Exercise 6.43

>Which one of the following declarations and definitions would you put in a header? In a source file? Explain why.
```cpp
(a) inline bool eq(const BigInt&, const BigInt&) {...}
(b) void putValues(int *arr, int size);
```

 - Declaration and definition: header file.
 - Declaration: header file; definition: source file.

###Exercise 6.44

>Rewrite the isShorter function from § 6.2.2(p. 211) to be inline.

```cpp
inline bool isShorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}
```

###Exercise 6.45

>Review the programs you’ve written for the earlier exercises and decide whether they should be defined as inline. If so, do so. If not, explain why they should not be inline.

 - As you like.

###Exercise 6.46

>Would it be possible to define isShorter as a constexpr? If so, do so. If not, explain why not.

 - No. Because std::string::size() is not a constexpr function and s1.size() == s2.size() is not a constant expression.

##Exercises Section 6.5.3

###Exercise 6.47

>Revise the program you wrote in the exercises in §6.3.2(p.228) that used recursion to print the contents of a vector to conditionally print information about its execution. For example, you might print the size of the vector on each call. Compile and run the program with debugging turned on and again with it turned off.

```cpp
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

#define NDEBUG

void Print(vector<int> &vec, int index)
{
#ifdef NDEBUG
	cout << "vector size: " << vec.size() << '\n';
#endif

	if(index == 0)
	{
		cout << vec[0] << ' ';
		return;
	}
	Print(vec, index - 1);
	cout << vec[index] << ' ';
}

int main()
{
	vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	Print(vec, vec.size() - 1);
}
/*
Output:
vector size: 10
vector size: 10
vector size: 10
vector size: 10
vector size: 10
vector size: 10
vector size: 10
vector size: 10
vector size: 10
vector size: 10
1 2 3 4 5 6 7 8 9 10
*/
```

###Exercise 6.48

>Explain what this loop does and whether it is a good use of assert:
```cpp
string s;
while(cin >> s && s != sought) { } // empty body
assert(cin);
```

 - This loop let user input a word all the way until the word is sought.
 - It isn't a good use of assert. The assert macro is often used to check for conditions that “cannot happen”. But the assert would always happen when users input EOF directly. Using `assert(!cin || s == sought)` is more better.

##Exercises Section 6.6

###Exercise 6.49

>What is a candidate function? What is a viable function?

 - Candidate functions have the same name as the called function and their declaration are visible at the point of the call.
 - Viable functions are subset of candidate functions. Viable function must have the same number of parameters as there are arguments in the call, and the type of each argument must match(or be convertible to) the type of its corresponding parameter.

###Exercise 6.50

>Given the declarations for f from page 242, list the viable functions, if any for each of the following calls. Indicate which function is the best match, or if the call is illegal whether there is no match or why the call is ambiguous.

```cpp
void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);
(a) f(2.56, 42)
(b) f(42)
(c) f(42, 0)
(d) f(2.56, 3.14)
```

 - Illegal.
 - void f(int);
 - void f(int, int);
 - void f(double, double = 3.14);

###Exercise 6.51

>Write all four versions of f. Each function should print a distinguishing message. Check your answers for the previous exercise. If your answers were incorrect, study this section until you understand why your answers were wrong.

```cpp
#include <iostream>

using std::cout;
using std::endl;

void f()
{
	cout << "f()" << endl;
}

void f(int)
{
	cout << "f(int)" << endl;
}

void f(int, int)
{
	cout << "f(int, int)" << endl;
}

void f(double, double = 3.14)
{
	cout << "f(double, double = 3.14)" << endl;
}

int main()
{
	f(2.56, 42); // error: call of overloaded ‘f(double, int)’ is ambiguous
	f(42);
	f(42, 0);
	f(2.56, 3.14);

	return 0;
}
```

##Exercises Section 6.6.1

###Exercise 6.52

>Given the following declarations,
```cpp
void manipulate(int, int);
double num;
```
what is the rank(§ 6.6.1, p. 245) of each conversion in the following calls?
(a) manipulate('a', 'z');
(b) manipulate(55.4, num);

 - 3. Match through a promotion.
 - 4. Match through an arithmetic conversion.

###Exercise 6.53

>Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.
```cpp
(a)
int calc(int&, int&);
int calc(const int&, const int&);
(b)
int calc(char*, char*);
int calc(const char*, const char*);
(c)
int calc(char*, char*);
int calc(char* const, char* const);
```

 - Legal.
 - Legal.
 - Illegal. Top-level const omit.

##Exercises Section 6.7

###Exercise 6.54

>Write a declaration for a function that takes two int parameters and returns an int, and declare a vector whose elements have this function pointer type.

```cpp
int func(int, int);

using pFunc1 = decltype(func) *;
typedef decltype(func) *pFunc2;
using pFunc3 = int (*)(int a, int b);
using pFunc4 = int(int a, int b);
typedef int(*pFunc5)(int a, int b);
using pFunc6 = decltype(func);

vector<int(*)(int, int)> vec;
std::vector<pFunc1> vec1;
std::vector<pFunc2> vec2;
std::vector<pFunc3> vec3;
std::vector<pFunc4*> vec4;
std::vector<pFunc5> vec5;
std::vector<pFunc6*> vec6;
```

###Exercise 6.55

>Write four functions that add, subtract, multiply, and divide two int values. Store pointers to these values in your vector from the previous exercise.

```cpp
int Add(int a, int b)
{
	return a + b;
}
int Subtract(int a, int b)
{
	return a - b;
}
int Multiply(int a, int b)
{
	return a * b;
}
int Divide(int a, int b)
{
	return b != 0 ? a / b : 0;
}
```

###Exercise 6.56

>Call each element in the vector and print their result.

```cpp
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;

inline int f(const int, const int);
typedef decltype(f) fp; // fp is just a function type not a function pointer

inline int NumAdd(const int n1, const int n2)
{
	return n1 + n2;
}

inline int NumSub(const int n1, const int n2)
{
	return n1 - n2;
}

inline int NumMul(const int n1, const int n2)
{
	return n1 * n2;
}

inline int NumDiv(const int n1, const int n2)
{
	return n1 / n2;
}

int main()
{
	vector<fp*> v {NumAdd, NumSub, NumMul, NumDiv};
	for(auto it = v.cbegin(); it != v.cend(); ++it)
	{
		cout << (*it)(2, 2) << std::endl;
	}

	return 0;
}
```

