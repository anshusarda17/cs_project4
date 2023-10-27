#include <iostream>
#include "bst.h"
#include <string>
#include <queue>
using namespace std;

//====================================
// Node(const Data &d, const Key &k, Node *p): Constructor for a Node object.
// Parameters:
//    - const Data &d: The data to be stored in the node.
//    - const Key &k: The key associated with the data.
//    - Node<Data, Key>* p: Pointer to the parent node (default is nullptr).
// Purpose:
//    - Initializes a new node with given data, key, and parent.
//    - Sets left and right child pointers to nullptr.
//====================================
template <typename Data, typename Key>
Node<Data, Key>::Node(const Data &d, const Key &k, Node *p)
    : data(d), key(k), left(nullptr), right(nullptr), parent(p) {}

//====================================
// BST(): Constructor for a BST object.
// Purpose:
//    - Initializes a new empty Binary Search Tree.
//    - Sets the root pointer to nullptr.
//====================================
template <typename Data, typename Key>
BST<Data, Key>::BST() : root(nullptr) {}

template <typename Data, typename Key>
BST<Data, Key>::~BST()
{
    // destructor
}

//====================================
// empty() : Checks if the BST is empty.
// Pre-conditions: None.
// Post-conditions: Returns true if BST is empty, false otherwise.
// Purpose: To determine if the BST currently contains any nodes.
// Returns: bool - true if BST is empty, false otherwise.
//====================================
template <typename Data, typename Key>
bool BST<Data, Key>::empty() const
{

    if (root == nullptr)
    {
        /*
        cout << "the bst is empty "
             << " \n";
        return true;
        */
        return true;
    }
    else
    {
        /*
        cout << "the bst is NOT empty "
             << " \n";
        return false;
        */
        return false;
    }
}

//====================================
// insert(const Data &d, const Key &k) : Inserts a new node with given data and key into the BST.
// Parameters:
//    const Data &d - the data of the new node.
//    const Key &k - the key of the new node.
// Pre-conditions: The BST may or may not contain other nodes. No node with key k exists in the BST.
// Post-conditions: A new node with data d and key k is added to the BST.
// Purpose: To add a new node to the BST.
// Returns: void.
//====================================
template <typename Data, typename Key>

void BST<Data, Key>::insert(const Data &d, const Key &k)
{

    Node<Data, Key> *newNode = new Node<Data, Key>(d, k);

    if (root == nullptr)
    { //if BST is empty

        root = newNode;
        return;
    }
    Node<Data, Key> *current = root; //start from root
    Node<Data, Key> *parentt = nullptr;

    while (current != nullptr)
    {

        parentt = current;
        if (k < current->key)
        {
            current = current->left;
        }
        else if (k > current->key)
        {
            current = current->right;
        }
        else
        {
            // duplicate key
            delete newNode;
            return;
        }
    }
    newNode->parent = parentt;
    if (k < parentt->key)
    {
        parentt->left = newNode;
    }
    else
    {
        parentt->right = newNode;
    }
}
//====================================
// get(const Key &k) : Retrieves the data associated with a specific key.
// Parameters:
//    const Key &k - the key of the node whose data is to be retrieved.
// Pre-conditions: The BST may or may not contain a node with the key k.
// Post-conditions: If a node with key k exists, its data is returned; otherwise, returns an empty or default value.
// Purpose: To find and return the data of a node with a specific key in the BST.
// Returns: Data - the data of the node with key k if it exists, otherwise an empty or default value.
//====================================
template <typename Data, typename Key>
Data BST<Data, Key>::get(const Key &k)
{

    Node<Data, Key> *current = root; //start from root
    while (current != nullptr)
    {

        //checking each node from root if key matches
        if (k == current->key)
        {
            return current->data;
        }
        else if (k < current->key)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return "";
}

//====================================
// findMin(Node<Data, Key>* node) : Finds the node with the minimum key in the BST.
// Parameters:
//    Node<Data, Key>* node - the node from where to start the search.
// Purpose: To find the node with the minimum key value in the subtree rooted at the given node.
// Pre-conditions:
//    - The node provided as an argument should be part of a valid BST.
//    - The function assumes that the BST follows the standard BST property where
//      each node's left child key is less than the node's key and the right child key is greater.
//    - The function can handle nullptr inputs, which implies an empty subtree.
// Post-conditions:
//    - If the subtree rooted at 'node' is not empty, returns the node with the minimum key in that subtree.
//    - If 'node' is nullptr or the subtree is empty, returns nullptr.
//    - Does not modify the structure or contents of the BST.
// Returns: Node<Data, Key>* - a pointer to the node with the minimum key, or nullptr if the subtree is empty.
//====================================
template <typename Data, typename Key>
Node<Data, Key> *BST<Data, Key>::findMin(Node<Data, Key> *node)
{

    if (node == nullptr)
    {
        return nullptr;
    }
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

//

//====================================
// remove(const K &key) : Removes the node with the specified key from the BST.
// Parameters:
//    const K &key - the key of the node to be removed.
// Pre-conditions: The BST may contain a node with the specified key.
// Post-conditions: If a node with the key exists, it is removed from the BST.
// Purpose: To delete a node from the BST based on its key.
// Returns: void.
//====================================
template <typename D, typename K>
void BST<D, K>::remove(const K &key)
{
    root = removeHelper(root, key);
}

//====================================
// removeHelper(node, key): Helper function for removing a node with a specific key.
// Parameters:
//    - Node<D, K>* node: Pointer to the current node being checked.
//    - const K &key: The key of the node to be removed.
// Purpose:
//    - To recursively find and remove a node with the given key in the BST.
//    - Handles different cases of node removal, including leaf nodes and nodes with one or two children.
// Returns:
//    - Node<D, K>*: Pointer to the node that replaces the removed node (can be nullptr).
// Description:
//====================================
template <typename D, typename K>
Node<D, K> *BST<D, K>::removeHelper(Node<D, K> *node, const K &key)
{
    /*
    // temporary fix --
    if (node == root)
    {
        root = removeHelper(root, key);
    }
    else
    {
        node = removeHelper(node, key);
    }
    //
    */

    if (node == nullptr)
    {
        return nullptr;
    }

    if (key < node->key)
    {
        node->left = removeHelper(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = removeHelper(node->right, key);
    }
    else
    {
        // Node with the key is found, perform removal

        // Case 1: Node has only a single child or no child
        if (node->left == nullptr)
        {
            Node<D, K> *temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr)
        {
            Node<D, K> *temp = node->left;
            delete node;
            return temp;
        }

        // Case 2: Node has two children
        Node<D, K> *successor = findMin(node->right); // Find the in-order successor
        node->key = successor->key;
        node->data = successor->data;
        node->right = removeHelper(node->right, successor->key);
    }
    return node;
}

//====================================
// max_data() : Finds the data associated with the maximum key in the BST.
// Parameters: None
// Purpose: To retrieve the data associated with the node that has the highest key value in the BST.
// Pre-conditions:
//    - The BST is properly initialized.
//    - The BST may be empty or contain one or more nodes.
// Post-conditions:
//    - The structure of the BST remains unchanged.
//    - If the BST is not empty, returns the data of the node with the maximum key.
//    - If the BST is empty, returns a default value (dependent on the data type, such as an empty string for std::string).
// Returns: D - The data type of the BST, representing the data of the node with the maximum key, or a default value if the BST is empty.
//====================================
template <typename D, typename K>
D BST<D, K>::max_data()
{
    // Start at the root
    Node<D, K> *current = root;

    // Traverse to the rightmost node
    while (current && current->right)
    {
        current = current->right;
    }

    // Return the data of the rightmost node
    if (current)
    {
        return current->data;
    }
    else
    {
        return "";
    }
}

//====================================
// max_key() : Retrieves the maximum key value in the BST.
// Parameters: None
// Purpose: To find and return the highest key value present in the BST.
// Pre-conditions:
//    - The BST is properly initialized.
//    - The BST may be empty or contain one or more nodes.
// Post-conditions:
//    - The structure of the BST remains unchanged.
//    - If the BST is not empty, returns the maximum key.
//    - If the BST is empty, returns a default value (dependent on the key type, such as 0 for integer types).
// Returns: K - The key type of the BST, representing the maximum key value, or a default value if the BST is empty.
//====================================
template <typename D, typename K>
K BST<D, K>::max_key()
{
    // Start at the root
    Node<D, K> *current = root;

    // Traverse to the rightmost node
    while (current && current->right)
    {
        current = current->right;
    }

    // Return the key of the rightmost node
    if (current)
    {
        return current->key;
    }
    else
    {
        return 0;
    }
}

//====================================
// min_data() : Retrieves the minimum data value in the BST.
// Parameters: None
// Purpose: To find and return the data with the lowest key value present in the BST.
// Pre-conditions:
//    - The BST is properly initialized.
//    - The BST may be empty or contain one or more nodes.
// Post-conditions:
//    - The structure of the BST remains unchanged.
//    - If the BST is not empty, returns the data associated with the minimum key.
//    - If the BST is empty, returns a default value (dependent on the data type, such as 0 for integer types, empty string for std::string, etc.).
// Returns: D - The data type of the BST, representing the data associated with the minimum key, or a default value if the BST is empty.
//====================================
template <typename D, typename K>
D BST<D, K>::min_data()
{
    // Start at the root
    Node<D, K> *current = root;

    // Traverse to the leftmost node
    while (current && current->left)
    {
        current = current->left;
    }

    // Return the data of the leftmost node
    if (current)
    {
        return current->data;
    }
    else
    {
        return "";
    }
}

//====================================
// min_key() : Retrieves the minimum key in the BST.
// Parameters: None
// Purpose: To find and return the lowest key value present in the BST.
// Pre-conditions:
//    - The BST is properly initialized.
//    - The BST may be empty or contain one or more nodes.
// Post-conditions:
//    - The structure of the BST remains unchanged.
//    - If the BST is not empty, returns the minimum key.
//    - If the BST is empty, returns a default value (dependent on the key type, such as 0 for integer types, empty string for std::string, etc.).
// Returns: K - The key type of the BST, representing the lowest key, or a default value if the BST is empty.
//====================================
template <typename D, typename K>
K BST<D, K>::min_key()
{
    // Start at the root
    Node<D, K> *current = root;

    // Traverse to the leftmost node
    while (current && current->left)
    {
        current = current->left;
    }

    // Return the key of the leftmost node
    if (current)
    {
        return current->key;
    }
    else
    {
        return -1;
    }
}

//====================================
// successor(k) : Finds the successor of a given key in the BST.
// Parameters: K k - The key for which the successor is to be found.
// Purpose: To find the smallest key in the BST that is larger than the given key k.
// Pre-conditions:
//    - The BST is properly initialized and may contain zero or more nodes.
//    - The key k is of the same type as the BST keys.
// Post-conditions:
//    - The structure of the BST remains unchanged.
//    - Returns the successor key if k is found in the BST.
//    - Returns a default value (e.g., 0 for integer types) if k is not in the BST.
// Returns: K - The successor key of k if it exists, otherwise a default value.
//====================================
template <typename D, typename K>
K BST<D, K>::successor(const K &key)
{
    // Start at the root
    Node<D, K> *current = root;
    Node<D, K> *successor = nullptr;

    while (current)
    {
        if (key < current->key)
        {
            successor = current;
            current = current->left;
        }
        else if (key > current->key)
        {
            current = current->right;
        }

        else
        {
            if (current->right)
            {
                Node<D, K> *minNode = findMin(current->right);
                return minNode->key;
            }
            else
            {
                break; //key found but no right tree
            }
        }
    }

    if (successor)
    {
        return successor->key;
    }
    else
    {
        return 0;
    }
}

//====================================
// trim(low, high) : Trims the BST to contain only keys within the [low, high] interval.
// Parameters:
//    - K low - The lower bound of the interval.
//    - K high - The upper bound of the interval.
// Purpose: To modify the BST such that it only contains nodes whose keys are within the given interval.
// Pre-conditions:
//    - The BST is properly initialized.
// Post-conditions:
//    - Nodes with keys outside the [low, high] interval are removed.
//    - The relative structure of the remaining elements is unchanged.
//    - BST might become empty if no keys are within the interval.
// Returns: None
//====================================
template <typename D, typename K>
void BST<D, K>::trim(const K &low, const K &high)
{
    Node<D, K> *current = root;
    root = trimHelper(current, low, high);
}

//====================================
// trimHelper(node, low, high) : Helper function for recursively trimming the BST.
// Parameters:
//    - Node<D, K>* node: Pointer to the current node being examined.
//    - const K &low: The lower bound of the interval.
//    - const K &high: The upper bound of the interval.
// Purpose:
//    - To recursively trim the BST so that it only retains nodes with keys within the [low, high] interval.
//    - This function is designed to assist the public trim method.
// Returns:
//    - Node<D, K>*: The pointer to the current node after trimming, or nullptr if the node is out of bounds.
//====================================
template <typename D, typename K>
Node<D, K> *BST<D, K>::trimHelper(Node<D, K> *node, const K &low, const K &high)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->key < low)
    {
        // Key is smaller than the low limit, remove the left subtree
        return trimHelper(node->right, low, high);
    }
    else if (node->key > high)
    {
        // Key is larger than the high limit, remove the right subtree
        return trimHelper(node->left, low, high);
    }
    else
    {
        // Key is within the range, recursively trim left and right subtrees
        node->left = trimHelper(node->left, low, high);
        node->right = trimHelper(node->right, low, high);
        return node;
    }
}

//====================================
// in_order() : Returns a string of the keys in BST in ascending order.
// Parameters: None
// Purpose: To get a space-separated string of the keys in the BST, sorted in ascending order.
// Pre-conditions:
//    - The BST is properly initialized.
// Post-conditions:
//    - The structure of the BST remains unchanged.
//    - Returns a string representation of the BST keys in sorted order.
// Returns: std::string - A string containing the sorted keys, separated by spaces.
//====================================
template <typename D, typename K>
string BST<D, K>::in_order()
{
    bool first = true;
    return inOrderHelper(root, first);
}

//====================================
// inOrderHelper(node, first): Helper function for generating an in-order traversal string of keys.
// Parameters:
//    - Node<D, K>* node: Pointer to the current node in the BST.
//    - bool &first: Reference to a boolean indicating if the current node is the first in the traversal.
// Purpose:
//    - To perform an in-order traversal of the BST and create a string representation of the keys.
//    - Assists in creating a string for the public in_order() method.
// Returns:
//    - string: In-order concatenated string of keys from the BST.
//====================================
template <typename D, typename K>
string BST<D, K>::inOrderHelper(Node<D, K> *node, bool &first)
{
    if (node == nullptr)
    {
        return "";
    }

    string result;

    // Traverse the left subtree (in-order)
    result += inOrderHelper(node->left, first);

    // Visit the current node
    // to not add a space at the end,
    if (first)
    {
        first = false;
    }
    else
    {
        result += " ";
    }

    result += std::to_string(node->key);

    // Traverse the right subtree (in-order)
    result += inOrderHelper(node->right, first);

    return result;
}

//====================================
// to_string(): Function to convert the keys of all nodes in the BST to a string.
// Purpose:
//    - To create a string representation of all keys in the BST.
//    - This string is not in any specific order and is based on a breadth-first traversal.
// Returns:
//    - string: A string of keys separated by spaces.
//====================================
template <typename D, typename K>
string BST<D, K>::to_string()
{
    if (root == nullptr)
    {
        return " "; // Return an empty string if the tree is empty
    }

    string result;
    queue<Node<D, K> *> nodes;
    nodes.push(root);

    while (!nodes.empty())
    {
        Node<D, K> *current = nodes.front();
        nodes.pop();
        result += std::to_string(current->key) + " ";

        if (current->left)
        {
            nodes.push(current->left);
        }
        if (current->right)
        {
            nodes.push(current->right);
        }
    }

    // Remove the trailing space and return the result
    result.pop_back();
    return result;
}
