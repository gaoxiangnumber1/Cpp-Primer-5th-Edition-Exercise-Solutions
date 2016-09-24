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
