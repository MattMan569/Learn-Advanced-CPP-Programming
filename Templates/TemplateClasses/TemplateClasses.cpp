#include <iostream>
#include <string>

using namespace std;


template<class T, class K>
class Test
{
private:
	T obj;

public:
	Test(T obj)
	{
		this->obj = obj;
	}

	void print() const
	{
		cout << obj << endl;
	}
};


int main()
{
	Test<string, int> test1("Hello");
	test1.print();



	return 0;
}