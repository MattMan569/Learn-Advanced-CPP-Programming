// ElisionAndOptimization.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Test
{
public:
	Test()
	{
		cout << "Constructor" << endl;
	}

	Test(int i)
	{
		cout << "Parameterized constructor" << endl;
	}

	Test(const Test & other)
	{
		cout << "Copy constructor" << endl;
	}

	Test & operator=(const Test & other)
	{
		cout << "Assignment" << endl;
		return *this;
	}

	~Test()
	{
		cout << "Destructor" << endl;
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

