#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;


class Test
{
private:
	static const int SIZE = 100;
	int *_pBuffer;

public:
	Test()
	{
		cout << "Constructor" << endl;

		_pBuffer = new int[SIZE] {};


		// Three ways to zero a new array:

		// Set all bytes in a given memory range to the given value (0)
		// memset(_pBuffer, 0, sizeof(int)*SIZE);

		// Type parenthesis after the array
		// _pBuffer = new int[SIZE]();

		// Use an initializer list
		// _pBuffer = new int[SIZE] {};
	}

	Test(int i)
	{
		cout << "Parameterized constructor" << endl;

		_pBuffer = new int[SIZE] {};

		for (int i = 0; i < SIZE; i++)
		{
			_pBuffer[i] = 7 * i;
		}
	}

	Test(const Test & other)
	{
		cout << "Copy constructor" << endl;

		_pBuffer = new int[SIZE] {};

		// Copy the values of the array
		memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
	}

	Test & operator=(const Test & other)
	{
		cout << "Assignment" << endl;

		_pBuffer = new int[SIZE] {};

		// Copy the values of the array
		memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));

		return *this;
	}

	~Test()
	{
		cout << "Destructor" << endl;

		delete[] _pBuffer;
	}

	friend ostream & operator<<(ostream & out, const Test & test);
};

ostream & operator<<(ostream &out, const Test & test)
{
	out << "Hello from test";
	return out;
}


Test getTest()
{
	Test test;

	// This will result in a copy constructor call if
	// optimization is turned off.
	return test;
}


int main()
{
	cout << "main1" << endl;
	Test test1 = getTest();
	cout << test1 << endl;
	cout << "main2" << endl;


	// Object is constructed then copied into the vector
	// even with optimization on
	vector<Test> vec;
	vec.push_back(Test());
	cout << "main3" << endl;


	return 0;
}

