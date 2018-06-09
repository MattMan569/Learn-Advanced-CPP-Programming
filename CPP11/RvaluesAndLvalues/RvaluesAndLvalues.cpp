// In general:
// L-Values are locations
// R-Values are actual values


#include <iostream>
#include <string>

using namespace std;


class Test
{

};


Test getTest()
{
	// return Test();
	Test test;
	return test;
}


int main()
{
	// value1 is an lvalue, 7 is an rvalue
	// Comes from "left" and "right" sides of the statement
	int value1 = 7;


	// Definition extended in C++11
	// lvalue is anything you can take the address of
	// so, value1 is still an lvalue here
	int * pValue1 = &value1;

	// Cannot take the address of 7, not an lvalue
	// Cannot take the address of rvalues
	// int * pValue2 = &7;


	// test1 is a named value we can take the address of
	// thus it is an lvalue
	Test test1;
	Test * pTest1 = &test1;


	// rvalues are often temporary values
	// ie) returns from functions
	// Cannot assign temporary values to rvalues
	// Test * pTest2 = &getTest();


	// No temporary value, works fine
	int * pValue3 = &++value1;
	cout << *pValue3 << endl;

	// Postfix increment requires a temporary value to increment, doesn't work
	// value1++ is an rvalue, cannot take the address of rvalues
	// int * pValue4 = &value1++;


	// value1 is an lvalue but the whole expression is an rvalue
	// Cannot take the address of it
	// int * s = &(7 + value1);


	return 0;
}
