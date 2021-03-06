// RangeBasedLoop.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
	// Auto does not need the pointer or brackets
	// char * texts[] = { ... };
	auto texts = {"one", "two", "three"};

	// Range based for loop
	for (auto text : texts)
	{
		cout << text << endl;
	}


	cout << endl;


	vector<int> numbers;
	numbers.push_back(5);
	numbers.push_back(7);
	numbers.push_back(9);
	numbers.push_back(11);

	for (auto number : numbers)
	{
		cout << number << endl;
	}


	cout << endl;


	string hello = "Hello";

	for (auto c : hello)
	{
		cout << c << endl;
	}


	cout << endl;


    return 0;
}

