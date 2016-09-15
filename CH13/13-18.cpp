#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
	Employee() : name_(""), id_(++static_id)
	{
		cout << "Employee(): id = " << id_ << '\n';
	}
	Employee(string name) : name_(name), id_(++static_id)
	{
		cout << "Employee(string name): name = " << name_
		     << ", id = " << id_ << '\n';
	}

private:
	string name_;
	int id_;
	static int static_id;
};

int Employee::static_id = 0;

int main()
{
	Employee obj1;
	Employee obj2("gaoxiang");

	return 0;
}
/*
Output:
Employee(): id = 1
Employee(string name): name = gaoxiang, id = 2
*/
