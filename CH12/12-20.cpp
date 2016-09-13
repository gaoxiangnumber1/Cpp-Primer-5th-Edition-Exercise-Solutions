#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

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
