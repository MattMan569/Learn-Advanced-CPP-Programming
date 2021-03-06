// AbstractClasses.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;


// An abstract class is a class that contains methods
// which have no implementation
class Animal
{
public:
	// Pure virtual function
	virtual void speak() = 0;
	virtual void run() = 0;
};


class Dog : public Animal
{
public:
	virtual void speak()
	{
		cout << "Woof!" << endl;
	}
};


class Labrador : public Dog
{
public:
	Labrador()
	{
		cout << "New labrador" << endl;
	}

	virtual void run()
	{
		cout << "Labrador running" << endl;
	}
};


// Can use derived classes
void test(Animal & a)
{
	a.speak();
	a.run();
}


int main()
{
	// Must implement all pure virtual functions
	// in order to instantiate a class
	/*Dog dog;
	dog.speak();*/

	Labrador lab;
	lab.speak();
	lab.run();


	Labrador labs[3];


	cout << endl;


	// Can create an array of abstract class pointers
	// as this will not instantiate the abstract class
	Animal * animals[5];
	animals[0] = &lab;
	animals[1] = new Labrador;

	animals[0]->speak();
	animals[0]->run();

	animals[1]->speak();
	animals[1]->run();


	cout << endl;


	test(lab);


	delete animals[1];


    return 0;
}

