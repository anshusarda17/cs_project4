#include <iostream>
#include "bst.h"
#include <string>
using namespace std;

template <typename Data, typename Key>
Node<Data, Key>::Node(const Data &d, const Key &k, Node *p)
    : data(d), key(k), left(nullptr), right(nullptr), parent(p) {}

template <typename Data, typename Key>
BST<Data, Key>::BST() : root(nullptr) {}

template <typename Data, typename Key>
BST<Data, Key>::~BST()
{
    // destructor
}

template <typename Data, typename Key>
bool BST<Data, Key>::empty() const
{

    if (root == nullptr)
    {
        cout << "the bst is empty "
             << " \n";
        return true;
    }
    else
    {
        cout << "the bst is NOT empty "
             << " \n";
        return false;
    }
}
template <typename Data, typename Key>

void BST<Data, Key>::insert(const Data &d, const Key &k)
{

    Node<Data, Key> *newNode = new Node<Data, Key>(d, k);

    if (root == nullptr)
    { //if BST is empty

        root = newNode;
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
    return -1;
}

// Function to remove a node with a specific key from the BST
template <typename D, typename K>
void BST<D, K>::remove(const K &key)
{
    root = removeHelper(root, key);
}

// Helper function for removing a node with a specific key because its easier this way
template <typename D, typename K>
Node<D, K> *BST<D, K>::removeHelper(Node<D, K> *node, const K &key)
{
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

    if (node == nullptr)
    {
        return node;
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

// Function to find the maximum data in the BST
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
        return -1;
    }
}

// Function to find the maximum key in the BST
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
        return -1;
    }
}

// Function to find the minimum data in the BST
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
        return -1;
    }
}

// Function to find the minimum key in the BST
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

// Function to find the successor key in the tree
template <typename D, typename K>
K BST<D, K>::successor(const K &key)
{
    // Start at the root
    Node<D, K> *current = root;
    Node<D, K> *successor = nullptr;

    if (current)
    {
        if (current->right)
        {
            return min_key();
        }
        successor = current->parent;
        while (successor && current == successor->right)
        {
            current = successor;
            successor = current->parent;
        }
    }
    return -1;
}

// Function to trim the BST to a specific range of keys
template <typename D, typename K>
void BST<D, K>::trim(const K &low, const K &high)
{
    Node<D, K> *current = root;
    root = trimHelper(current, low, high);
}

// Helper function for trimming the BST because trim was abstracted by me :)
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

// Function to return an in-order string of keys
template <typename D, typename K>
string BST<D, K>::in_order()
{
    return inOrderHelper(root);
}

// Helper function to generate an in-order string of keys
template <typename D, typename K>
string BST<D, K>::inOrderHelper(Node<D, K> *node)
{
    if (node == nullptr)
    {
        return "";
    }

    string result;

    // Traverse the left subtree (in-order)
    result += inOrderHelper(node->left);

    // Visit the current node
    result += to_string(node->key) + " ";

    // Traverse the right subtree (in-order)
    result += inOrderHelper(node->right);

    return result;
}

// fix this FUNCTION KOTAA
// Function to convert data for a specific key to a string
template <typename D, typename K>
std::string BST<D, K>::to_string()
{
    K *key = key;
    D data = get(key);
    return std::to_string(data);
}