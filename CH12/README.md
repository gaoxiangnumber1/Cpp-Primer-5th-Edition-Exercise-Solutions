# CH12

##Exercises Section 12.1.1

###Exercise 12.1

>How many elements do b1 and b2 have at the end of this code?

```cpp
StrBlob b1;
{
	StrBlob b2 = {"a", "an", "the"};
	b1 = b2;
	b2.push_back("about");
}
```
 - b1: 4; b2: 0
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class StrBlob
{
public:
	using size_type = vector<string>::size_type;

	StrBlob(string id) : id_(id), data(make_shared<vector<string>>())
	{
		cout << "Constructor:\tid = " << id_ << '\n';
	}
	StrBlob(string id, initializer_list<string> il) :
		id_(id), data(make_shared<vector<string>>(il))
	{
		cout << "Constructor:\tid = " << id_ << '\n';
	}
	~StrBlob()
	{
		cout << "Destructor:\tid = " << id_ << '\n';
	}
	void push_back(const string &t)
	{
		data->push_back(t);
	}
	void Print()
	{
		int length = data->size();
		for(int index = 0; index < length; ++index)
		{
			cout <<(*data)[index] << ' ';
		}
		cout << '\n';
	}

private:
	string id_;
	shared_ptr<vector<string>> data;
};

int main()
{
	cout << "Begin main\n";
	StrBlob b1("b1");
	{
		StrBlob b2("b2", {"a", "an", "the"});
		b1 = b2;
		b2.push_back("about");
	}
	b1.Print();// a an the about
	//b2.Print();// error: ‘b2’ was not declared in this scope
	cout << "End main\n";

	return 0;
}
/*
Output:
Begin main
Constructor:	id = b1
Constructor:	id = b2
Destructor:	id = b2
a an the about
End main
Destructor:	id = b2
*/
```

###Exercise 12.2

>Write your own version of the StrBlob class including the const versions of front and back.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <exception>

using namespace std;

class StrBlob
{
public:
	using size_type = vector<string>::size_type;

	StrBlob(string id) : id_(id), data(make_shared<vector<string>>())
	{
		cout << "Constructor:\tid = " << id_ << '\n';
	}
	StrBlob(string id, initializer_list<string> il) :
		id_(id), data(make_shared<vector<string>>(il))
	{
		cout << "Constructor:\tid = " << id_ << '\n';
	}
	~StrBlob()
	{
		cout << "Destructor:\tid = " << id_ << '\n';
	}
	string &front()
	{
		check(0, "front on empty StrBlob");
		cout << "string &front()\n";
		return data->front();
	}
	string &back()
	{
		check(0, "back on empty StrBlob");
		cout << "string &back()\n";
		return data->back();
	}
	const string &front() const
	{
		check(0, "front on empty StrBlob");
		cout << "const string &front() const\n";
		return data->front();
	}
	const string &back() const
	{
		check(0, "back on empty StrBlob");
		cout << "const string &back() const\n";
		return data->back();
	}

private:
	string id_;
	shared_ptr<vector<string>> data;
	// throws msg if data[i] isn't valid
	void check(size_type i, const string &msg) const
	{
		if(i >= data->size())
		{
			throw out_of_range(msg);
		}
	}
};

int main()
{
	cout << "Begin main\n";
	StrBlob obj1("obj1", {"gao", "xiang", "number1"});
	cout << obj1.front() << '\t' << obj1.back() << '\n';
	obj1.front() = "Gao Xiang";
	obj1.back() = "Number1";
	cout << obj1.front() << '\t' << obj1.back() << '\n';

	StrBlob obj2("obj2", {"hello", "gaoxiang", "number1"});
	cout << obj2.front() << '\t' << obj2.back() << '\n';
	cout << "End main\n";

	return 0;
}
/*
Output:
Begin main
Constructor:	id = obj1
string &back()
string &front()
gao	number1
string &front()
string &back()
string &back()
string &front()
Gao Xiang	Number1
Constructor:	id = obj2
string &back()
string &front()
hello	number1
End main
Destructor:	id = obj2
Destructor:	id = obj1
*/
```

###Exercise 12.3

>Does this class need const versions of push_back and pop_back? If so, add them. If not, why aren’t they needed?

 - It is legal but there seem no logical reason. The compiler doesn't complain because this doesn't modify data(which is a pointer) but rather the thing data points to.

###Exercise 12.4

>In our check function we didn’t check whether i was greater than zero. Why is it okay to omit that check?

 - Because the type of i is `std::vector<std::string>::size_type` which is an unsigned. When an argument is negative, it is converted to a positive number.

###Exercise 12.5

>We did not make the constructor that takes an initializer_list explicit(§7.5.4, p. 296). Discuss the pros and cons of this design choice.

 - Pros: The compiler will not use this constructor in an automatic conversion and we can realize clearly which class we have used.
 - Cons: We must uses the constructor to construct a temporary StrBlob object. We cannot use the copy form of initialization.

##Exercises Section 12.1.2

###Exercise 12.6

>Write a function that returns a dynamically allocated vector of ints. Pass that vector to another function that reads the standard input to give values to the elements. Pass the vector to another function to print the values that were read. Remember to delete the vector at the appropriate time.

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> *Allocate()
{
	return new vector<int>();
}

void Input(vector<int> *vec)
{
	int data;
	while(cin >> data)
	{
		vec->push_back(data);
	}
}

void Output(vector<int> *vec)
{
	int length = vec->size();
	for(int index = 0; index < length; ++index)
	{
		cout <<(*vec)[index] << ' ';
	}
	cout << '\n';
}

int main()
{
	vector<int> *vec = Allocate();
	Input(vec);
	Output(vec);
	delete vec;

	return 0;
}
```

###Exercise 12.7

>Redo the previous exercise, this time using shared_ptr.

```cpp
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> Allocate()
{
	return make_shared<vector<int>>();
}

void Input(shared_ptr<vector<int>> vec)
{
	int data;
	while(cin >> data)
	{
		vec->push_back(data);
	}
}

void Output(shared_ptr<vector<int>> vec)
{
	int length = vec->size();
	for(int index = 0; index < length; ++index)
	{
		cout <<(*vec)[index] << ' ';
	}
	cout << '\n';
}

int main()
{
	shared_ptr<vector<int>> vec = Allocate();
	Input(vec);
	Output(vec);

	return 0;
}
```

###Exercise 12.8

>Explain what if anything is wrong with the following function.

```cpp
bool b()
{
	int* p = new int;
	// ...
	return p;
}
```
 - The pointer will be converted to a bool; memory leak.

###Exercise 12.9

>Explain what happens in the following code:
```cpp
int *q = new int(42), *r = new int(100);
r = q;
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;
```

 - For q and r: Memory leakage happens. Because after r = q was executed, no pointer points to the int r had pointed to. It implies that no chance to free the memory for it.
 - For q2 and r2: It's safe. Because after 'r2 = q2', the reference count belongs to r2 reduce to 0 and the reference count belongs to q2 increase to 2, then the memory allocated by r2 will be released automatically.

##Exercises Section 12.1.3

###Exercise 12.10

>Explain whether the following call to the process function defined on page 464 is correct. If not, how would you correct the call?

```cpp
shared_ptr<int> p(new int(42));
process(shared_ptr<int>(p));
```
```cpp
#include <iostream>
#include <memory>

using namespace std;

void process(shared_ptr<int> ptr)
{
	cout << "ptr =\t" << ptr << ": reference_count = " << ptr.use_count() << '\n';
}

int main()
{
	shared_ptr<int> p(new int(1));
	process(shared_ptr<int>(p)); // ptr = 0xc7d010: reference_count = 2

	return 0;
}
```

###Exercise 12.11

>What would happen if we called process as follows?
`process(shared_ptr<int>(p.get()));`

 - When the call process ends, p is a dangling pointer. When p is destroyed, the pointer to that memory will be deleted a second time.

###Exercise 12.12

>Using the declarations of p and sp explain each of the following calls to process. If the call is legal, explain what it does. If the call is illegal, explain why:
```cpp
auto p = new int();
auto sp = make_shared<int>();
(a) process(sp);
(b) process(new int());
(c) process(p);
(d) process(shared_ptr<int>(p));
```

 - Legal.
 - Illegal: can’t implicitly convert `int*` to shared_ptr.
 - Illegal, same as above.
 - Legal: create a temporary object.

###Exercise 12.13

>What happens if we execute the following code?

```cpp
auto sp = make_shared<int>();
auto p = sp.get();
delete p;
```
```cpp

*** Error in `./a.out': free(): invalid pointer: 0x0000000001670028 ***

Aborted
```

##Exercises Section 12.1.4

###Exercise 12.14

>Write your own version of a function that uses a shared_ptr to manage a connection.

```cpp
#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct connection
{
	string ip;
	int port;
	connection(string ip_, int port_) : ip(ip_), port(port_) {}
};

struct destination
{
	string ip;
	int port;
	destination(string ip_, int port_) : ip(ip_), port(port_) {}
};

connection connect(destination* pDest)
{
	shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
	cout << "creating connection(" << pConn.use_count() << ")\n";
	return *pConn;
}

void disconnect(connection pConn)
{
	cout << "connection close(" << pConn.ip << ":" << pConn.port << ")\n";
}

void end_connection(connection* pConn)
{
	disconnect(*pConn);
}

void f(destination& d)
{
	connection conn = connect(&d);
	shared_ptr<connection> p(&conn, end_connection);
	cout << "connecting now(" << p.use_count() << ")\n";
}

int main()
{
	destination dest("127.0.0.1", 7188);
	f(dest);

	return 0;
}
/*
Output:
creating connection(1)
connecting now(1)
connection close(127.0.0.1:7188)
*/
```

###Exercise 12.15

>Rewrite the first ###Exercise to use a lambda(§10.3.2, p. 388) in place of the end_connection function.

```cpp
#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct connection
{
	string ip;
	int port;
	connection(string ip_, int port_):ip(ip_), port(port_) { }
};
struct destination
{
	string ip;
	int port;
	destination(string ip_, int port_):ip(ip_), port(port_) { }
};

connection connect(destination* pDest)
{
	shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
	cout << "creating connection(" << pConn.use_count() << ")\n";
	return *pConn;
}

void disconnect(connection pConn)
{
	cout << "connection close(" << pConn.ip << ":" << pConn.port << ")\n";
}

void f(destination &d)
{
	connection conn = connect(&d);
	shared_ptr<connection> p(&conn, [](connection *p)
	{
		disconnect(*p);
	});
	cout << "connecting now(" << p.use_count() << ")\n";
}

int main()
{
	destination dest("127.0.0.1", 7188);
	f(dest);
}
/*
Output:
creating connection(1)
connecting now(1)
connection close(127.0.0.1:7188)
*/
```

##Exercises Section 12.1.5

###Exercise 12.16

>Compilers don’t always give easy-to-understand error messages if we attempt to copy or assign a unique_ptr. Write a program that contains these errors to see how your compiler diagnoses them.

 - error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = double; _Dp = std::default_delete<double>]’

###Exercise 12.17

>Which of the following unique_ptr declarations are illegal or likely to result in subsequent program error? Explain what the problem is with each one.

```cpp
int ix = 1024, *pi = &ix, *pi2 = new int(2048);
typedef unique_ptr<int> Int;
(a) Int p0(ix);
(b) Int p1(pi);
(c) Int p2(pi2);
(d) Int p3(&ix);
(e) Int p4(new int(2048));
(f) Int p5(p2.get());
```
 - `error: invalid conversion from ‘int’ to ‘std::unique_ptr<int>::pointer {aka int*}’`
 - `*** Error in `cpp': free(): invalid pointer: 0x00007ffec78f8e9c *** Aborted`
The code can compile, but will cause error at run time. The reason is that when the unique_ptr p1 is out of scope, delete will be called to free the object. But the object is not allocate using new. Thus, an error would be thrown by operating system.
 - This code can compile, but cause a dangling pointer at run time. The reason is that the unique_ptr will free the object the raw pointer is pointing to.
 - Same as p1.
 - ok
 - `*** Error in `cpp': double free or corruption: 0x00000000020ec010 *** Aborted`
Two unique_ptrs are pointing to the same object, when both are out of scope, operating system will throw double free or corruption.

###Exercise 12.18

>Why doesn’t shared_ptr have a release member?

 - Because other shared_ptr that points the same object can still delete this object.Thus, it's meaningless to provide this member
http://stackoverflow.com/questions/1525764/how-to-release-pointer-from-boostshared-ptr

##Exercises Section 12.1.6

###Exercise 12.19

>Define your own version of StrBlobPtr and update your StrBlob class with the appropriate friend declaration and begin and end members.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class StrBlobPtr;
class StrBlob
{
	friend class StrBlobPtr;

public:
	StrBlobPtr begin();
	StrBlobPtr end();

	typedef	vector<string>::size_type	size_type;

	StrBlob(string id) : id_(id), data(make_shared<vector<string>>())
	{
		cout << "Constructor:\tid = " << id_ << '\n';
	}
	StrBlob(string id, initializer_list<string> il) :
		id_(id), data(make_shared<vector<string>>(il))
	{
		cout << "Constructor:\tid = " << id_ << '\n';
	}
	~StrBlob()
	{
		cout << "Destructor:\tid = " << id_ << '\n';
	}
	size_type size() const
	{
		return data->size();
	}
	bool empty() const
	{
		return data->empty();
	}
	void push_back(const string &t)
	{
		data->push_back(t);
	}
	void pop_back()
	{
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}
	string &front()
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}
	string &back()
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}
	const string &front() const
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}
	const string &back() const
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}
	void Print()
	{
		int length = data->size();
		for(int index = 0; index < length; ++index)
		{
			cout <<(*data)[index] << ' ';
		}
		cout << '\n';
	}

//private:
	string id_;
	shared_ptr<vector<string>> data;
	// throws msg if data[i] isn't valid
	void check(size_type i, const string &msg) const
	{
		if(i >= data->size())
		{
			throw out_of_range(msg);
		}
	}
};

// StrBlobPtr throws an exception on attempts to access a nonexistent element
class StrBlobPtr
{
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	string &deref() const
	{
		shared_ptr<vector<string>> p = check(curr, "dereference past end");
		return(*p)[curr];
	}
	// prefix: return a reference to the incremented object
	StrBlobPtr &incr()
	{
		check(curr, "increment past end of StrBlobPtr");
		++curr;
		return *this;
	}

private:
	// check returns a shared_ptr to the vector if the check succeeds
	shared_ptr<vector<string>> check(size_t i, const string &msg) const
	{
		shared_ptr<vector<string>> ret = wptr.lock();
		if(!ret)
		{
			throw runtime_error("unbound StrBlobPtr");
		}
		if(i >= ret->size())
		{
			throw out_of_range(msg);
		}
		return ret;
	}
	// store a weak_ptr, which means the underlying vector might be destroyed
	weak_ptr<vector<string>> wptr;
	size_t curr; // current position within the array
};

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	StrBlobPtr ret = StrBlobPtr(*this, data->size());
	return ret;
}

int main()
{
	StrBlob obj1("obj1");
	StrBlobPtr obj2(obj1);

	return 0;
}
```

###Exercise 12.20

>Write a program that reads an input file a line at a time into a StrBlob and uses a StrBlobPtr to print each element in that StrBlob.

```cpp
int main()
{
	ifstream ifs("data.txt");
	StrBlob obj("obj");
	for(string str; getline(ifs, str); )
	{
		obj.push_back(str);
	}
	for(StrBlobPtr pbeg(obj.begin()), pend(obj.end()); pbeg != pend; pbeg.incr())
	{
		cout << pbeg.deref() << endl;
	}
}
/*
Output:
Constructor:	id = obj
0-201-78345-X 3 20
0-201-78345-X 2 25
0-201-78346-X 1 100
0-201-78346-X 2 99.9
0-201-78346-X 6 89.9
Destructor:	id = obj
*/
```

###Exercise 12.21

>We could have written StrBlobPtr ’s deref member as follows.

```cpp
std::string& deref() const
{
	return(*check(curr, "dereference past end"))[curr];
}
```

>Which version do you think is better and why?

 - The original one is better, because it's more readable.

###Exercise 12.22

>What changes would need to be made to StrBlobPtr to create a class that can be used with a const StrBlob? Define a class named ConstStrBlobPtr that can point to a const StrBlob.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class ConstStrBlobPtr;
class StrBlob
{
	friend class ConstStrBlobPtr;

public:
	ConstStrBlobPtr begin() const; // NOTE: ADD const
	ConstStrBlobPtr end() const; // NOTE: ADD const

};

class ConstStrBlobPtr
{
public:
	ConstStrBlobPtr() : curr(0) {}
	 // NOTE: ADD const
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	 // NOTE: ADD const
	const string &deref() const
	{
		shared_ptr<vector<string>> p = check(curr, "dereference past end");
		return(*p)[curr];
	}
};

ConstStrBlobPtr StrBlob::begin() const // NOTE: ADD const
{
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const // NOTE: ADD const
{
	ConstStrBlobPtr ret = ConstStrBlobPtr(*this, data->size());
	return ret;
}

int main()
{
	const StrBlob obj("obj");
	ConstStrBlobPtr obj2(obj);
}
```

##Exercises Section 12.2.1

###Exercise 12.23

>Write a program to concatenate two string literals, putting the result in a dynamically allocated array of char. Write a program to concatenate two library strings that have the same value as the literals used in the first program.

```cpp
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	// Dynamically allocated array of char
	char *result1 = new char[strlen("gaoxiang") + 1]();
	strcat(result1, "gao");
	strcat(result1, "xiang");
	cout << result1 << '\n';
	delete [] result1;

	// string
	string str1 = "gao", str2 = "xiang";
	string result2 = str1 + str2;
	cout << result2 << '\n';
}
```

###Exercise 12.24

>Write a program that reads a string from the standard input into a dynamically allocated character array. Describe how your program handles varying size inputs. Test your program by giving it a string of data that is longer than the array size you’ve allocated.

```cpp
#include <iostream>

using namespace std;

int main()
{
	int length = 0;
	while(true)
	{
		cout << "Input your string length: ";
		cin >> length;
		char *str = new char[length + 1]();
		cout << "Input string: ";
		cin >> str;
		cout << str << '\n';
		delete[] str;
	}
}
```

###Exercise 12.25

>Given the following new expression, how would you delete pa?
`int *pa = new int[10];`

 - `delete [] pa;`

##Exercises Section 12.2.2

###Exercise 12.26

>Rewrite the program on page 481 using an allocator.

```cpp
#include <iostream>
#include <string>

using namespace std;

void Fun(int n)
{
	allocator<string> alloc;
	auto const p = alloc.allocate(n);
	string s;
	auto q = p;
	while (cin >> s && q != p + n)
	{
		alloc.construct(q++, s);
	}

	while (q != p)
	{
		cout << *--q << " ";
		alloc.destroy(q);
	}
	alloc.deallocate(p, n);
}

int main()
{
	Fun(3);
}
```
