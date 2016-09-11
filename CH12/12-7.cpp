#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> Allocate()
{
	return make_shared<vector<int>>();
}

void Input(shared_ptr<vector<int>> vec)
{
	int data;
	while(cin >> data)
	{
		vec->push_back(data);
	}
}

void Output(shared_ptr<vector<int>> vec)
{
	int length = vec->size();
	for(int index = 0; index < length; ++index)
	{
		cout << (*vec)[index] << ' ';
	}
	cout << '\n';
}

int main()
{
	shared_ptr<vector<int>> vec = Allocate();
	Input(vec);
	Output(vec);

	return 0;
}
