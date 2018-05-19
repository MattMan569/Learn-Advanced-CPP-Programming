#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Disable padding
#pragma pack(push, 1)

struct Person
{
	char name[50];
	int age;
	double weight;
};

// Re-enable padding
#pragma pack(pop)

int main()
{



	return 0;
}