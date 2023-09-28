
#include <iostream>
#include "json/json.h"
#include <fstream>

using namespace std;


int main()
{
	cout << "Making new empty inventory data... \n";
	//Code for creating data goes here
	
	//Json::Value jsonArray;
    
    Json::Value value;
    for (auto const& id : value.getMemberNames()) {
        std::cout << id << std::endl;
    }
    
    /*
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
		cerr << "Failed to open file for writing. \n";
		return 1;
	}
	outFile << jsonString;
	outFile.close();

	cout << "Json data saved to 'inventory.json' \n";
    */
	return 0;

}