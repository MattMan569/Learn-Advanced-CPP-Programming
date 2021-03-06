// Capturing-this-WithLambdas.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;


class Test
{
private:
	int one = 1;
	int two{ 2 };

public:
	void run()
	{
		int three{ 3 };
		int four = 4;

		// Cannot capture instance variables (one, two) like local variables
		// Need to capture "this" which captures all instance variables by reference
		// auto pLambda = [this, three, four]()
		auto pLambda = [this, three, four]()
		{
			one = 111;
			cout << one << endl;
			cout << two << endl;
			cout << three << endl;
			cout << four << endl;
		};
		pLambda();
	}
};


int main()
{
	Test test;
	test.run();


    return 0;
}

