#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "bst.cpp"
using namespace std;

template <typename D, typename K>
BST<D, K> *create_bst(const string &fname)
{
    BST<D, K> *bst = new BST<D, K>();

    ifstream file(fname);
    string line, bin, hex;

    while (getline(file, line))
    {
        stringstream ss(line);
        getline(ss, hex, ',');
        getline(ss, bin);
        bst->insert(hex, bin);
    }

    return bst;
}
template <typename D, typename K>
string convert(BST<D, K> *bst, string bin)
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

/*
template <typename D, typename K>
string convert(BST<D, K> *bst, string bin)
{
    string hex;
    int i = 0;
    for (size_t i = 0; i < bin.length(); i += 4)
    {
        string segment = bin.substr(i, 4);
        string hexSegment = bst->get(segment);

        hex += hexSegment;
    }

    return hex;
}

*/

/*

int main()
{
    string filename = "binhex.txt";
    auto *bst = create_bst<string, string>(filename); // Specify Data and Key types

    string binaryInput;
    cout << "Enter binary representation for conversion: ";
    cin >> binaryInput;

    string hexOutput = convert(bst, binaryInput);
    cout << "Hexadecimal representation of " << binaryInput << " is " << hexOutput << endl;

    delete bst; // Clean up the BST
    return 0;
}

*/
