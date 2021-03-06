// UsingFunctionPointers.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


bool match(string test)
{
	// Return true if the string is "two"
	// return test == "two";

	// Return true if the string is three characters long
	return test.size() == 3;
}


// Implement our own version of count_if
int countStrings(vector<string> & texts, bool(*match)(string test))
{
	int tally = 0;

	for (int i = 0; i < texts.size(); i++)
	{
		if (match(texts[i]))
		{
			tally++;
		}
	}

	return tally;
}


int main()
{
	vector<string> texts;

	texts.push_back("one");
	texts.push_back("two");
	texts.push_back("three");
	texts.push_back("two");
	texts.push_back("four");
	texts.push_back("two");
	texts.push_back("three");


	cout << boolalpha << match("one") << noboolalpha << endl;

	// Iterator from the beginning to the end of texts
	// and match against the function "match"
	// given via a function pointer
	cout << count_if(texts.begin(), texts.end(), match) << endl;


	cout << countStrings(texts, match) << endl;


    return 0;
}

