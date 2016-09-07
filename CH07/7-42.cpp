#include <iostream>
#include <string>

class Book
{
public:
	Book(unsigned isbn, std::string const& name, std::string const& author, std::string const& pubdate)
		:isbn_(isbn), name_(name), author_(author), pubdate_(pubdate) {}
	explicit Book(std::istream &in)
	{
		in >> isbn_ >> name_ >> author_ >> pubdate_;
	}

private:
	unsigned isbn_;
	std::string name_;
	std::string author_;
	std::string pubdate_;
};
