// MutableLambdas.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;


int main()
{
	int cats = 5;
	int dogs = 4;


	// Cats are captured by value so cannot be modified
	// Mutable keyword allows values to be modified but
	// new values are not saved out of the lambdas scope
	[cats]() mutable
	{
		cats = 8;
		cout << cats << endl;
	} ();
	cout << cats << endl;

	[&dogs]() mutable
	{
		dogs = 11;
		cout << dogs << endl;
	} ();
	cout << dogs << endl;


    return 0;
}

