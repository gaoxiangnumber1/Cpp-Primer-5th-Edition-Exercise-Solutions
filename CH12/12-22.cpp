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

// ConstStrBlobPtr throws an exception on attempts to access a nonexistent element
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
		return (*p)[curr];
	}
	// prefix: return a reference to the incremented object
	ConstStrBlobPtr &incr()
	{
		check(curr, "increment past end of ConstStrBlobPtr");
		++curr;
		return *this;
	}
	bool operator!=(const ConstStrBlobPtr& p)
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
			throw runtime_error("unbound ConstStrBlobPtr");
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
