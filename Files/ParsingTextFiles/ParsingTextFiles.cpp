// ParsingTextFiles.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	string filename = "stats.txt";

	ifstream input;

	input.open(filename);

	if (!input.is_open())
	{
		return 1;
	}

	while (input)
	{
		string line;

		// Using ":" as delimitter
		getline(input, line, ':');

		int population;
		input >> population;

		// Discard new line character
		// input.get();
		input >> ws; // C++ 11 : read into ws "white space"

		// Check if previous reads have reached eof
		if (!input)
		{
			break;
		}

		cout << "'" << line << "'" << " -- '" << population << "'" << endl;
	}

	input.close();

    return 0;
}

