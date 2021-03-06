// VectorsAndMemory.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>

using namespace std;


int main()
{
	// Vector of size 20
	vector<double> numbers(20);

	cout << "Size: " << numbers.size() << endl;

	int capacity = numbers.capacity();
	cout << "Capacity: " << capacity << endl;

	// Vector will increase in size exponentially when size meets capacity
	for (int i = 0; i < 1000000; i++)
	{
		if (numbers.capacity() != capacity)
		{
			capacity = numbers.capacity();
			cout << "Capacity: " << capacity << endl;
		}

		numbers.push_back(i);
	}

	// Alters size but not capacity, memory and data is left untouched; only inaccessable
	numbers.resize(100);
	cout << "Size: " << numbers.size() << endl;
	cout << "Capacity: " << numbers.capacity() << endl;

	// Resets size but not capacity
	// numbers.clear();
	// cout << "Size: " << numbers.size() << endl;
	// cout << "Capacity: " << numbers.capacity() << endl;

	// Reserving more space
	numbers.reserve(10000000);
	cout << "Size: " << numbers.size() << endl;
	cout << "Capacity: " << numbers.capacity() << endl;

    return 0;
}

