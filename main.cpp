#include <iostream>
#include "usecase.cpp"
#include <string>
#include <ostream>
using namespace std;

int main()
{
    string filename = "binhex.txt";
    BST<string, string> *bst = create_bst<string, string>(filename); // Specify Data and Key types

    cout << "USECASE IMPLEMENTATION: " << endl;
    string binaryInput;
    cout << "Enter binary representation for conversion: ";
    cin >> binaryInput;

    string hexOutput = convert(bst, binaryInput);
    cout << "Hexadecimal representation of " << binaryInput << " is " << hexOutput << endl;

    delete bst; // Clean up the BST

    return 0;
}