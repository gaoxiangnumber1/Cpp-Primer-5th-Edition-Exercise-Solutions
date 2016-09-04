#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::ostream;

class Screen
{
public:
	typedef	string::size_type	pos;

	Screen() = default;
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

	char get() const
	{
		return contents[cursor];
	}
	inline char get(pos ht, pos wd) const;

	Screen &set(char c)
	{
		contents[cursor] = c;
		return *this;
	}
	Screen &set(pos r, pos col, char ch)
	{
		contents[r * width + col] = ch;
		return *this;
	}

	Screen &move(pos r, pos c);

	void some_member() const
	{
		++access_ctr;
	}

	Screen &display(ostream &os)
	{
		do_display(os);
		return *this;
	}
	const Screen &display(ostream &os) const
	{
		do_display(os);
		return *this;
	}

private:
	void do_display(ostream &os) const
	{
		os << contents << '\n';
	}

	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
	mutable size_t access_ctr;
};

inline Screen& Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}

char Screen::get(pos r, pos c) const
{
	pos row = r * width;
	return contents[row + c];
}

int main()
{
	Screen obj(5, 5, 'X');
	obj.move(4, 0).set('#').display(cout);
	obj.display(cout);

	return 0;
}
