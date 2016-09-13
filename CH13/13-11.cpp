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
