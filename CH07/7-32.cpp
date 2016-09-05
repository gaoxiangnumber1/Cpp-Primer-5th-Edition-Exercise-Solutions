#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::ostream;

class Screen;

class Window_mgr
{
public:
	using ScreenIndex = vector<Screen>::size_type;
	void clear(ScreenIndex i);

private:
	vector<Screen> screens;
};

class Screen
{
	friend void Window_mgr::clear(ScreenIndex);

public:
	typedef	string::size_type	pos;

	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
};

void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.contents = string(s.height * s.width, ' ');
}

int main()
{

	return 0;
}
