#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

template<typename T>
void Print(vector<T> &vec)
{
	int length = vec.size();
	for(int index = 0; index < length; ++index)
	{
		cout << vec[index] << " ";
	}
	cout << ((length == 0) ? "empty\n" : "\n");
}

int main()
{
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4 {10};
	vector<int> v5 {10, 42};
	vector<string> v6 {10};
	vector<string> v7 {10, "hi"};
	cout << "v1:\t";
	Print(v1);
	cout << "v2:\t";
	Print(v2);
	cout << "v3:\t";
	Print(v3);
	cout << "v4:\t";
	Print(v4);
	cout << "v5:\t";
	Print(v5);
	cout << "v6:\t";
	Print(v6);
	cout << "v7:\t";
	Print(v7);

	return 0;
}
