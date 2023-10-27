#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "bst.cpp"
using namespace std;


//=====================================================
// Purpose: Create a BST from a CSV file with hex-bin pairs
// Parameters: 
//    - const string &fname: Path to the CSV file
// Returns: Pointer to the newly created BST
// Pre-conditions: The file specified by fname exists and is well-formatted
// Post-conditions: A BST is created and returned, containing all hex-bin pairs from the file
//=====================================================

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

//=====================================================
// Purpose: Convert binary string to hexadecimal using BST
// Parameters:
//    - BST<D, K> *bst: Pointer to the BST with binary-hexadecimal pairs
//    - string bin: Binary string for conversion
// Returns: Hexadecimal string representing the conversion of the binary input
// Pre-conditions: The BST pointed by bst is constructed with binary-hexadecimal pairs
// Post-conditions: Binary string is converted to hexadecimal using BST mappings
//=====================================================

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
