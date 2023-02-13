#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include "Store.h"

using namespace std;


class Store {
public:
	void PrintMenu() const;
	string nCharString(int size, char symb);
	int i;


private:
	size_t n;
	char c;
	string charStr;
};

void Store::PrintMenu() const { // Displays a default menu to the user when prompting for user input
	cout << "Select an option by entering 1, 2, 3, or 4. " << endl << endl;
	cout << "Option 1: Enter item you wish to search for." << endl;
	cout << "Option 2: Print list of items with frequncy of purchases." << endl;
	cout << "Option 3: Print list of items with frequency of purchases as histrogram." << endl;
	cout << "Option 4: Exit the program." << endl;
}

string Store::nCharString(int size, char symb) { // Function to allow us to print any character 'n' amount of times
	n = size;
	c = symb;
	charStr = "";
	for (i = 0; i < n; ++i) {
		charStr += c;
	}
	return charStr;
}
