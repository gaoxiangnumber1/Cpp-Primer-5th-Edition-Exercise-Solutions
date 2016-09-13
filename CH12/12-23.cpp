#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	// Dynamically allocated array of char
	char *result1 = new char[strlen("gaoxiang") + 1]();
	strcat(result1, "gao");
	strcat(result1, "xiang");
	cout << result1 << '\n';
	delete [] result1;

	// string
	string str1 = "gao", str2 = "xiang";
	string result2 = str1 + str2;
	cout << result2 << '\n';
}
