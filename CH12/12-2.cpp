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

	StrBlob(string id) : id_(id), data(make_shared<vector<string>> ())
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
