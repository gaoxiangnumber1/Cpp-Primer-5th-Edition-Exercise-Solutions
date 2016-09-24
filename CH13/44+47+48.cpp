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
