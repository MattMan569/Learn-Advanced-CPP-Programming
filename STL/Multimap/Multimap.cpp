// Multimap.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;


int main()
{
	multimap<int, string> lookup;

	// A multimap can have duplicate keys
	lookup.insert(make_pair(30, "Mike"));
	lookup.insert(make_pair(10, "Vicky"));
	lookup.insert(make_pair(30, "Raj"));
	lookup.insert(make_pair(20, "Bob"));

	for (multimap<int, string>::iterator it = lookup.begin(); it != lookup.end(); it++)
	{
		cout << it->first << ": " << it->second << endl;
	}

	cout << endl;

	// Find key 20
	// This loop will also output all proceeding values as well
	for (multimap<int, string>::iterator it = lookup.find(20); it != lookup.end(); it++)
	{
		cout << it->first << ": " << it->second << endl;
	}

	cout << endl;


	// Find the range that contains the key 30
	pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(30);

	// Iterate from the beginning of the range to the end of the range
	for (multimap<int, string>::iterator it = its.first; it != its.second; it++)
	{
		cout << it->first << ": " << it->second << endl;
	}

	cout << endl;


	// Same as above, but with auto
	auto its2 = lookup.equal_range(30);

	for (auto it = its2.first; it != its2.second; it++)
	{
		cout << it->first << ": " << it->second << endl;
	}

    return 0;
}

