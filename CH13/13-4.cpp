#include <iostream>

using namespace std;

class Point
{
public:
	Point(string id) : id_(id)
	{
		cout << "Constructor: id = " << id_ << "\n";
	}
	Point(const Point &obj) : id_(obj.id_)
	{
		cout << "Copy constructor: id = " << id_ << "\n";
	}
	~Point()
	{
		cout << "Destructor: id = " << id_ << "\n";
	}

private:
	string id_;
};

Point global("global");
Point foo_bar(Point arg)
{
	cout << "Enter call, before `Point local = arg;`\n";
	Point local = arg;
	cout << "After `Point local = arg;`, before `Point *heap = new Point(global);`\n";
	Point *heap = new Point(global);
	cout << "After `Point *heap = new Point(global);`, before `*heap = local;`\n";
	*heap = local;
	cout << "After `*heap = local;`, before `Point pa[ 4 ] = { local, *heap };`\n";
	Point pa[ 4 ] = {local, *heap, string("default 1"), string("default 2")};
	cout << "After `Point pa[ 4 ] = { local, *heap };`, before `return *heap;`\n";
	return *heap;
}

int main()
{
	Point obj("obj");
	cout << "Before call\n";
	foo_bar(obj);
	cout << "After call\n";
}
/*
Output:
Constructor: id = global
Constructor: id = obj
Before call
Copy constructor: id = obj
Enter call, before `Point local = arg;`
Copy constructor: id = obj
After `Point local = arg;`, before `Point *heap = new Point(global);`
Copy constructor: id = global
After `Point *heap = new Point(global);`, before `*heap = local;`
After `*heap = local;`, before `Point pa[ 4 ] = { local, *heap };`
Copy constructor: id = obj
Copy constructor: id = obj
Constructor: id = default 1
Constructor: id = default 2
After `Point pa[ 4 ] = { local, *heap };`, before `return *heap;`
Copy constructor: id = obj
Destructor: id = default 2
Destructor: id = default 1
Destructor: id = obj
Destructor: id = obj
Destructor: id = obj
Destructor: id = obj
Destructor: id = obj
After call
Destructor: id = obj
Destructor: id = global
*/
