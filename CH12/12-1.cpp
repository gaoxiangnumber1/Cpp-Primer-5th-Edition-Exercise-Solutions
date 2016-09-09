#include <iostream>
#include <string>
#include <vector>
#include <memory>

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
	void push_back(const string &t)
	{
		data->push_back(t);
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
