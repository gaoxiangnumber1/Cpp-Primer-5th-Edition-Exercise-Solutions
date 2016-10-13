#include <iostream>
#include <sstream>

using namespace std;

// always declare first:
template <typename T>
string debug_rep(const T& t);
template <typename T>
string debug_rep(T* p);

string debug_rep(const string &s);
string debug_rep(char* p);
string debug_rep(const char *p);

// print any type we don't otherwise.
template<typename T>
string debug_rep(const T& t)
{
	ostringstream ret;
	ret << t;
	return ret.str();
}

// print pointers as their pointer value, followed by the object to which the pointer points
template<typename T>
string debug_rep(T* p)
{
	ostringstream ret;
	ret << "pointer: " << p;

	if (p)
		ret << " " << debug_rep(*p);
	else
		ret << " null pointer";

	return ret.str();
}

// non-template version
string debug_rep(const string &s)
{
	return '"' + s + '"';
}

// convert the character pointers to string and call the string version of debug_rep
string debug_rep(char *p)
{
	return debug_rep(string(p));
}

string debug_rep(const char *p)
{
	return debug_rep(string(p));
}

template<typename T>
ostream& print(ostream& os, const T& t)
{
	return os << t;
}

template<typename T, typename... Args>
ostream& print(ostream &os, const T &t, const Args&... rest)
{
	// print the first argument
	os << t << ",";
	// recursive call; print the other arguments
	return print(os, rest...);
}

// call debug_rep on each argument in the call to print
template<typename... Args>
ostream& error_msg(ostream& os, const Args... rest)
{
	return print(os, debug_rep(rest)...);
}

int main()
{
	error_msg(cout, 1, 2, 3, 4, 9.0f, "gao", "xiang");
	return 0;
}
