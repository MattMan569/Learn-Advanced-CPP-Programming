#include <iostream>
#include <map>
#include <string>

using namespace std;


int main()
{
	// String key, int value
	map<string, int> ages;

	ages["Raj"] = 20;
	ages["Mike"] = 40;
	ages["Vicky"] = 30;


	// pair<string, int> addToMap("Peter", 100);
	// ages.insert(addToMap);

	ages.insert(pair<string, int>("Peter", 100));
	ages.insert(make_pair("Xavier", 12));


	// Keys must be unique or they will overwrite previous values
	// ages["Mike"] = 70;

	// Keys that do not exist are added to the map
	// cout << ages["Sue"] << endl;


	cout << ages["Raj"] << endl;


	// Check if value key is in the map
	if (ages.find("Vicky1234") != ages.end())
	{
		cout << "Found Vicky!" << endl;
	}
	else
	{
		cout << "Key not found" << endl;
	}

	cout << endl;

	for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
	{
		cout << it->first << ": " << it->second << endl;
	}

	cout << endl;

	for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
	{
		pair<string, int> age = *it;
		cout << age.first << ": " << age.second << endl;
	}

	cout << endl;


	return 0;
}