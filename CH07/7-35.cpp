#include <iostream>
#include <string>

using std::cout;
using std::string;

typedef string Type;
Type Init_Val();

class Exercise
{
public:
	Type Set_Val(Type);
	Type Init_Val()
	{
		return "gaoxiangnumber1";
	}

private:
	int val;
};

Type Exercise::Set_Val(Type parm)
{
	Type val = parm + Init_Val();
	return val;
}

int main()
{
	Exercise obj;
	cout << obj.Set_Val("hello ");

	return 0;
}
