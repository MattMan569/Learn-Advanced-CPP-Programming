#pragma once

#include <iostream>
using namespace std;


template <class T>
class ring
{
public:
	// Declare iterator as a sub type of ring
	class iterator;
};


// Not a free standing class, nested within ring
// Iterator class assumes the type of ring class
template <class T>
class ring<T>::iterator
{
public:
	void print()
	{
		cout << "Hello from iterator" << endl;
	}
};

