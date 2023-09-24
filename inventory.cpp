// Sep 2023 Jeff Dickson

#include <iostream>
#include "json/json.h"
using namespace std;

string x = "help";
bool y = true;

int makeEmptyData();

int main()
{
	cout << "Welcome to the inventory manager \n";
	while(y == true)
	{
		cout << "Please write a command. \n";
		cin >> x;
		if(x == "quit")
		{
			cout << "Exiting \n";
			y = false;
		}
		else if (x == "new")
		{
			makeEmptyData();
		}
		else if (x == "help")
		{
			cout << "quit ~ quits the program \nnew ~ creates a new empty inventory database \nadd ~ adds a new entry to the database \nremove ~ removes and entry from the database \n";
		}
		else
		{
			cout << "Unknown command please write help for a command list. \n";
		}
	}
return 0;
}

int makeEmptyData()
{
	cout << "Making new empty inventory data... \n";
	return 0;
}
