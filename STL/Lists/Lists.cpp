#include <iostream>
#include <list>

using namespace std;


int main()
{
	list<int> numbers;

	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_front(0);


	list<int>::iterator it = numbers.begin();
	it++;
	numbers.insert(it, 100);
	cout << "Element: " << *it << endl;

	
	list<int>::iterator eraseIt = numbers.begin();
	eraseIt++;
	eraseIt = numbers.erase(eraseIt); // Erase returns the iterator to the next value
	cout << "Element: " << *eraseIt << endl;
	

	for (list<int>::iterator it = numbers.begin(); it != numbers.end();)
	{
		if (*it == 2)
		{
			numbers.insert(it, 1234);
		}

		if (*it == 1)
		{
			// Erase invalidates the iterator, have to set it to next element
			it = numbers.erase(it);
		}
		else
		{
			it++;
		}
	}


	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		cout << *it << endl;
	}


	return 0;
}