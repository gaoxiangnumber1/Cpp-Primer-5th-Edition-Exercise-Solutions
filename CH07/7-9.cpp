class Person
{
public:
	string get_name() const
	{
		return name_;
	}
	string get_address() const
	{
		return address_;
	}

private:
	string name_;
	string address_;
};

istream& Read(istream &is, Person &obj)
{
	is >> obj.name_ >> obj.address_;
	return is;
}

ostream& Print(ostream &os, const Person &obj)
{
	os << obj.name_ << ' ' << obj.address_ << '\n';
	return os;
}
