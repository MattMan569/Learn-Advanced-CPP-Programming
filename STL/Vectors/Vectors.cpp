#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
	vector<string> strings;

	strings.push_back("one");
	strings.push_back("two");
	strings.push_back("three");

	// Subscript
	for (int i = 0; i < strings.size(); i++)
	{
		cout << strings[i] << endl;
	}

	cout << endl;

	// Explicit iterator
	for (vector<string>::iterator it = strings.begin(); it != strings.end(); it++)
	{
		cout << *it << endl;
	}

	cout << endl;

	// Auto iterator
	for (auto it = strings.begin(); it != strings.end(); it++)
	{
		cout << *it << endl;
	}

	cout << endl;
	
	// Range
	for (auto const &value : strings)
	{
		cout << value << endl;
	}


	cout << endl;
	return 0;
}