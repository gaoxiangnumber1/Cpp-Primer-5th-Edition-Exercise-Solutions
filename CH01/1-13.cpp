#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	/*
	* Exercise 1.9: Write a program that uses a while
	* to sum the numbers from 50 to 100.
	*/
	cout << "Exercise 1.9\n";
	int sum = 0;
	for(int num = 50; num <= 100; ++num)
	{
		sum += num;
	}
	cout << "The sum from 50 to 100 is " << sum << endl;

	/*
	* Exercise 1.10: Use the decrement operator to write a while
	* that prints the numbers from ten down to zero.
	*/
	cout << "Exercise 1.10\n";
	for(int num = 10; num >= 0; --num)
	{
		cout << num << endl;
	}

	/*
	* Exercise 1.11: Write a program that prompts the user for two integers.
	* Print each number in the range specified by those two integers.
	*/
	cout << "Exercise 1.11\n";
	int num1 = 0, num2 = 0;
	cout << "Please input 2 integers: ";
	cin >> num1 >> num2;

	// We make num1 <= num2
	if(num1 > num2)
	{
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}

	// Print integers in the range [num1, num2]:
	for(; num1 <= num2; ++num1)
	{
		cout << num1 << endl;
	}

	return 0;
}
