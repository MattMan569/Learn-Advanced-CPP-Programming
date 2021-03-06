// RingBuffer.cpp : Defines the entry point for the console application.
//

#include "ring.h"

#include <iostream>
#include <string>


int main()
{
	ring<string> textring(3);

	textring.add("one");
	textring.add("two");
	textring.add("three");
	// textring.add("four"); // Should overwrite the first value, circular buffer

	for (int i = 0; i < textring.size(); i++)
	{
	cout << textring.get(i) << endl; // four two three
	}

	cout << endl;

	for (ring<string>::iterator it = textring.begin(); it != textring.end(); it++)
	{
		cout << *it << endl;
	}

	cout << endl;

	for (auto value : textring)
	{
		cout << value << endl;
	}


    return 0;
}

