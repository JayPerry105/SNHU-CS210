#include <iostream>
#include <fstream>
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


int main() {
    ifstream inputFile;
    ofstream outputFile;
    string productName;
    int productOccur = 0;
    string item;
    
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
        outputFile << productName << endl;
        cout << productName << endl;
        inputFile >> productName;
        //outputFile << productName << endl;
    }

    cout << "Closing input_file.txt" << endl;
    inputFile.close();

    inputFile.open("input_file.txt");
    cin >> item;

    inputFile >> productName;
    while (!inputFile.fail()) {
        if (productName == item) {
            productOccur += 1;
        }
        cout << productName << endl;
        inputFile >> productName;
    }

    cout << productOccur << endl;

    cout << "Closing input_file.txt" << endl;
    inputFile.close();


    return 0;
}
