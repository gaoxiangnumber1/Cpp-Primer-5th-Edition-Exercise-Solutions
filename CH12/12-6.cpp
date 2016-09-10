#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> *Allocate()
{
	return new vector<int>();
}

void Input(vector<int> *vec)
{
	int data;
	while(cin >> data)
	{
		vec->push_back(data);
	}
}

void Output(vector<int> *vec)
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
	vector<int> *vec = Allocate();
	Input(vec);
	Output(vec);
	delete vec;

	return 0;
}

