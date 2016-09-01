class Person
{
public:
	// We should define get_xx functions as const because
	// they don't modify the class members' value.
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
