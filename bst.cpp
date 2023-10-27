#include <iostream>
#include "bst.h"
#include <string>
#include <queue>
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

// writing findMin()

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
        return "";
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
        return 0;
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
        return "";
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
    bool first = true;
    return inOrderHelper(root, first);
}

// Helper function to generate an in-order string of keys
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

// fix this FUNCTION KOTAA
// Function to convert data for a specific key to a string
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
