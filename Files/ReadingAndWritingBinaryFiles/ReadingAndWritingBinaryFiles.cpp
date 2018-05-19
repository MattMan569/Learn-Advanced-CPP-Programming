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
	double height;
};

// Re-enable padding
#pragma pack(pop)

int main()
{
	Person someone = { "Matthew", 21, 1.85 };


	string fileName = "test.bin";

	/// Write binary file

	// ofstream outputFile;
	fstream outputFile;

	// Open the file for writing in binary
	// outputFile.open(fileName, ios::binary);
	outputFile.open(fileName, ios::binary | ios::out);

	if (outputFile.is_open())
	{
		outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));

		outputFile.close();
	}
	else
	{
		cout << "Could not create file: " << fileName << endl;
	}


	/// Read binary file

	// Create empty instance
	Person someoneElse = {};

	ifstream inputFile;

	// Open the file for reading in binary
	inputFile.open(fileName, ios::binary);

	if (inputFile.is_open())
	{
		// Read the binary file into the new Person instance
		inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));

		inputFile.close();
	}
	else
	{
		cout << "Could not read file: " << fileName << endl;
	}

	cout << someoneElse.name << ". " << someoneElse.age << ". " << someoneElse.height << endl;


	return 0;
}