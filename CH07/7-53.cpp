#include <iostream>

using std::cout;

class Debug
{
public:
	constexpr Debug(bool b = true): hardware(b), io(b), other(b) {}
	constexpr Debug(bool h, bool i, bool o) : hardware(h), io(i), other(o) {}
	constexpr bool any()
	{
		return hardware || io || other;
	}
	void set_io(bool b)
	{
		io = b;
	}
	void set_hw(bool b)
	{
		hardware = b;
	}
	void set_other(bool b)
	{
		hardware = b;
	}

private:
	bool hardware;// hardware errors other than IO errors
	bool io;// IO errors
	bool other;// other errors
};

int main()
{
	constexpr Debug io_sub(false, true, false); // debugging IO
	if (io_sub.any()) // equivalent to if(true)
		cout << "print appropriate error messages" << '\n';
	constexpr Debug prod(false); // no debugging during production
	if (prod.any()) // equivalent to if(false)
		cout << "print an error message" << '\n';

	return 0;
}
