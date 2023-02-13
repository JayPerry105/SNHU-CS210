#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include "Store.h"

using namespace std;


int main() {
    ifstream inputFile;
    ofstream outputFile;
    string productName;
    int productOccur = 0;
    string item;
    map<string, int> groceryCount;
    string produceName;
    list<string> allProducts;
    list<string>::iterator iter;
    int menuChoice;
    string searchItem;
    Store myStore;

    cout << "Opening file input_file.txt" << endl;

    inputFile.open("input_file.txt");  // Opens file to read product sales from
    if (!inputFile.is_open()) {
        cout << "Could not open file input_file.txt." << endl; // Lets user know if file was unable to open properly
        return 1;
    }

    cout << "Opening file frequency.dat." << endl;

    outputFile.open("frequency.dat"); // Opens file to write product sales to
    if (!outputFile.is_open()) {
        cout << "Could not open file frequency.dat." << endl; // Lets user know if file was unable to open properly
        return 1;
    }




    inputFile >> productName; // Sets variable to current product name from input file list

    while (!inputFile.fail()) { // Checks to see that we are not at end of file
        if (!groceryCount.count(productName)) { // Checks if product name is already in map
            groceryCount.emplace(productName, 1); // If product is not yet in map, add it to map and give it a value of 1
            allProducts.push_back(productName);  // Adds product name to a list
        }
        else {
            groceryCount.at(productName) += 1; //  If product is already in list, increment value by 1
        }
        inputFile >> productName; // Assign next product name to variable
    }

    // Iterates through allProducts list and writes items into data file along with count of times purchased
    for (iter = allProducts.begin(); iter != allProducts.end(); ++iter) {
        item = *iter;
        outputFile << item << " " << groceryCount.at(item) << endl;
    }




    cout << "Closing input_file.txt" << endl;
    inputFile.close(); // Closes input file

    cout << "Closing output file frequency.dat." << endl;
    outputFile.close(); // Closes output file

    cout << endl;

    cout << myStore.nCharString(26, '*') << endl;
    cout << "  The Corner Grocer App" << endl;
    cout << myStore.nCharString(26, '*') << endl << endl;
    // Displays app title graphic to user

    myStore.PrintMenu();
    cin >> menuChoice;

    while (menuChoice != 4) { // Checks to see if user entered '4' to exit program
        if (menuChoice == 1) {
            cout << "Please enter an item." << endl;
            cin >> searchItem; // Sets variable to product name customer wants to look up
            if (groceryCount.count(searchItem)) { //  Checks if desired product has been purchased
                cout << groceryCount.at(searchItem) << endl << endl;
                myStore.PrintMenu();
                cin >> menuChoice;
            }
            else { // Prompts user for another item input if original input does not match any map item
                cout << "Invalid entry, please try again" << endl;
            }
        }
        else if (menuChoice == 2) {
            for (iter = allProducts.begin(); iter != allProducts.end(); ++iter) {
                item = *iter;
                cout << item << " " << groceryCount.at(item) << endl;
            } // Iterates through map and prints each item with number of times purchased

            cout << endl;
            myStore.PrintMenu();
            cin >> menuChoice;
        }
        else if (menuChoice == 3) {
            for (iter = allProducts.begin(); iter != allProducts.end(); ++iter) {
                item = *iter;
                cout << item << " " << myStore.nCharString(groceryCount.at(item), '*') << endl;
            } // iterates through map and prints 'n' number of '*'s to represent number of items purchased

            cout << endl;
            myStore.PrintMenu();
            cin >> menuChoice;
        }
        else { // Prompts user for another input since it was not 1, 2, 3, or 4
            cout << "Invalid entry, try again please." << endl;
            myStore.PrintMenu();
            cin >> menuChoice;
        }
    }

    cout << "Thank you for using the Corner Grocer App!" << endl;

    return 0;
}
