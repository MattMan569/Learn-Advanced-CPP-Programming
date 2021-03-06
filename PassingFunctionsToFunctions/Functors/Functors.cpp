// Functors.cpp : Defines the entry point for the console application.
//
// Functors are essentially an alternative to function pointers

#include <iostream>
#include <string>

using namespace std;


// Abstract functor
struct Test
{
	virtual bool operator() (string & text) = 0;
};


// Functor:
struct MatchTest : public Test
{
	// Specify the operator, then the argument list
	virtual bool operator() (string & text)
	{
		return text == "lion";
	}
};


// Need test to be a reference for polymorphic purposes
// Allow any class derived from Test to be used
void check(string text, Test & test)
{
	if (test(text))
	{
		cout << "Text matches!" << endl;
	}
	else
	{
		cout << "No match." << endl;
	}
}


int main()
{
	MatchTest pred;

	string value = "lion";
	string value2 = "dog";

	cout << boolalpha << pred(value) << noboolalpha << endl;
	cout << boolalpha << pred(value2) << noboolalpha << endl;


	cout << endl;


	MatchTest m;

	check("lion", m);
	check("dog", m);


    return 0;
}

