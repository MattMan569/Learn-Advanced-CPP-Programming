// ObjectSlicingAndPolymorphism.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;


class Parent
{
private:
	int one;

public:
	Parent() : one(0)
	{

	}

	Parent(const Parent & other) : one(0)
	{
		// Copy constructor cannot copy "two" from the child sub-class
		// This causes object slicing, parts of child class are "sliced off" and thrown away
		one = other.one;

		cout << "Copy parent" << endl;
	}

	virtual void print() const
	{
		cout << "Parent" << endl;
	}
};


class Child : public Parent
{
private:
	int two;

public:
	Child() : two(0)
	{

	}

	Child(const Child & other)
	{
		cout << "Copy child" << endl;
	}

	void print() const
	{
		cout << "Two: " << two << endl;
		cout << "Child" << endl;
	}
};


int main()
{
	Child c1;


	// Reference to parent pointing to child object
	// As Child is a "kind" of parent object, we can use its methods
	// on parent types as long as parent methods are virtual
	Parent &p1 = c1;
	p1.print();


	// Copy initialization, calling the parent class copy constructor
	// Effectivly upcasting the Child type to the Parent type
	Parent p2 = Child();
	p2.print();


	Parent p3;
	p3 = c1;
	p3.print();


	Parent p4 = c1;
	p4.print();


    return 0;
}

