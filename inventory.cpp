// Sep 2023 Jeff Dickson

#include <iostream>
#include "json/json.h"
#include <fstream>

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
	//Code for creating data goes here
	
	Json::Value jsonArray;

	for (int i = 1; i <= 100; ++i)
	{
		Json::Value bookObject;
		bookObject["SKU"] = i;
		bookObject["Title"] = "Unspecified Book " + std::to_string(i);
		bookObject["ISBN"] = 5000 + i;

		jsonArray.append(bookObject);
	}
	//Serialize the JSON array to a string
	
	Json::StreamWriterBuilder writer;
	string jsonString = Json::writeString(writer, jsonArray);
	//Save the Json string to the file
	
	fstream outFile("inventory.json");
	if(!outFile.is_open())
	{
		string r  = "n";
		cout << "Empty file does not exist, create a new file? y/n \n";
		cin >> r;
		if(r == "n")
		{
			return 1;
		}
		if(r == "y")
		{
			fstream newFile;
			newFile.open("inventory.json",ios::out);
			if(!newFile)
			{
				cout << "Error in creating new file, try making one manually? \n";
				return 1;
			}
			cout << "File created successfully. \n";
			makeEmptyData();
			return 0;
		}
	}
	outFile << jsonString;
	outFile.close();

	cout << "Json data saved to 'inventory.json' \n";

	return 0;

}
