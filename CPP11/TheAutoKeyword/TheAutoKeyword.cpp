// TheAutoKeyword.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

using namespace std;


int get()
{
	return 999;
}


auto test2() -> decltype(get())
{
	return get();
}


template <class T, class S>
auto test(T value1, S value2) -> decltype(value1 + value2) // Trailing return type
{
	return value1 + value2;
}


int main()
{
	auto value = 7;
	auto text1 = "Hello";
	auto text2 = string("World");

	cout << value << endl;
	cout << text1 << endl;
	cout << text2 << endl;

	cout << test(5, 6) << endl;

	cout << test2() << endl;


    return 0;
}

