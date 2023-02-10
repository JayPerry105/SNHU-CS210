#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include "Store.h"

using namespace std;

string nCharString(size_t n, char c) {
    int i;
    string charStr;

    for (i = 0; i < n; ++i) {
        charStr += c;
    }
    return charStr;
}

void printMenu() {
    cout << "Select an option by entering 1, 2, 3, or 4. " << endl << endl;
    cout << "Option 1: Enter item you wish to search for." << endl;
    cout << "Option 2: Print list of items with frequncy of purchases." << endl;
    cout << "Option 3: Print list of items with frequency of purchases as histrogram." << endl;
    cout << "Option 4: Exit the program." << endl;
}


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

    cout << "Opening file input_file.txt" << endl;

    inputFile.open("input_file.txt");
    if (!inputFile.is_open()) {
        cout << "Could not open file input_file.txt." << endl;
        return 1;
    }

    cout << "Opening file frequency.dat." << endl;

    outputFile.open("frequency.dat");
    if (!outputFile.is_open()) {
        cout << "Could not open file frequency.dat." << endl;
        return 1;
    }




    inputFile >> productName;

    while (!inputFile.fail()) {
        if (!groceryCount.count(productName)) {
            groceryCount.emplace(productName, 1);
            allProducts.push_back(productName);
        }
        else {
            groceryCount.at(productName) += 1;
        }
        inputFile >> productName;
    }

    for (iter = allProducts.begin(); iter != allProducts.end(); ++iter) {
        item = *iter;
        outputFile << item << " " << groceryCount.at(item) << endl;
    }




    cout << "Closing input_file.txt" << endl;
    inputFile.close();

    cout << "Closing output file frequency.dat." << endl;
    outputFile.close();

    cout << endl;

    cout << nCharString(26, '*') << endl;
    cout << "  The Corner Grocer App" << endl;
    cout << nCharString(26, '*') << endl << endl;

    printMenu();
    cin >> menuChoice;

    while (menuChoice != 4) {
        if (menuChoice == 1) {
            cout << "Please enter an item." << endl;
            cin >> searchItem;
            if (groceryCount.count(searchItem)) {
                cout << groceryCount.at(searchItem) << endl << endl;
                printMenu();
                cin >> menuChoice;
            }
            else {
                cout << "Invalid entry, please try again" << endl;
            }
        }
        else if (menuChoice == 2) {
            for (iter = allProducts.begin(); iter != allProducts.end(); ++iter) {
                item = *iter;
                cout << item << " " << groceryCount.at(item) << endl;
            }
            cout << endl;
            printMenu();
            cin >> menuChoice;
        }
        else if (menuChoice == 3){
            for (iter = allProducts.begin(); iter != allProducts.end(); ++iter) {
                item = *iter;
                cout << item << " " << nCharString(groceryCount.at(item), '*') << endl;
            }
            cout << endl;
            printMenu();
            cin >> menuChoice;
        }
        else {
            cout << "Invalid entry, try again please." << endl;
        }
    }

    cout << "Thank you for using the Corner Grocer App!" << endl;

    return 0;
}
