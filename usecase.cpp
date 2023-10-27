#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
// #include "bst.cpp"
using namespace std;

template <typename D, typename K>
BST<D, K> *create_bst(const string &fname)
{
    auto *bst = new BST<D, K>();

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
    string hex;

    for (size_t i = 0; i < bin.length(); i += 4)
    {
        string segment = bin.substr(i, 4);
        string hexSegment = bst->get(segment);

        // Check if the segment is found in the BST
        if (hexSegment.empty())
        {
            // Handle the case where the segment is not found
            // You could return an error value or throw an exception.
        }

        hex += hexSegment;
    }

    return hex;
}

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
