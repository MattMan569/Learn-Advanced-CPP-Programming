// TwoDimensionalVectors.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>

using namespace std;


int main()
{
	// 3 x 4 vector with values initialized to 7
	// Vector containing 3 other vectors, each contains 4 values set to 7
	vector< vector<int> > grid(3, vector<int>(4, 7));

	for (int row = 0; row < grid.size(); row++)
	{
		for (int col = 0; col < grid[row].size(); col++)
		{
			cout << grid[row][col] << " ";
		}
		cout << endl;
	}
	cout << endl;

	// Possible to use ragged arrays
	grid[1].push_back(8);

	for (int row = 0; row < grid.size(); row++)
	{
		for (int col = 0; col < grid[row].size(); col++)
		{
			cout << grid[row][col] << " ";
		}
		cout << endl;
	}
	cout << endl;


    return 0;
}

