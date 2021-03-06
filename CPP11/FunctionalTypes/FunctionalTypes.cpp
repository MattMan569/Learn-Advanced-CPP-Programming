// FunctionalTypes.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


// Function pointer
bool check(string & test)
{
	return test.size() == 3;
}


// Functor
class Check
{
public:
	bool operator()(string & test)
	{
		return test.size() == 5;
	}
};


// "run" will accept any function pointer that
// returns a bool and has a string parameter
void run(function<bool(string&)> check)
{
	string test = "dog";
	cout << check(test) << endl;
}


int main()
{
	int size = 3;

	vector<string> vec{ "one", "two", "three" };

	int count;


	// Lambda
	count = count_if(vec.begin(), vec.end(), [size](string test) {return test.size() == size; });
	cout << count << endl;


	// Function pointer
	count = count_if(vec.begin(), vec.end(), check);
	cout << count << endl;


	// Functor
	Check check1;

	count = count_if(vec.begin(), vec.end(), check1);
	cout << count << endl;


	// Functional
	auto lambda = [size](string test) {return test.size() == size; };
	run(lambda); // 1
	run(check1); // 0
	run(check); // 1


	// "add" can refer to anything that is callable that
	// returns an int and takes to int parameters
	function<int(int, int)> add = [](int one, int two) { return one + two; };
	cout << add(7, 3) << endl;



    return 0;
}

