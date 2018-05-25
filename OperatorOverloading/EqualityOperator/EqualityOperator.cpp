// EqualityOperator.cpp : Defines the entry point for the console application.
//

#include "Complex.h"

#include <iostream>

using namespace std;


int main()
{
	Complex c1(3, 2);
	Complex c2(3, 1);

	if (c1 == c2)
	{
		cout << "Equal" << endl;
	}
	else
	{
		cout << "Not equal" << endl;
	}

	if (c1 != c2)
	{
		cout << "Not equal" << endl;
	}
	else
	{
		cout << "Equal" << endl;
	}


    return 0;
}

