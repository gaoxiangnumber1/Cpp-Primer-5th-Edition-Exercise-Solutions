#CH04

##Exercises Section 4.1.2

###Exercise 4.1

>What is the value returned by 5 + 10 * 20/2?

 - 5 + 10 * 10 = 5 + 100 = 105

###Exercise 4.2

>Using Table 4.12 (p. 166), parenthesize the following expressions to indicate the order in which the operands are grouped:
(a) * vec.begin()
(b) * vec.begin() + 1

 - *(vec.begin())
 - (*(vec.begin())) + 1

##Exercises Section 4.1.3

###Exercise 4.3

>Order of evaluation for most of the binary operators is left undefined to give the compiler opportunities for optimization. This strategy presents a trade-off between efficient code generation and potential pitfalls in the use of the language by the programmer. Do you consider that an acceptable trade-off? Why or why not?

 - Yes. Result oriented.

##Exercises Section 4.2

###Exercise 4.4

>Parenthesize the following expression to show how it is evaluated. Test your answer by compiling the expression (without parentheses) and printing its result.
`12 / 3 * 4 + 5 * 15 + 24 % 4 / 2`

 - (((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2)) = 16 + 75 + 0 = 91

###Exercise 4.5

>Determine the result of the following expressions.
(a) -30 * 3 + 21 / 5
(b) -30 + 3 * 21 / 5
(c) 30 / 3 * 21 % 5
(d) -30 / 3 * 21 % 4

 - -90 + 4 = -86
 - -30 + 12 = -18
 - 10 * 21 % 5 = 210 % 5 = 0
 - -10 * 21 % 4 = -210 % 4 = -2

###Exercise 4.6

>Write an expression to determine whether an int value is even or odd.

```cpp
int num = value;
cout << ((num % 2) ? “Odd\n” : “Even\n”);
```

###Exercise 4.7

>What does overflow mean? Show three expressions that will overflow.

 - Exceed the scope.
```cpp
char ch = 10000;
short num1 = 10000000;
int num2 = 1000000000000000000000000;
```

##Exercises Section 4.3

###Exercise 4.8

>Explain when operands are evaluated in the logical AND, logical OR, and equality operators.

 - The right side of an && is evaluated if and only if the left side is true.
 - The right side of an || is evaluated if and only if the left side is false.
 - equality operators: undefined.

###Exercise 4.9

>Explain the behavior of the condition in the following if:
```cpp
const char *cp = "Hello World";
if (cp && *cp)
```

 - Because cp is not NULL pointer, so left side is true; and *cp = ‘H’, not ‘\0’, is also true. So this expression is true.

###Exercise 4.10

>Write the condition for a while loop that would read ints from the standard input and stop when the value read is equal to 42.

```
int num = 0;
while(cin >> num && num != 42)
{}
```

###Exercise 4.11

>Write an expression that tests four values, a, b, c, and d, and ensures that a is greater than b, which is greater than c, which is greater than d.

`if(a > b && b > c && c > d)`

###Exercise 4.12

>Assuming i, j, and k are all ints, explain what i != j < k means.

 - i != (j < k), that is, i != 0/1

##Exercises Section 4.4

###Exercise 4.13

>What are the values of i and d after each assignment?
```cpp
int i;
double d;
(a) d = i = 3.5;
(b) i = d = 3.5;
```

 - i = 3, d= 3.0
 - d = 3.5, i = 3

###Exercise 4.14

>Explain what happens in each of the if tests:
```cpp
if (42 = i) // ...
if (i = 42) // ...
```

 - error: lvalue required as left operand of assignment
 - make i equal to 42 and return 42 as condition, so i true.

###Exercise 4.15

>The following assignment is illegal. Why? How would you correct it?
```cpp
double dval;
int ival;
int *pi;
dval = ival = pi = 0;
```

 - error: invalid conversion from ‘int*’ to ‘int’

###Exercise 4.16

>Although the following are legal, they probably do not behave as the programmer expects. Why? Rewrite the expressions as you think they should be.
(a) if (p = getPtr() != 0)
(b) if (i = 1024)

 - if ((p = getPtr()) != 0)
 - if(i == 1024)

##Exercises Section 4.5

###Exercise 4.17

>Explain the difference between prefix and postfix increment.

 - Prefix: increments its operand and yields the changed object as its result.
 - Postfix: increment the operand but yield a copy of the original, unchanged value as its result.

###Exercise 4.18

>What would happen if the while loop on page 148 that prints the elements from a vector used the prefix increment operator?

 - It will print from the second element and dereference v.end() at last.

###Exercise 4.19

>Given that ptr points to an int, that vec is a vector<int>, and that ival is an int, explain the behavior of each of these expressions. Which, if any, are likely to be incorrect? Why? How might each be corrected?
(a) ptr != 0 && *ptr++
(b) ival++ && ival
(c) vec[ival++] <= vec[ival]

 - Check ptr is not a nullptr and check the pointer value.
 - Check ival and ival+1 whether equal zero.
 - Incorrect. It is an **undefined behavior.**

Correct: vec[ival] <= vec[ival + 1]

##Exercises Section 4.6

###Exercise 4.20

>Assuming that iter is a vector<string>::iterator, indicate which, if any, of the following expressions are legal. Explain the behavior of the legal expressions and why those that aren’t legal are in error.
(a) *iter++;
(b) (*iter)++;
(c) *iter.empty()
(d) iter->empty();
(e) ++*iter;
(f) iter++->empty();

 - Return *iter, then ++iter. 
 - Illegal, *iter is a string, cannot increment value. 
 - Illegal, iter should use '->' to indicate whether empty. 
 - Indicate the iter' value whether empty. 
 - Illegal, string have not increment. 
 - Return iter->empty(), then ++iter.

##Exercises Section 4.7

###Exercise 4.21

>Write a program to use a conditional operator to find the elements in a vector<int> that have odd value and double the value of each such element.

```cpp
int length = vec.size();
for(int index = 0; index < length; ++index)
{
	vec[index] = ((vec[index] % 2 != 0) ? vec[index] * 2 : vec[index]);
}
```

###Exercise 4.22

>Extend the program that assigned high pass, pass, and fail grades to also assign low pass for grades between 60 and 75 inclusive. Write two versions: One version that uses only conditional operators; the other should use one or more if statements. Which version do you think is easier to understand and why?

```cpp
#include <iostream>

using std::cout;
using std::cin;

int main()
{
	int grade;
	while(cin >> grade)
	{
		cout << ((grade > 90) ? "high pass" :
		         ((grade < 60) ? "fail" :
		          ((grade > 75) ? "pass" : "low pass")));
		cout << '\t';
		if(grade > 90)
		{
			cout << "high pass";
		}
		else if(grade < 60)
		{
			cout << "fail";
		}
		else if(grade > 75)
		{
			cout << "pass";
		}
		else
		{
			cout << "low pass";
		}
		cout << '\n';
	}

	return 0;
}
```

###Exercise 4.23

>The following expression fails to compile due to operator precedence. Using Table 4.12 (p. 166), explain why it fails. How would you fix it?

```cpp
string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s";
```
 - It equivalent to:
`string pl = (((s + s[s.size() - 1]) == 's') ? "" : "s");
// error: no match for ‘operator==’ (operand types are ‘std::basic_string<char>’ and ‘char’)
 - FIX:
`string pl = s + ((s[s.size() - 1] == 's') ? "" : "s");`

###Exercise 4.24

>Our program that distinguished between high pass, pass, and fail depended on the fact that the conditional operator is right associative. Describe how that operator would be evaluated if the operator were left associative.
final_grade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";

```cpp
// Right associative:
cout << ((grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass");

// Left associative.
// error: operands to ?: have different types ‘const char*’ and ‘bool’
cout << (((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass");
```

##Exercises Section 4.8

###Exercise 4.25

>What is the value of ~'q' << 6 on a machine with 32-bit ints and 8 bit chars, that uses Latin-1 character set in which 'q' has the bit pattern 01110001?

 - -7296.
```
[‘q’]2		=	0000 0000	0000 0000	0000 0000	0111 0001
[~‘q’]2		=	1111 1111	1111 1111	1111 1111	1000 1110
[~‘q’ <<6]2	=	1111 1111	1111 1111	1110 0011	1000 0000
```

###Exercise 4.26

>In our grading example in this section, what would happen if we used unsigned int as the type for quiz1?

 - The C++ standard does not specify the size of integral types in bytes, but it specifies minimum ranges they must be able to hold. Minimum mange of unsigned int is 0 to 65535. Thus if unsigned int adopted, the result is undefined.

###Exercise 4.27

>What is the result of each of these expressions?
`unsigned long ul1 = 3, ul2 = 7;`
(a) ul1 & ul2
(b) ul1 | ul2
(c) ul1 && ul2
(d) ul1 || ul2

 - 3
 - 7
 - 1(true)
 - 1(true)

##Exercises Section 4.9

###Exercise 4.28

>Write a program to print the size of each of the built-in types.

```cpp
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	// void type
	cout << "void: nullptr_t\t" << sizeof(std::nullptr_t) << " bytes" << endl << endl;

	// boolean type
	cout << "bool:\t\t" << sizeof(bool) << " bytes" << endl << endl;

	// charactor type
	cout << "char:\t\t" << sizeof(char) << " bytes" << endl;
	cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes" << endl;
	cout << "char16_t:\t" << sizeof(char16_t) << " bytes" << endl;
	cout << "char32_t:\t" << sizeof(char32_t) << " bytes" << endl << endl;

	// integers type
	cout << "short:\t\t" << sizeof(short) << " bytes" << endl;
	cout << "int:\t\t" << sizeof(int) << " bytes" << endl;
	cout << "long:\t\t" << sizeof(long) << " bytes" << endl;
	cout << "long long:\t" << sizeof(long long) << " bytes" << endl << endl;

	// floating point type
	cout << "float:\t\t" << sizeof(float) << " bytes" << endl;
	cout << "double:\t\t" << sizeof(double) << " bytes" << endl;
	cout << "long double:\t" << sizeof(long double) << " bytes" << endl << endl;

	// Fixed width integers
	cout << "int8_t:\t\t" << sizeof(int8_t) << " bytes" << endl;
	cout << "uint8_t:\t" << sizeof(uint8_t) << " bytes" << endl;
	cout << "int16_t:\t" << sizeof(int16_t) << " bytes" << endl;
	cout << "uint16_t:\t" << sizeof(uint16_t) << " bytes" << endl;
	cout << "int32_t:\t" << sizeof(int32_t) << " bytes" << endl;
	cout << "uint32_t:\t" << sizeof(uint32_t) << " bytes" << endl;
	cout << "int64_t:\t" << sizeof(int64_t) << " bytes" << endl;
	cout << "uint64_t:\t" << sizeof(uint64_t) << " bytes" << endl;

	return 0;
}
/*
void: nullptr_t	8 bytes

bool:		1 bytes

char:		1 bytes
wchar_t:	4 bytes
char16_t:	2 bytes
char32_t:	4 bytes

short:		2 bytes
int:		4 bytes
long:		8 bytes
long long:	8 bytes

float:		4 bytes
double:		8 bytes
long double:	16 bytes

int8_t:		1 bytes
uint8_t:	1 bytes
int16_t:	2 bytes
uint16_t:	2 bytes
int32_t:	4 bytes
uint32_t:	4 bytes
int64_t:	8 bytes
uint64_t:	8 bytes
*/
```

###Exercise 4.29

>Predict the output of the following code and explain your reasoning. Now run the program. Is the output what you expected? If not, figure out why.

```cpp
int x[10];
int *p = x;
cout << sizeof(x)/sizeof(*x) << endl;
cout << sizeof(p)/sizeof(*p) << endl;
```
 - 10
2

###Exercise 4.30

>Using Table 4.12(p. 166), parenthesize the following expressions to match the default evaluation:
(a) sizeof x + y
(b) sizeof p->mem[i]
(c) sizeof a < b
(d) sizeof f()

 - (sizeof x)+y
 - sizeof(p‐>mem[i]) 
 - sizeof(a) < b 
 - If f() returns void, this statement is undefined, otherwise it returns the size of return type.

##Exercises Section 4.10

###Exercise 4.31

>The program in this section used the prefix increment and decrement operators. Explain why we used prefix and not postfix. What changes would have to be made to use the postfix versions? Rewrite the program using postfix operators.

```cpp
for(vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
	ivec[ix] = cnt;
```

###Exercise 4.32

>Explain the following loop.
```cpp
constexpr int size = 5;
int ia[size] = {1,2,3,4,5};
for (int *ptr = ia, ix = 0; ix != size && ptr != ia+size; ++ix, ++ptr){ /* ... */ }
```

 - ptr and ix have the same function. The former use a pointer, and the latter use the index of array. we use the loop to through the array.﴾just choose one from ptr and ix)

###Exercise 4.33

>Using Table 4.12(p. 166) explain what the following expression does:
`some_Value ? ++x, ++y : --x, --y`

```cpp
#include <iostream>

using std::cout;

int main()
{
	int x = 1, y = 9;
	cout << (true ? ++x, ++y : --x, --y) << '\n';
	cout << x << '\t' << y << '\n';
	cout << (false ? ++x, ++y : --x, --y) << '\n';
	cout << x << '\t' << y << '\n';

	return 0;
}
/*
9
2	9
8
1	8
*/
```
 - Equivalent to: `(some_Value ? ++x, ++y :--x), --y`
If true, return y; else, return --y.

##Exercises Section 4.11.1

###Exercise 4.34

>Given the variable definitions in this section, explain what conversions take place in the following expressions:
(a) if (fval)
(b) dval = fval + ival;
(c) dval + ival * cval;
Remember that you may need to consider the associativity of the operators.

 - float to bool: if fval = 0, then false; otherwise true.
 - ival from int to float, then result convert from float to double.
 - cval convert from char to int, then result convert from int to double.

###Exercise 4.35

>Given the following definitions,
```cpp
char cval;
int ival;
unsigned int ui;
float fval;
double dval;
```
>identify the implicit type conversions, if any, taking place:
(a) cval = 'a' + 3;
(b) fval = ui - ival * 1.0;
(c) dval = ui * fval;
(d) cval = ival + fval + dval;

 - ‘a’: char -> int; result: int -> char
 - ival: int -> double; ui: unsigned int -> double; result: double -> float
 - ui: unsigned int -> float; result: float -> double
 - ival: int -> float; (ival + fval): float -> double; result: double -> char

##Exercises Section 4.11.3

###Exercise 4.36

>Assuming i is an int and d is a double, write the expression i *= d so that it does integral, rather than floating-point, multiplication.

```cpp
i *= static_cast<int>(d);
```

###Exercise 4.37

>Rewrite each of the following old-style casts to use a named cast:
```cpp
int i;
double d;
const string *ps;
char *pc;
void *pv;
(a) pv = (void*)ps;
(b) i = int(*pc);
(c) pv = &d;
(d) pc = (char*) pv;
```

```cpp
pv = static_cast<void*>(const_cast<string*>(ps)); 
i = static_cast<int>(*pc); 
pv = static_cast<void*>(&d); 
pc = reinterpret_cast<char*>(pv);
```

###Exercise 4.38

>Explain the following expression:
`double slope = static_cast<double>(j/i);`

 - j/i is an int﴾by truncation﴿, then converted to double and assigned to slope.


