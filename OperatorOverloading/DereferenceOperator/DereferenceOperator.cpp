#include "Complex.h"

#include <iostream>

using namespace std;


int main()
{
	Complex c1(2, 4);

	// Get the complex conjugate
	cout << *c1 << endl;

	cout << *Complex(4, 3) + c1 << endl;

	cout << *c1 + *Complex(9, 17) << endl;


	system("pause");
	return 0;
}