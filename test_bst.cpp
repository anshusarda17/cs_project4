//
//  test_bst_detailed.cpp
//  CS 271 BST Project: Detailed Test File
//
//  Created by ChatGPT Assistance
//

#include <iostream>
#include "usecase.cpp"
#include <stdlib.h>
#include <math.h>
#include "bst.cpp"

using namespace std;

void test_empty()
{
    BST<string, int> bst;

    // Newly created BST should be empty.
    if (!bst.empty())
    {
        cout << "Error: New BST should be empty." << endl;
    }

    bst.insert("one", 1);

    // After insertion, BST should not be empty.
    if (bst.empty())
    {
        cout << "Error: BST should not be empty after insertion." << endl;
    }
}

void test_insert()
{
    BST<string, int> bst;

    // Test inserting in non-decreasing order
    for (int i = 1; i <= 5; i++)
    {
        bst.insert("data", i);
    }

    if (bst.to_string() != "1 2 3 4 5")
    {
        cout << "Error: Incorrect in-order traversal after incremental insertion." << endl;
    }

    bst = BST<string, int>(); // Resetting the tree

    // Test inserting in non-increasing order
    for (int i = 5; i > 0; i--)
    {
        bst.insert("data", i);
    }

    if (bst.to_string() != "1 2 3 4 5")
    {
        cout << "Error: Incorrect in-order traversal after decremental insertion." << endl;
    }
}

void test_get()
{
    BST<string, int> bst;
    bst.insert("one", 1);
    bst.insert("three", 3);
    bst.insert("two", 2);

    // Testing for existing keys
    if (bst.get(1) != "one" || bst.get(2) != "two" || bst.get(3) != "three")
    {
        cout << "Error: Get function is not returning correct values." << endl;
    }

    // Test for non-existing key. Assuming it returns an empty string for non-existing keys.
    if (!bst.get(4).empty())
    {
        cout << "Error: Get function should return an empty string for non-existing keys." << endl;
    }
}

void test_remove()
{
    BST<string, int> bst;
    bst.insert("one", 1);
    bst.insert("three", 3);
    bst.insert("two", 2);

    // Removing a middle node with two children
    bst.remove(2);

    if (bst.to_string() != "1 3")
    {
        cout << "Error: Incorrect in-order traversal after removing a middle node." << endl;
    }

    // Test removing a non-existent node
    bst.remove(5); // Assuming no error is thrown

    // Test removing the root node
    bst.remove(1);

    if (bst.to_string() != "3")
    {
        cout << "Error: Incorrect in-order traversal after removing the root." << endl;
    }
}

void test_min_max()
{
    BST<string, int> bst;

    bst.insert("five", 5);
    bst.insert("two", 2);
    bst.insert("eight", 8);

    // Testing minimum and maximum data and key
    if (bst.min_data() != "two" || bst.max_data() != "eight" ||
        bst.min_key() != 2 || bst.max_key() != 8)
    {
        cout << "Error: Min or Max functions are not working correctly." << endl;
    }

    // Testing min and max on an empty tree
    BST<string, int> emptyTree;
    // Assuming they return an empty string and -1 for the key on an empty tree.
    if (!emptyTree.min_data().empty() || !emptyTree.max_data().empty() ||
        emptyTree.min_key() != -1 || emptyTree.max_key() != -1)
    {
        cout << "Error: Min or Max functions should handle empty trees." << endl;
    }
}

void test_successor()
{
    BST<string, int> bst;

    for (int i = 1; i <= 10; i++)
    {
        bst.insert("data", i);
    }

    // Common case
    if (bst.successor(5) != 6)
    {
        cout << "Error: Successor function is not working correctly." << endl;
    }

    // Edge case: No successor
    if (bst.successor(10) != 0)
    { // Assuming 0 indicates no successor
        cout << "Error: Successor function is not working correctly for edge case." << endl;
    }

    // Edge case: Non-existing node
    if (bst.successor(20) != 0)
    { // Assuming 0 indicates no successor for non-existing node
        cout << "Error: Successor function should return 0 for non-existing nodes." << endl;
    }
}

void test_in_order()
{
    BST<string, int> bst;

    for (int i = 5; i > 0; i--)
    {
        bst.insert("data", i);
    }

    if (bst.in_order() != "1 2 3 4 5")
    {
        cout << "Error: In-order traversal is not working correctly." << endl;
    }
}

void test_binhex()
{
    BST<string, int> bst;
    bst.insert("a", 0b1010);
    bst.insert("f", 0b1111);

    if (bst.binhex() != "a f")
    {
        cout << "Error: binhex function is not working correctly." << endl;
    }
}

void test_trim()
{
    BST<string, int> bst;

    for (int i = 1; i <= 10; i++)
    {
        bst.insert("data", i);
    }

    bst.trim(3, 8);

    if (bst.to_string() != "3 4 5 6 7 8")
    {
        cout << "Error: Trim function is not working correctly." << endl;
    }

    // Edge case: Trim with reversed boundaries
    bst.trim(8, 3); // Assuming this doesn't change the tree
    if (bst.to_string() != "3 4 5 6 7 8")
    {
        cout << "Error: Trim function should handle reversed boundaries correctly." << endl;
    }
}

int main()
{
    test_empty();
    test_insert();
    test_get();
    test_remove();
    test_min_max();
    test_successor();
    test_in_order();
    test_binhex();
    test_trim();

    cout << "Detailed testing completed." << endl;

    return 0;
}
