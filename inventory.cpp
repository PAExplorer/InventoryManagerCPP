// Sep 2023 Jeff Dickson

#include <iostream>
#include "json/json.h"
#include <fstream>

using namespace std;

string x = "help";
bool y = true;

int modEntry();
int findISBN();
int loadData();
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
		else if (x == "lookup")
		{
			findISBN();
		}
		else
		{
			cout << "Unknown command please write help for a command list. \n";
		}
	}
return 0;
}

int modEntry(Json::Value inBook)
{
	cout << "TEST FOR PASSING PARAM: \n";
	cout << inBook["ISBN"].asInt() << endl;
	return 1;
}

int findISBN()
{
	Json::Value jsonArray;

	fstream inFile("inventory.json");
	if(!inFile.is_open())
	{
		cout << "Failed to open inventory file... \n";
		return 1;
	}
	Json::Reader reader;
	if (!reader.parse(inFile, jsonArray))
	{
		cout << "Failed to parse JSON data from the file... \n";
		inFile.close();
		return 1;
	}
	
	int nTargetISBN = 42;
	Json::Value foundBook;
	
	cout << "Please enter an ISBN to search for: \n";
	cin >> nTargetISBN;

	for (const Json::Value& bookObject : jsonArray)
	{
		int nIsbn = bookObject["ISBN"].asInt();
		if (nIsbn == nTargetISBN)
		{
			foundBook = bookObject;
			break;
		}
	}

	if (!foundBook.empty())
	{
		cout << endl;
		cout << "Book found: \n";
		cout << "SKU: " << foundBook["SKU"].asInt() << endl;
		cout << "Title: " << foundBook["Title"].asString() << endl;
		cout << "ISBN: " << foundBook["ISBN"].asInt() << endl;
		cout << "Stock: " << foundBook["Stock"].asInt() << endl;
		cout << endl;
		modEntry(foundBook);
	} else 
	{
		cout << "Book with the ISBN " << nTargetISBN << " not found. \n";
	}


	inFile.close();
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
		bookObject["Stock"] = 0;

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
