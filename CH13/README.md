# CH13

##Exercises Section 13.1.1

###Exercise 13.1

>What is a copy constructor? When is it used?

 - A constructor is the copy constructor if its first parameter is a reference to the class type(often a reference to const) and any additional parameters have default values.
 - Copy initialization happens:
1. When we define variables using =.
2. Pass an object as an argument to a parameter of nonreference type.
3. Return an object from a function that has a nonreference return type.
4. Brace initialize the elements in an array or the members of an aggregate class (§7.5.5).

###Exercise 13.2

>Explain why the following declaration is illegal:
```cpp
Sales_data::Sales_data(Sales_data rhs);
```

 - The first parameter is a reference to the class type.

###Exercise 13.3

>What happens when we copy a StrBlob? What about StrBlobPtrs?

```cpp
StrBlob(const StrBlob &obj) : id_(obj.id_), data(obj.data) {}
StrBlobPtr(const StrBlobPtr &obj) : wptr(obj.wptr), curr(obj.curr) {}
```

###Exercise 13.4

>Assuming Point is a class type with a public copy constructor, identify each use of the copy constructor in this program fragment:

```cpp
Point global;
Point foo_bar(Point arg)
{
	Point local = arg, *heap = new Point(global);
	*heap = local;
	Point pa[ 4 ] = { local, *heap };
	return *heap;
}
```

```cpp
#include <iostream>

using namespace std;

class Point
{
public:
	Point(string id) : id_(id)
	{
		cout << "Constructor: id = " << id_ << "\n";
	}
	Point(const Point &obj) : id_(obj.id_)
	{
		cout << "Copy constructor: id = " << id_ << "\n";
	}
	~Point()
	{
		cout << "Destructor: id = " << id_ << "\n";
	}

private:
	string id_;
};

Point global("global");
Point foo_bar(Point arg)
{
	cout << "Enter call, before `Point local = arg;`\n";
	Point local = arg;
	cout << "After `Point local = arg;`, before `Point *heap = new Point(global);`\n";
	Point *heap = new Point(global);
	cout << "After `Point *heap = new Point(global);`, before `*heap = local;`\n";
	*heap = local;
	cout << "After `*heap = local;`, before `Point pa[ 4 ] = { local, *heap };`\n";
	Point pa[ 4 ] = {local, *heap, string("default 1"), string("default 2")};
	cout << "After `Point pa[ 4 ] = { local, *heap };`, before `return *heap;`\n";
	return *heap;
}

int main()
{
	Point obj("obj");
	cout << "Before call\n";
	foo_bar(obj);
	cout << "After call\n";
}
/*
Output:
Constructor: id = global
Constructor: id = obj
Before call
Copy constructor: id = obj
Enter call, before `Point local = arg;`
Copy constructor: id = obj
After `Point local = arg;`, before `Point *heap = new Point(global);`
Copy constructor: id = global
After `Point *heap = new Point(global);`, before `*heap = local;`
After `*heap = local;`, before `Point pa[ 4 ] = { local, *heap };`
Copy constructor: id = obj
Copy constructor: id = obj
Constructor: id = default 1
Constructor: id = default 2
After `Point pa[ 4 ] = { local, *heap };`, before `return *heap;`
Copy constructor: id = obj
Destructor: id = default 2
Destructor: id = default 1
Destructor: id = obj
Destructor: id = obj
Destructor: id = obj
Destructor: id = obj
Destructor: id = obj
After call
Destructor: id = obj
Destructor: id = global
*/
```

###Exercise 13.5

>Given the following sketch of a class, write a copy constructor that copies all the members. Your constructor should dynamically allocate a new string(§12.1.2) and copy the object to which ps points, rather than copying ps itself.

```cpp
class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) {}
	
private:
	std::string *ps;
	int i;
};
```

```cpp
HasPtr(const HasPtr &obj) : ps(new std::string(*(obj.ps))), i(obj.i) {}
```

##Exercises Section 13.1.2

###Exercise 13.6

>What is a copy-assignment operator? When is this operator used? What does the synthesized copy-assignment operator do? When is it synthesized?

 - `Type &operator=(const Type &rhs);`
 - `Object obj2 = obj1;`
 - Assigns each nonstatic member of the right-hand object to the corresponding member of the left-hand object using the copy-assignment operator for the type of that member.
 - When we don’t define it ourself.

###Exercise 13.7

>What happens when we assign one StrBlob to another? What about StrBlobPtrs?

```cpp
StrBlob &operator=(const StrBlob &rhs)
{
	id_ = rhs.id_;
	data = rhs.data;
	return *this;
}
StrBlobPtr &operator=(const StrBlobPtr &rhs)
{
	wptr = rhs.wptr;
	curr = rhs.curr;
	return *this;
}
```

###Exercise 13.8

>Write the assignment operator for the HasPtr class from ###Exercise 13.5 in §13.1.1(p. 499). As with the copy constructor, your assignment operator should copy the object to which ps points.

```cpp
class HasPtr
{
public:
	HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
	HasPtr(const HasPtr &orig) : ps(new string(*(orig.ps))), i(orig.i) {}
	HasPtr &operator=(const HasPtr &rhs)
	{
		ps = new string(*(rhs.ps));
		i = rhs.i;
	}

private:
	string *ps;
	int i;
};
```

##Exercises Section 13.1.3

###Exercise 13.9

>What is a destructor? What does the synthesized destructor do? When is a destructor synthesized?

 - Destructors do whatever work is needed to free the resources used by an object and destroy the nonstatic data members of the object.
 - For some classes, the synthesized destructor is defined to disallow objects of the type from being destroyed(§13.1.6); otherwise, the synthesized destructor has an empty function body.
 - When we don’t define it ourself.

###Exercise 13.10

>What happens when a StrBlob object is destroyed? What about a StrBlobPtr?

 - When a StrBlob object destroyed, the use_count of the dynamic object will decrement. It will be freed if no shared_ptr to that dynamic object.
 - When a StrBlobPtr object is destroyed the object dynamically allocated will not be freed.

###Exercise 13.11

>Add a destructor to your HasPtr class from the previous exercises.

```cpp
class HasPtr
{
public:
	HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
	HasPtr(const HasPtr &orig) : ps(new string(*(orig.ps))), i(orig.i) {}
	HasPtr &operator=(const HasPtr &rhs)
	{
		ps = new string(*(rhs.ps));
		i = rhs.i;
	}
	~HasPtr()
	{
		delete ps;
	}

private:
	string *ps;
	int i;
};
```

###Exercise 13.12

>How many destructor calls occur in the following code fragment?

```cpp
bool fcn(const Sales_data *trans, Sales_data accum)
{
	Sales_data item1(*trans), item2(accum);
	return item1.isbn() != item2.isbn();
}
```
 - Three times: accum, item1 and item2.

###Exercise 13.13

>A good way to understand copy-control members and constructors is to define a simple class with these members in which each member prints its name:

```cpp
struct X
{
	X()
	{
		std::cout << "X()" << std::endl;
	}
	X(const X&)
	{
		std::cout << "X(const X&)" << std::endl;
	}
};
```

>Add the copy-assignment operator and destructor to X and write a program using X objects in various ways: Pass them as nonreference and reference parameters; dynamically allocate them; put them in containers; and so forth. Study the output until you are certain you understand when and why each copy-control member is used. As you read the output, remember that the compiler can omit calls to the copy constructor.
```cpp
#include <iostream>
#include <vector>

using namespace std;

struct X
{
	X(string id) : id_(id)
	{
		cout << "X(): id = " << id_ << "\n";
	}
	X(const X &orig) : id_(orig.id_)
	{
		cout << "X(const X&): id = " << id_ << "\n";
	}
	X &operator=(const X &)
	{
		cout << "X &operator=(const X &): id = " << id_ << "\n";
		return *this;
	}
	~X()
	{
		cout << "~X(): id = " << id_ << "\n";
	}
	string id_;
};

void Fun1(X obj)
{
	cout << "Fun1(X): id = " << obj.id_ << "\n";
}

void Fun2(X &obj)
{
	cout << "Fun2(X&): id = " << obj.id_ << "\n";
}

int main()
{
	X obj1("obj1");
	Fun1(obj1);
	Fun2(obj1);
	X *obj2 = new X("obj2");
	vector<X> vec(5, string("obj3"));
	delete obj2;
	cout << "EXIT\n";

	return 0;
}
/*
Output:
X(): id = obj1
X(const X&): id = obj1
Fun1(X): id = obj1
~X(): id = obj1
Fun2(X&): id = obj1
X(): id = obj2
X(): id = obj3
X(const X&): id = obj3
X(const X&): id = obj3
X(const X&): id = obj3
X(const X&): id = obj3
X(const X&): id = obj3
~X(): id = obj3
~X(): id = obj2
EXIT
~X(): id = obj3
~X(): id = obj3
~X(): id = obj3
~X(): id = obj3
~X(): id = obj3
~X(): id = obj1
*/
```

##Exercises Section 13.1.4

###Exercise 13.14

>Assume that `numbered` is a class with a default constructor that generates a unique serial number for each object, which is stored in a data member named my_serial_number. Assuming numbered uses the synthesized copy-control members and given the following function:

```cpp
void f(numbered s)
{
	cout << s.my_serial_number << endl;
}
```

>what output does the following code produce?

```cpp
numbered a, b = a, c = b;
f(a);
f(b);
f(c);
```
 - Three same numbers.

###Exercise 13.15

>Assume numbered has a copy constructor that generates a new serial number. Does that change the output of the calls in the previous exercise? If so, why? What output gets generated?

 - Three distinct numbers.

###Exercise 13.16

>What if the parameter in f were const numbered&? Does that change the output? If so, why? What output gets generated?

 - The output will change. Because no copy operation happens within function f, the three output are the same.

###Exercise 13.17

>Write versions of numbered and f corresponding to the previous three exercises and check whether you correctly predicted the output.

```cpp
#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;

class numbered1
{
	friend void f1(numbered1);

public:
	numbered1()
	{
		num = ++cnt;
		cout << "numbered1(): cnt = " << cnt << '\n';
	}

private:
	int num;
};

void f1(numbered1 s)
{
	cout << s.num << '\n';
}

class numbered2
{
	friend void f2(numbered2);
	friend void f3(const numbered2 &);

public:
	numbered2()
	{
		num = ++cnt;
		cout << "numbered2(): cnt = " << cnt << '\n';
	}
	numbered2(const numbered2 &orig)
	{
		cout << "numbered2(const numbered2 &): old num = " << num;
		num = ++cnt;
		cout << ", new num = " << cnt << '\n';
	}

private:
	int num;
};

void f2(numbered2 s)
{
	cout << s.num << '\n';
}

void f3(const numbered2 &s)
{
	cout << s.num << '\n';
}

int main()
{
	numbered1 a1, b1 = a1, c1 = b1;
	f1(a1);
	f1(b1);
	f1(c1);

	cout << "###" << cnt << "###\n";

	numbered2 a2, b2 = a2, c2 = b2;
	f2(a2);
	f2(b2);
	f2(c2);

	cout << "###" << cnt << "###\n";

	f3(a2);
	f3(b2);
	f3(c2);

	cout << "###" << cnt << "###\n";
	return 0;
}
/*
Output:
numbered1(): cnt = 1
1
1
1

###1###
numbered2(): cnt = 2
numbered2(const numbered2 &): old num = 2, new num = 3
numbered2(const numbered2 &): old num = 1, new num = 4
numbered2(const numbered2 &): old num = 4197328, new num = 5
5
numbered2(const numbered2 &): old num = 5, new num = 6
6
numbered2(const numbered2 &): old num = 6, new num = 7
7

###7###
2
3
4

###7###
*/
```

##Exercises Section 13.1.6

###Exercise 13.18

>Define an Employee class that contains an employee name and a unique employee identifier. Give the class a default constructor and a constructor that takes a string representing the employee’s name. Each constructor should generate a unique ID by incrementing a static data member.

```cpp
#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
	Employee() : name_(""), id_(++static_id)
	{
		cout << "Employee(): id = " << id_ << '\n';
	}
	Employee(string name) : name_(name), id_(++static_id)
	{
		cout << "Employee(string name): name = " << name_
		     << ", id = " << id_ << '\n';
	}

private:
	string name_;
	int id_;
	static int static_id;
};

int Employee::static_id = 0;

int main()
{
	Employee obj1;
	Employee obj2("gaoxiang");

	return 0;
}
/*
Output:
Employee(): id = 1
Employee(string name): name = gaoxiang, id = 2
*/
```

###Exercise 13.19

>Does your Employee class need to define its own versions of the copy-control members? If so, why? If not, why not? Implement whatever copy-control members you think Employee needs.

 - No: employee can't copy in real world.

```cpp
Employee(const Employee&) = delete;
Employee &operator=(const Employee&) = delete;
```

###Exercise 13.20

>Explain what happens when we copy, assign, or destroy objects of our TextQuery and QueryResult classes from §12.3(p. 484).

 - The member(smart pointer and container) will be copied.

###Exercise 13.21

>Do you think the TextQuery and QueryResult classes need to define their own versions of the copy-control members? If so, why? If not, why not? Implement whichever copy-control operations you think these classes require.

 - The synthesized version meet all requirements for this case.

##Exercises Section 13.2

###Exercise 13.22

>Assume that we want HasPtr to behave like a value. That is, each object should have its own copy of the string to which the objects point. We’ll show the definitions of the copy-control members in the next section. However, you already know everything you need to know to implement these members. Write the HasPtr copy constructor and copy-assignment operator before reading on.

```cpp
#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
public:
	HasPtr(const string &s = string()) : ps(new string(s)), id(0) {}
	HasPtr(const HasPtr &orig) : ps(new string(*(orig.ps))), id(orig.id) {}
	HasPtr &operator=(const HasPtr &rhs)
	{
		ps = new string(*(rhs.ps));
		id = rhs.id;
	}
	~HasPtr()
	{
		delete ps;
	}

	void get_ps() const
	{
		cout << *ps << '\n';
	}
	void set_ps(const string &str)
	{
		delete ps;
		ps = new string(str);
	}

private:
	string *ps;
	int id;
};

int main()
{
	HasPtr obj1("gao"), obj2 = obj1;
	obj1.get_ps();
	obj2.get_ps();

	cout << "After modify obj2:\n";
	obj2.set_ps(string("xiang"));
	obj1.get_ps();
	obj2.get_ps();

	return 0;
}
/*
Output:
gao
gao
After modify obj2:
gao
xiang
*/
```

##Exercises Section 13.2.1

###Exercise 13.23

>Compare the copy-control members that you wrote for the solutions to the previous section’s exercises to the code presented here. Be sure you understand the differences, if any, between your code and ours.

 - Yes.

###Exercise 13.24

>What would happen if the version of HasPtr in this section didn’t define a destructor? What if HasPtr didn’t define the copy constructor?

 - The memory pointed by ps won’t be free.
 - Only copy pointer itself, not string itself.

###Exercise 13.25

>Assume we want to define a version of StrBlob that acts like a value. Also assume that we want to continue to use a shared_ptr so that our StrBlobPtr class can still use a weak_ptr to the vector. Your revised class will need a copy constructor and copy-assignment operator but will not need a destructor. Explain what the copy constructor and copy-assignment operators must do. Explain why the class does not need a destructor.

 - Copy constructor and copy-assignment operator should dynamically allocate memory for its own data, rather than share the object with the right hand operand.
 - StrBlob is using smart pointers which can be managed with synthesized destructor, If an object of StrBlob is out of scope, the destructor for std::shared_ptr will be called automatically to free the memory dynamically allocated when the use_count goes to 0.

###Exercise 13.26

>Write your own version of the StrBlob class described in the previous exercise.

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

	StrBlob(string id) : id_(id), data(make_shared<vector<string>> ())
	{
		cout << "Constructor:\tid = " << id_ << '\n';
	}
	StrBlob(string id, initializer_list<string> il) :
		id_(id), data(make_shared<vector<string>>(il))
	{
		cout << "Constructor:\tid = " << id_ << '\n';
	}
	StrBlob(const StrBlob &obj)
	{
		id_ = obj.id_;
		data = make_shared<vector<string>>(*obj.data);
	}
	StrBlob &operator=(const StrBlob &rhs)
	{
		id_ = rhs.id_;
		data = make_shared<vector<string>>(*rhs.data);
		return *this;
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
			cout << (*data)[index] << ' ';
		}
		cout << '\n';
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

// StrBlobPtr throws an exception on attempts to access a nonexistent element
class StrBlobPtr
{
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	StrBlobPtr(const StrBlobPtr &obj) : wptr(obj.wptr), curr(obj.curr) {}
	StrBlobPtr &operator=(const StrBlobPtr &rhs)
	{
		wptr = rhs.wptr;
		curr = rhs.curr;
		return *this;
	}
	string &deref() const
	{
		shared_ptr<vector<string>> p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	// prefix: return a reference to the incremented object
	StrBlobPtr &incr()
	{
		check(curr, "increment past end of StrBlobPtr");
		++curr;
		return *this;
	}
	bool operator!=(const StrBlobPtr& p)
	{
		return p.curr != curr;
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
	return 0;
}
```

##Exercises Section 13.2.2

###Exercise 13.27

>Define your own reference-counted version of HasPtr.

```cpp
#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
public:
	HasPtr(const string &s1, const string &s2) :
		name(s1), ps(new string(s2)), id(0), use(new size_t(1))
	{
		cout << "Constructor:\tname = " << name << ", *ps = " << *ps
		     << ", ref_count = " << *use << '\n';
	}
	HasPtr(const HasPtr &orig) : ps(orig.ps), id(orig.id), use(orig.use)
	{
		++*use;
		cout << "Copy-Construct:\tname = " << name << ", *ps = " << *ps
		     << ", ref_count = " << *use << '\n';
	}
	HasPtr &operator=(const HasPtr &rhs)
	{
		cout << "Copy-operator:\t";
		cout << "left-hand: name = " << name << ", *ps = " << *ps
		     << ", ref_count = " << *use << '\n';
		cout << "\t\tright-hand: name = " << rhs.name << ", *ps = " << *rhs.ps
		     << ", ref_count = " << *rhs.use << '\n';
		++*rhs.use;
		if(--*use == 0)
		{
			cout << "\t\tRunning left-hand obj's Destructor.\n";
			delete ps;
			delete use;
		}
		ps = rhs.ps;
		id = rhs.id;
		use = rhs.use;
		cout << "Copy-op finish:\tname = " << name << ", *ps = " << *ps
		     << ", ref_count = " << *use << '\n';
		return *this;
	}
	~HasPtr()
	{
		cout << "Destructor:\tBefore --*use: name = " << name << ", *ps = " << *ps
		     << ", ref_count = " << *use << '\n';
		if(--*use == 0)
		{
			delete ps;
			delete use;
			cout << "\t\t--*use = 0: destroy object.\n";
		}
		else
		{
			cout << "\t\t--*use = " << *use << ", not destroy object.\n";
		}
	}

	void get_ps() const
	{
		cout << *ps << '\n';
	}
	void set_ps(const string &str)
	{
		delete ps;
		ps = new string(str);
	}

private:
	string name = "default";
	string *ps;
	int id;
	size_t *use;
};

int main()
{
	HasPtr obj1("obj1", "gao");
	HasPtr obj2(obj1);
	HasPtr obj3("obj3", "xiang");
	obj3 = obj2;
	obj2.set_ps("gaoxiangnumber1");

	return 0;
}
/*
Output:
Constructor:	name = obj1, *ps = gao, ref_count = 1
Copy-Construct:	name = default, *ps = gao, ref_count = 2
Constructor:	name = obj3, *ps = xiang, ref_count = 1
Copy-operator:	left-hand: name = obj3, *ps = xiang, ref_count = 1
		right-hand: name = default, *ps = gao, ref_count = 2
		Running left-hand obj's Destructor.
Copy-op finish:	name = obj3, *ps = gao, ref_count = 3
Destructor:	Before --*use: name = obj3, *ps = gaoxiangnumber1, ref_count = 3
		--*use = 2, not destroy object.
Destructor:	Before --*use: name = default, *ps = gaoxiangnumber1, ref_count = 2
		--*use = 1, not destroy object.
Destructor:	Before --*use: name = obj1, *ps = gaoxiangnumber1, ref_count = 1
		--*use = 0: destroy object.
*/
```

###Exercise 13.28

>Given the following classes, implement a default constructor and the necessary copy-control members.

```cpp
// (a)
class TreeNode
{
private:
	std::string value;
	int count;
	TreeNode *left;
	TreeNode *right;
};
// (b)
class BinStrTree
{
private:
	TreeNode *root;
};
```

```cpp
#include <string>
using namespace std;

class TreeNode
{
public:
	TreeNode() : value(string()), count(new int(1)), left(nullptr), right(nullptr) {}
	TreeNode(const TreeNode& rhs) :
		value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right)
	{
		++*count;
	}
	TreeNode& operator=(const TreeNode& rhs);
	~TreeNode()
	{
		if (--*count == 0)
		{
			if (left)
			{
				delete left;
				left = nullptr;
			}
			if (right)
			{
				delete right;
				right = nullptr;
			}
			delete count;
			count = nullptr;
		}
	}

private:
	string value;
	int* count;
	TreeNode* left;
	TreeNode* right;
};

class BinStrTree
{
public:
	BinStrTree() : root(new TreeNode()) {}
	BinStrTree(const BinStrTree& bst) : root(new TreeNode(*bst.root)) {}
	BinStrTree& operator=(const BinStrTree& bst);
	~BinStrTree()
	{
		delete root;
	}

private:
	TreeNode* root;
};

TreeNode& TreeNode::operator=(const TreeNode& rhs)
{
	++*rhs.count;
	if (--*count == 0)
	{
		if (left)
		{
			delete left;
			left = nullptr;
		}
		if (right)
		{
			delete right;
			right = nullptr;
		}

		delete count;
		count = nullptr;
	}
	value = rhs.value;
	left = rhs.left;
	right = rhs.right;
	count = rhs.count;
	return *this;
}

BinStrTree& BinStrTree::operator=(const BinStrTree& bst)
{
	TreeNode* new_root = new TreeNode(*bst.root);
	delete root;
	root = new_root;
	return *this;
}
```

##Exercises Section 13.3

###Exercise 13.29

>Explain why the calls to swap inside swap(HasPtr&, HasPtr&) don't cause a recursion loop.

 - Because we declare `using std::swap;` before and for built-in types, std::swap is a better match.

###Exercise 13.30

>Write and test a swap function for your valuelike version of HasPtr. Give your swap a print statement that notes when it is executed.

```cpp
#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
	friend void swap(HasPtr &, HasPtr&);

public:
	HasPtr(const string &s = string()) : ps(new string(s)), id(0) {}
	HasPtr(const HasPtr &orig) : ps(new string(*(orig.ps))), id(orig.id) {}
	HasPtr &operator=(const HasPtr &rhs)
	{
		ps = new string(*(rhs.ps));
		id = rhs.id;
	}
	~HasPtr()
	{
		delete ps;
	}

	const string &get_ps() const
	{
		return *ps;
	}
	void set_ps(const string &str)
	{
		delete ps;
		ps = new string(str);
	}

private:
	string *ps;
	int id;
};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
	cout << "\nswap value-like HasPtr\n";
	swap(lhs.ps, rhs.ps);
	swap(lhs.id, rhs.id);
}

int main()
{
	HasPtr obj1("gao"), obj2 = obj1;
	cout << "obj1.get_ps() = " << obj1.get_ps() << '\n';
	cout << "obj2.get_ps() = " << obj2.get_ps() << '\n';

	cout << "\nAfter modify obj2:\n";
	obj2.set_ps(string("xiang"));
	cout << "obj1.get_ps() = " << obj1.get_ps() << '\n';
	cout << "obj2.get_ps() = " << obj2.get_ps() << '\n';

	swap(obj1, obj2);
	cout << "\nAfter swap obj1 and obj2:\n";
	cout << "obj1.get_ps() = " << obj1.get_ps() << '\n';
	cout << "obj2.get_ps() = " << obj2.get_ps() << '\n';

	return 0;
}
/*
Output:
obj1.get_ps() = gao
obj2.get_ps() = gao

After modify obj2:
obj1.get_ps() = gao
obj2.get_ps() = xiang

swap value-like HasPtr

After swap obj1 and obj2:
obj1.get_ps() = xiang
obj2.get_ps() = gao
*/
```

###Exercise 13.31

>Give your class a < operator and define a vector of HasPtr. Give that vector some elements and then sort the vector. Note when swap is called.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class HasPtr
{
	friend bool operator<(const HasPtr &, const HasPtr&);

public:
	HasPtr(const string &s = string()) : ps(new string(s)), id(0) {}
	HasPtr(const HasPtr &orig) : ps(new string(*(orig.ps))), id(orig.id) {}
	//HasPtr &operator=(HasPtr rhs) = delete;
	HasPtr &operator=(HasPtr rhs)
	{
		cout << "operator=: left-obj = " << *ps <<
		     ", right-obj = " << *rhs.ps << ". -> ";
		this->swap(rhs);
		return *this;
	}

	~HasPtr()
	{
		delete ps;
	}

	const string &get_ps() const
	{
		return *ps;
	}
	void set_ps(const string &str)
	{
		delete ps;
		ps = new string(str);
	}

	void swap(HasPtr &rhs)
	{
		cout << *ps << ".swap(" << *rhs.ps << ")\n";
		std::swap(ps, rhs.ps);
		std::swap(id, rhs.id);
	}

private:
	string *ps;
	int id;
};

bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
	return *lhs.ps < *rhs.ps;
}

int main()
{
	HasPtr obj1("d"), obj2("c"), obj3("b"), obj4("a");
	vector<HasPtr> vec {obj1, obj2, obj3, obj4};
	cout << "Before sort:\t";
	for(int index = 0; index < 4; ++index)
	{
		cout << vec[index].get_ps() << ' ';
	}
	cout << "\n\n";
	sort(vec.begin(), vec.end());

	cout << "\nAfter sort:\t";
	for(int index = 0; index < 4; ++index)
	{
		cout << vec[index].get_ps() << ' ';
	}

	return 0;
}
/*
Output1: when define copy-assignment operator
Before sort:	d c b a

operator=: left-obj = c, right-obj = d. -> c.swap(d)
operator=: left-obj = d, right-obj = c. -> d.swap(c)
operator=: left-obj = b, right-obj = d. -> b.swap(d)
operator=: left-obj = d, right-obj = c. -> d.swap(c)
operator=: left-obj = c, right-obj = b. -> c.swap(b)
operator=: left-obj = a, right-obj = d. -> a.swap(d)
operator=: left-obj = d, right-obj = c. -> d.swap(c)
operator=: left-obj = c, right-obj = b. -> c.swap(b)
operator=: left-obj = b, right-obj = a. -> b.swap(a)

After sort:	a b c d
*/
/*
Output2: when not define copy-assignment operator
Before sort:	d c b a



*** Error in `cpp': free(): invalid pointer: 0x0000000001d57148 ***

After sort:	!�q� !�q� !�q� d Aborted
*/
/*
Output3: when "HasPtr &operator=(HasPtr rhs) = delete;"
error: use of deleted function ‘HasPtr& HasPtr::operator=(HasPtr)’
*/
```

###Exercise 13.32

>Would the pointerlike version of HasPtr benefit from defining a swap function? If so, what is the benefit? If not, why not?

 - Avoiding memory allocation is the reason why it improve performance. As for the pointerlike version, no dynamic memory allocation anyway. Thus, a specific version for it will not improve the performance.

##Exercises Section 13.4

###Exercise 13.33

>Why is the parameter to the save and remove members of Message a Folder&? Why didn’t we define that parameter as Folder? Or const Folder&?

 - If `Folder`: we will change the temporary copied object, not the original folder object.
 - If `const Folder&`: we can’t change the folder object since it is const.

###Exercise 13.34

>Write the Message class as described in this section.

 - See 13.36.

###Exercise 13.35

>What would happen if Message used the synthesized versions of the copy-control members?

 - Some existing Folders will out of sync with the Message after assignment.

###Exercise 13.36

>Design and implement the corresponding Folder class. That class should hold a set that points to the Messages in that Folder.

```cpp
// .h
#include <string>
#include <set>

using namespace std;

class Folder;
class Message
{
	friend void swap(Message&, Message&);
	friend class Folder;

public:
	// folders is implicitly initialized to the empty set
	explicit Message(const string &str = ""): contents(str) {}
	// copy control to manage pointers to this Message
	Message(const Message &m);
	Message& operator=(const Message &rhs);
	~Message();
	// add/remove this Message from the specified Folder's set of messages
	void save(Folder &f);
	void remove(Folder &f);

private:
	string contents; // actual message text
	set<Folder*> folders; // Folders that have this Message
	// utility functions used by copy constructor, assignment, and destructor
	// add this Message to the Folders that point to the parameter
	void add_to_Folders(const Message &m);
	// remove this Message from every Folder in folders
	void remove_from_Folders();
	void addFldr(Folder *f)
	{
		folders.insert(f);
	}
	void remFldr(Folder *f)
	{
		folders.erase(f);
	}
};

void swap(Message &lhs, Message &rhs);

class Folder
{
	friend void swap(Folder&, Folder&);
	friend class Message;

public:
	Folder() = default;
	Folder(const Folder &f);
	Folder& operator=(const Folder &);
	~Folder();

private:
	std::set<Message*> msgs;
	void add_to_Message(const Folder &f);
	void remove_from_Message();
	void addMsg(Message *m)
	{
		msgs.insert(m);
	}
	void remMsg(Message *m)
	{
		msgs.erase(m);
	}
};

void swap(Folder &lhs, Folder &rhs);
```

```cpp
// .cpp
#include <iostream>
#include "msgfldr.h"

Message::Message(const Message &m): contents(m.contents), folders(m.folders)
{
	add_to_Folders(m); // add this Message to the Folders that point to m
}
Message& Message::operator=(const Message &rhs) // copy assignment
{
	// handle self-assignment by removing pointers before inserting them
	remove_from_Folders(); // update existing Folders
	contents = rhs.contents; // copy message contents from rhs
	folders = rhs.folders; // copy Folder pointers from rhs
	add_to_Folders(rhs); // add this Message to those Folders
	return *this;
}
Message::~Message() // destructor
{
	remove_from_Folders();
}
// add/remove this Message from the specified Folder's set of messages
void Message::save(Folder &f)
{
	folders.insert(&f); // add the given Folder to our list of Folders
	f.addMsg(this); // add this Message to f's set of Messages
}
void Message::remove(Folder &f)
{
	folders.erase(&f); // take the given Folder out of our list of Folders
	f.remMsg(this); // remove this Message to f's set of Messages
}

void Message::add_to_Folders(const Message &m)
{
	// for each Folder that holds m
	for(set<Folder*>::iterator f = m.folders.begin(); f != m.folders.end(); ++f)
	{
		(*f)->addMsg(this); // add a pointer to this Message to that Folder
	}
}
// remove this Message from every Folder in folders
void Message::remove_from_Folders()
{
	// for each Folder that holds m
	for(set<Folder*>::iterator f = folders.begin(); f != folders.end(); ++f)
	{
		(*f)->remMsg(this); // remove this Message from that Folder
	}
}

void swap(Message &lhs, Message &rhs)
{
	// remove pointers to each Message from their(original) respective Folders
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();
	// swap the contents and Folder pointer sets
	swap(lhs.contents, rhs.contents); // swap(string&, string&)
	swap(lhs.folders, rhs.folders); // swap(set&, set&)
	// add pointers to each Message to their(new) respective Folders
	lhs.add_to_Folders(lhs);
	rhs.add_to_Folders(rhs);
}

Folder::Folder(const Folder &f): msgs(f.msgs)
{
	add_to_Message(f);
}
Folder& Folder::operator=(const Folder &rhs)
{
	remove_from_Message();
	msgs = rhs.msgs;
	add_to_Message(rhs);
	return *this;
}
Folder::~Folder()
{
	remove_from_Message();
}
void Folder::add_to_Message(const Folder &f)
{
	for(set<Message*>::iterator m = f.msgs.begin(); m != f.msgs.end(); ++m)
	{
		(*m)->addFldr(this);
	}
}
void Folder::remove_from_Message()
{
	for(set<Message*>::iterator m = msgs.begin(); m != msgs.end(); ++m)
	{
		(*m)->remFldr(this);
	}
}

void swap(Folder &lhs, Folder &rhs)
{
	lhs.remove_from_Message();
	rhs.remove_from_Message();
	swap(lhs.msgs, rhs.msgs);
	lhs.add_to_Message(lhs);
	rhs.add_to_Message(rhs);
}

int main()
{
	Message msg("gaoxiangnumber1");
	Folder fldr;

	return 0;
}
```

###Exercise 13.37

>Add members to the Message class to insert or remove a given Folder* into folders. These members are analogous to Folder’s addMsg and remMsg operations.

 - Same as before.

###Exercise 13.38

>We did not use copy and swap to define the Message assignment operator. Why do you suppose this is so?

 - In this case, swap function is special. It will be clear two Message's folders , then swap members, and added themselves to each folders. But, Message assignment operator just clear itself, and copy the members, and added itself to each folders. The rhs don't need to clear and add to folders. So, if using copy and swap to define, it will be very inefficiency.

##Exercises Section 13.5

###Exercise 13.39

>Write your own version of StrVec, including versions of reserve, capacity(§9.4, p. 356), and resize(§9.3.5, p. 352).

```cpp
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class StrVec
{
public:
	// the allocator member is default initialized
	StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&); // copy constructor
	StrVec &operator=(const StrVec&); // copy assignment
	~StrVec(); // destructor
	size_t size() const
	{
		return first_free - elements;
	}
	size_t capacity() const
	{
		return cap - elements;
	}
	string *begin() const
	{
		return elements;
	}
	string *end() const
	{
		return first_free;
	}
	void push_back(const string&); // copy the element
	void reserve(size_t);
	void resize(size_t);
	void resize(size_t, const string&);

private:
	allocator<string> alloc; // allocates the elements
	void chk_n_alloc() // used by the functions that add elements to the StrVec
	{
		if(size() == capacity())
		{
			reallocate();
		}
	}
	// utilities used by the copy constructor, assignment operator, and destructor
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void alloc_n_move(size_t new_cap);
	void free(); // destroy the elements and free the space
	void reallocate(); // get more space and copy the existing elements
	string *elements; // pointer to the first element in the array
	string *first_free; // pointer to the first free element in the array
	string *cap; // pointer to one past the end of the array
};

pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	// allocate space to hold as many elements as are in the range
	string *data = alloc.allocate(e - b);
	// initialize and return a pair constructed from data and
	// the value returned by uninitialized_copy
	return {data, uninitialized_copy(b, e, data)};
}

void StrVec::alloc_n_move(size_t newcapacity)
{
	// allocate new memory
	string *newdata = alloc.allocate(newcapacity);
	// move the data from the old memory to the new
	string *dest = newdata; // points to the next free position in the new array
	string *elem = elements; // points to the next element in the old array
	for(size_t i = 0; i != size(); ++i)
	{
		alloc.construct(dest++, std::move(*elem++));
	}
	free(); // free the old space once we've moved the elements
	// update our data structure to point to the new elements
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void StrVec::free()
{
	// may not pass deallocate a 0 pointer; if elements is 0, there's no work to do
	if(elements)
	{
		// destroy the old elements in reverse order
		for(string *p = first_free; p != elements; )
		{
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate()
{
	// we'll allocate space for twice as many elements as the current size
	size_t newcapacity = size() ? 2 * size() : 1;
	alloc_n_move(newcapacity);
}

StrVec::StrVec(const StrVec &s)
{
	// call alloc_n_copy to allocate exactly as many elements as in s
	pair<string*, string*> newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
	// call alloc_n_copy to allocate exactly as many elements as in rhs
	pair<string*, string*> data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec::~StrVec()
{
	free();
}

void StrVec::push_back(const string &s)
{
	chk_n_alloc(); // ensure that there is room for another element
	// construct a copy of s in the element to which first_free points
	alloc.construct(first_free++, s);
}

void StrVec::reserve(size_t newcapacity)
{
	if (newcapacity <= capacity())
	{
		return;
	}
	alloc_n_move(newcapacity);
}

void StrVec::resize(size_t count, const std::string &s)
{
	if (count > size())
	{
		if (count > capacity())
		{
			reserve(count * 2);
		}
		for (size_t i = size(); i != count; ++i)
		{
			alloc.construct(first_free++, s);
		}
	}
	else if (count < size())
	{
		while (first_free != elements + count)
		{
			alloc.destroy(--first_free);
		}
	}
}

void StrVec::resize(size_t count)
{
	resize(count, std::string());
}

int main()
{
	return 0;
}
```

###Exercise 13.40

>Add a constructor that takes an initializer_list<string> to your StrVec class.

```cpp
// Only show the changes: define a new private function
// void range_initialize(const string*, const string*);
class StrVec
{
public:
	StrVec(initializer_list<string>);
	StrVec(const StrVec &s);

private:
	void range_initialize(const string*, const string*);
};

pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	// allocate space to hold as many elements as are in the range
	string *data = alloc.allocate(e - b);
	// initialize and return a pair constructed from data and
	// the value returned by uninitialized_copy
	return {data, uninitialized_copy(b, e, data)};
}

void StrVec::range_initialize(const string *b, const string *e)
{
	// call alloc_n_copy to allocate exactly as many elements as in s
	pair<string*, string*> newdata = alloc_n_copy(b, e);
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(initializer_list<string> il)
{
	range_initialize(il.begin(), il.end());
}

StrVec::StrVec(const StrVec &s)
{
	range_initialize(s.begin(), s.end());
}
```

###Exercise 13.41

>Why did we use postfix increment in the call to construct inside push_back? What would happen if it used the prefix increment?

 - There will be empty slot.

###Exercise 13.42

>Test your StrVec class by using it in place of the vector<string> in your TextQuery and QueryResult classes(§12.3, p. 484).

 - Not do.

###Exercise 13.43

>Rewrite the free member to use for_each and a lambda(§10.3.2, p. 388) in place of the for loop to destroy the elements. Which implementation do you prefer, and why?

 - `for_each(elements, first_free, [this](std::string &rhs){ alloc.destroy(&rhs); });`
The new version is better. Compared to the old one, it doesn't need to worry about the order and decrement. So more straightforward and handy. The only thing to do for using this approach is to add "&" to build the pointers to string pointers.

###Exercise 13.44

>Write a class named String that is a simplified version of the library string class. Your class should have at least a default constructor and a constructor that takes a pointer to a C-style string. Use an allocator to allocate memory that your String class uses.

 - See 13.47.
A trivial String class that designed for write-on-paper in an interview

##Exercises Section 13.6.1

###Exercise 13.45

>Distinguish between an rvalue reference and an lvalue reference.

 - Lvalue reference: reference that can bind to an lvalue. (Regular reference)
 - Rvalue reference: reference to an object that is about to be destroyed.

###Exercise 13.46

>Which kind of reference can be bound to the following initializers?

```cpp
int f();
vector<int> vi(100);
int? r1 = f();
int? r2 = vi[0];
int? r3 = r1;
int? r4 = vi[0] * f();
```

 - &&
 - &
 - &
 - &&

###Exercise 13.47

>Give the copy constructor and copy-assignment operator in your String class from exercise 13.44 in §13.5(p. 531) a statement that prints a message each time the function is executed.

 - See 48.

###Exercise 13.48

>Define a vector<String> and call push_back several times on that vector. Run your program and see how often Strings are copied.

```cpp
// Test reference to http://coolshell.cn/articles/10478.html
#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

class String
{
public:
	String(string id2): String(id2, "")
	{
		cout << "Default constructor -> String("")\n";
	}
	String(string id2, const char *);
	String(const String&);
	String& operator=(const String&);
	~String();

	const char *c_str() const
	{
		return elements;
	}
	size_t size() const
	{
		return end - elements;
	}
	size_t length() const
	{
		return end - elements - 1;
	}

private:
	string id = "default";
	pair<char*, char*> alloc_n_copy(const char*, const char*);
	void range_initializer(const char*, const char*);
	void free();
	char *elements;
	char *end;
	allocator<char> alloc;
};

pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
{
	char *str = alloc.allocate(e - b);
	return {str, uninitialized_copy(b, e, str)};
}

void String::range_initializer(const char *first, const char *last)
{
	pair<char*, char*> newstr = alloc_n_copy(first, last);
	elements = newstr.first;
	end = newstr.second;
}

void String::free()
{
	if (elements)
	{
		for(char *c = elements; c != end; ++c)
		{
			alloc.destroy(c);
		}
		alloc.deallocate(elements, end - elements);
	}
}

String::String(string id2, const char *s)
{
	char *sl = const_cast<char*>(s);
	while(*sl)
	{
		++sl;
	}
	range_initializer(s, ++sl);
	id = id2;
	cout << "Constructor: String(const char *s). id = " << id << "\n";
}

String::String(const String& rhs)
{
	cout << "Copy Constructor: left = " << id << ", right = " << rhs.id << "\n";
	range_initializer(rhs.elements, rhs.end);
	id = rhs.id;
}

String& String::operator=(const String &rhs)
{
	pair<char*, char*> newstr = alloc_n_copy(rhs.elements, rhs.end);
	free();
	elements = newstr.first;
	end = newstr.second;
	cout << "Copy Assignment=: left = " << id << ", right = " << rhs.id << "\n";
	id = rhs.id;
	return *this;
}

String::~String()
{
	free();
	cout << "Destructor: id = " << id << "\n";
}

int main()
{
	String str1(string("str1"));
	String str2(string("str2"), "gaoxiangnumber1");
	String str3(str2);
	String str4 = str3;
	String str5(string("str5"));
	str5 = str4;
	String str6(string("str6"), "hello world!");

	cout << "Create vector<String> vec;\n";
	vector<String> vec(3, string("push"));
	vec.push_back(str1);
	vec.push_back(str4);
	vec.push_back(str6);

	return 0;
}
/*
Output:
Constructor: String(const char *s). id = str1
Default constructor -> String()
Constructor: String(const char *s). id = str2
Copy Constructor: left = default, right = str2
Copy Constructor: left = default, right = str2
Constructor: String(const char *s). id = str5
Default constructor -> String()
Copy Assignment=: left = str5, right = str2
Constructor: String(const char *s). id = str6
Create vector<String> vec;
Constructor: String(const char *s). id = push
Default constructor -> String()
Copy Constructor: left = default, right = push
Copy Constructor: left = default, right = push
Copy Constructor: left = default, right = push
Destructor: id = push
Copy Constructor: left = default, right = str1
Copy Constructor: left = default, right = push
Copy Constructor: left = default, right = push
Copy Constructor: left = default, right = push
Destructor: id = push
Destructor: id = push
Destructor: id = push
Copy Constructor: left = default, right = str2
Copy Constructor: left = default, right = str6
Destructor: id = push
Destructor: id = push
Destructor: id = push
Destructor: id = str1
Destructor: id = str2
Destructor: id = str6
Destructor: id = str6
Destructor: id = str2
Destructor: id = str2
Destructor: id = str2
Destructor: id = str2
Destructor: id = str1
*/
```

##Exercises Section 13.6.2

###Exercise 13.49

>Add a move constructor and move-assignment operator to your StrVec, String, and Message classes.

```cpp
// For String:
String::String(String&& s) noexcept :
elements(s.elements), end(s.end)
{
	s.elements = s.end = nullptr;
}

String& String::operator=(String&& rhs) noexcept
{
	if(this != &rhs)
	{
		free();
		elements = rhs.elements;
		end = rhs.end;
		rhs.elements = rhs.end = nullptr;
	}
	return *this;
}

// For StrVec:
StrVec::StrVec(StrVec&& s) noexcept:
	elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	// leave s in a state in which it is safe to run the destructor.
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec&& rhs) noexcept
{
	if(this != &rhs)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}
```

###Exercise 13.50

>Put print statements in the move operations in your String class and rerun the program from exercise 13.48 in §13.6.1(p. 534) that used a vector<String> to see when the copies are avoided.

```cpp
String mov()
{
	String ret("world");
	return ret; // first avoided
}
String s5 = mov(); // second avoided
```

###Exercise 13.51

>Although unique_ptrs can't be copied, in §12.1.5(p. 471) we wrote a clone function that returned a unique_ptr by value. Explain why that function is legal and how it works.
§12.1.5: There is one exception to the rule that we cannot copy a unique_ptr: We can copy or assign a unique_ptr that is about to be destroyed. The common example is when we return a unique_ptr from a function.

```
unique_ptr<int> clone(int p)
{
	// ok: explicitly create a unique_ptr<int> from int*
	return unique_ptr<int>(new int(p));
}
```

Alternatively, we can also return a copy of a local object:

```
unique_ptr<int> clone(int p)
{
	unique_ptr<int> ret(new int (p));
	// . . .
	return ret;
}
```

 - For such case, move semantics is expected rather than copy operation. That's why a unique_ptr may be returned from a function by value. Reference.
 - The result of a call to clone is an rvalue, so it uses the move-assignment operator rather than copy-assignment operator. Thus, it is legal and can pretty work.

###Exercise 13.52

>Explain in detail what happens in the assignments of the HasPtr objects on page 541. In particular, describe step by step what happens to values of hp, hp2, and of the rhs parameter in the HasPtr assignment operator.

 - rhs parameter is nonreference, which means the parameter is copy initialized. Depending on the type of the argument, copy initialization uses either the copy constructor or the move constructor.
 - lvalues are copied and rvalues are moved. Thus, in `hp = hp2;`, hp2 is an lvalue, copy constructor used to copy hp2. In `hp = std::move(hp2);`, move constructor moves hp2.

###Exercise 13.53

>As a matter of low-level efficiency, the HasPtr assignment operator isn't ideal. Explain why. Implement a copy-assignment and move-assignment operator for HasPtr and compare the operations executed in your new move-assignment operator versus the copy-and-swap version.

```cpp
#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
public:
	friend void swap(HasPtr&, HasPtr&);
	HasPtr(const string& s = string());
	HasPtr(const HasPtr& hp);
	HasPtr(HasPtr&& p) noexcept;
	HasPtr& operator=(HasPtr rhs);
	/*
	HasPtr& operator=(const HasPtr &rhs);
	HasPtr& operator=(HasPtr &&rhs) noexcept;
	*/
	~HasPtr();

private:
	string* ps;
	int i;
};

inline void swap(HasPtr& lhs, HasPtr& rhs)
{
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	cout << "call swap" << endl;
}

HasPtr::HasPtr(const string& s) : ps(new string(s)), i(0)
{
	cout << "call constructor" << endl;
}

HasPtr::HasPtr(const HasPtr& hp) : ps(new string(*hp.ps)), i(hp.i)
{
	cout << "call copy constructor" << endl;
}

HasPtr::HasPtr(HasPtr&& p) noexcept :
ps(p.ps), i(p.i)
{
	p.ps = 0;
	cout << "call move constructor" << endl;
}

HasPtr& HasPtr::operator=(HasPtr rhs)
{
	swap(*this, rhs);
	return *this;
}

/*
HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    cout << "call copy assignment" << endl;
    return *this;
}

HasPtr& HasPtr::operator=(HasPtr &&rhs) noexcept
{
    if (this != &rhs)
    {
        delete ps;
        ps = rhs.ps;
        i = rhs.i;
        rhs.ps = nullptr;
        cout << "call move assignment" << endl;
    }
    return *this;
}
*/

HasPtr::~HasPtr()
{
	cout << "call destructor" << endl;
	delete ps;
}

int main()
{
	HasPtr hp1("hello"), hp2("World"), *pH = new HasPtr("World");
	hp1 = hp2;
	hp1 = move(*pH);
}
```

 - Reference.

###Exercise 13.54

>What would happen if we defined a HasPtr move-assignment operator but did not change the copy-and-swap operator? Write code to test your answer.

```cpp
error: ambiguous overload for 'operator=' (operand types are 'HasPtr' and 'std::remove_reference<HasPtr&>::type
hp1 = std::move(*pH);
^
```

##Exercises Section 13.6.3

###Exercise 13.55

>Add an rvalue reference version of push_back to your StrBlob.

```cpp
void push_back(string &&s)
{
	data->push_back(std::move(s));
}
```

###Exercise 13.56

>What would happen if we defined sorted as:
```cpp
Foo Foo::sorted() const &
{
	Foo ret(*this);
	return ret.sorted();
}
```

 - Because the local variable ret is an lvalue, so when we call ret.sorted(), we are not calling `Foo Foo::sorted() &&`, but `Foo Foo::sorted() const &` instead. As a result, the code will be trapped into a recursion and causes a stack overflow.

###Exercise 13.57

>What if we defined sorted as:
```cpp
Foo Foo::sorted() const &
{
	return Foo(*this).sorted();
}
```

 - ok, it will call the move version.

###Exercise 13.58

>Write versions of class Foo with print statements in their sorted functions to test your answers to the previous two exercises.

```cpp
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Foo
{
public:
	Foo sorted() &&;
	Foo sorted() const &;

private:
	vector<int> data;
};

Foo Foo::sorted() &&
{
	sort(data.begin(), data.end());
	cout << "&&" << endl; // debug
	return *this;
}

Foo Foo::sorted() const &
{
//    Foo ret(*this);
//    sort(ret.data.begin(), ret.data.end());
//    return ret;

	cout << "const &" << endl; // debug

//    Foo ret(*this);
//    ret.sorted();     // Exercise 13.56
//    return ret;

	return Foo(*this).sorted(); // Exercise 13.57
}

int main()
{
	Foo().sorted(); // call "&&"
	Foo f;
	f.sorted(); // call "const &"
}
```


