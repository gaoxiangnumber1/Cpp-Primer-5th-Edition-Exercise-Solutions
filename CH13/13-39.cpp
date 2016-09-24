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
