#include <iostream>
#include <fstream>
#include <sstream>
#include "bst.cpp"
using namespace std;

BST<string, string> *create_bst(const string &fname)
{
    auto *bst = new BST<string, string>();

    ifstream file(fname);
    string line, bin, hex;

    while (getline(file, line))
    {
        stringstream ss(line);
        getline(ss, bin, ',');
        getline(ss, hex);
        bst->insert(hex, bin);
    }

    return bst;
}

string convert(BST<string, string> *bst, string bin)
{
    // Pad the binary string to make its length a multiple of 4
    int pad = 4 - (bin.length() % 4);
    if (pad != 4)
    {
        bin = string(pad, '0') + bin;
    }

    string hex;
    for (size_t i = 0; i < bin.length(); i += 4)
    {
        string segment = bin.substr(i, 4);
        hex += bst->get(segment);
    }
    return hex;
}

int main()
{
    string filename = "binhex.txt";
    auto *bst = create_bst(filename);

    string binaryInput;
    cout << "Enter binary representation for conversion: ";
    cin >> binaryInput;

    string hexOutput = convert(bst, binaryInput);
    cout << "Hexadecimal representation of " << binaryInput << " is " << hexOutput << endl;

    delete bst; // Clean up the BST
    return 0;
}
