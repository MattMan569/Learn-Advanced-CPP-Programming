// ExceptionCatchingOrder.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <exception>
using namespace std;


void goesWrong()
{
	bool error1Detected = true;
	bool error2Detected = false;

	if (error1Detected)
	{
		throw bad_alloc();
	}

	if (error2Detected)
	{
		throw exception();
	}
}


int main()
{
	try
	{
		goesWrong();
	}
	catch (bad_alloc &e)
	{
		cout << "Catching bad_alloc: " << e.what() << endl;
	}
	catch (exception &e)
	{
		cout << "Catching exception: " << e.what() << endl;
	}

	/*
			This is incorrect because bad_alloc is a subclass of exception.
			Due to polymorphism the bad_alloc subclass can use exception class methods, namely "what",
				as bad_alloc is derived from exception.
			Subclass exceptions should be caught before base class to ensure the correct catch statement is used.
	
	try
	{
		goesWrong();
	}
	catch (exception &e)
	{
	cout << "Catching exception: " << e.what() << endl;
	}
	catch (bad_alloc &e)
	{
		cout << "Catching bad_alloc: " << e.what() << endl;
	}

	*/
	

    return 0;
}

