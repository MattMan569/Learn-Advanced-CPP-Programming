// DelegatingConstructors.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

using namespace std;


class Parent
{
	int dogs;
	string text;

public:
	Parent()
	{
		dogs = 5;
		cout << "No parameter parent constructor" << endl;
	}

	Parent(string text)
	{
		dogs = 5;
		this->text = text;
		cout << "String parent constructor" << endl;
	}
};


class Child : public Parent
{
public:
	Child() : Parent("Hello")
	{

	}
};


int main()
{
	Parent parent("Hi");
	Child child;


    return 0;
}

