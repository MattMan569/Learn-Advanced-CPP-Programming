// ObjectInitialization.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

using namespace std;


class Test
{
private:
	// Init values in every object
	int id{ 3 };
	int id2 = 8;
	string name{ "Mike" };

public:
	// Set constructor to default implementation
	Test() = default;

	// Set copy constructor to default implementation
	// Test(const Test & other) = default;
	
	// Explicitly prevent the copy constructor from being used
	Test(const Test & other) = delete;

	// Set = operator to default implementation
	// Test &operator=(const Test & other) = default;
	Test &operator=(const Test & other) = delete;

	Test(int id) : id(id)
	{
		
	}

	void print()
	{
		cout << id << " " << id2 << " " << name << endl;
	}
};


int main()
{
	Test test;
	test.print();

	// Override the default value of the class
	Test test1(77);
	test1.print();

	// Utilizes deleted copy constructor and assignment operator
	// Test test2 = test1; // Uses copy constructor
	// test2 = test; // Uses assignment operator


    return 0;
}

