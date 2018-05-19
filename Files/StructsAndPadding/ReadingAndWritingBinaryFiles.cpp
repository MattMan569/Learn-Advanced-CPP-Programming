#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Turn off padding
#pragma pack(push, 1)
struct Person
{
	char name[50];
	int age;
	double weight;
};
#pragma pack(pop)
// Re-enable padding

int main()
{
	/* With padding enabled:

	cout << sizeof(Person) << endl;				// 64
	cout << sizeof(Person::name) << endl;		// 50
	cout << sizeof(Person::age) << endl;		// 4
	cout << sizeof(Person::weight) << endl;		// 8
	// 50 + 4 + 8 = 62
	// Structs are padded by default for memory efficiency

	*/

	return 0;
}