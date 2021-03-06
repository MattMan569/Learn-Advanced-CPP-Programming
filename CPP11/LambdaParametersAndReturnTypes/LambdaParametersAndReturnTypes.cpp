// LambdaParametersAndReturnTypes.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

using namespace std;


void testGreet(void (*greet)(string))
{
	greet("Bob");
}

void runDivide(double(*divide)(double a, double b))
{
	auto rval = divide(9, 3);
	cout << rval << endl;
}


int main()
{
	auto pGreet = [](string name) { cout << "Hello, " << name << endl; };

	pGreet("Mike");

	testGreet(pGreet);


	// Lambda return type can be inferred if
	// there is only one return statement
	auto pDivide = [](double a, double b)
	{
		return a / b;
	};

	cout << pDivide(10.0, 5.0) << endl; // 2


	// 0 is an int, a / b is a double
	// so the type cannot be inferred
	// Use a trailing return type
	auto pDivide2 = [](double a, double b) -> double
	{
		if (b == 0.0)
		{
			return 0;
		}

		return a / b;
	};

	cout << pDivide2(10.0, 0) << endl; // 0


	runDivide(pDivide2); // 3


    return 0;
}

