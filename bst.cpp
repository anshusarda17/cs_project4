#include <iostream>
#include "bst.h"

using namespace std;

template <typename Data, typename Key>

class Node
{

private:
    Data data;
    Key key;
    Node *left = nullptr;
    Node *right = nullptr;
    Node *parent;

public:
    Node(const Data &d, const Key &k, Node *p = nullptr)
        : data(d), key(k), left(nullptr), right(nullptr), parent(p) {}
};
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

    Node<Data, Key> *newNode = new Node<Data Key>(d, k);

    if (root == nullptr)
    { //if BST is empty

        root = newNode;
    }
    Node<Data, Key> *current = root; //start from root
    Node<Data, key> *parentt = nullptr;

    while (current != nullptr)
    {

        parentt = current;
        if (k < current->key)
        {
            current = current->left;
        }
        else if
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
    if (k < parent->key)
    {
        parent->left = newNode;
    }
    else
    {
        parent->right = newNode;
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
    // key not found
    throw runtime_error("Key not Found");
}
template <typename Data, typename Key>
void BST<Data, Key>::remove(const Key &k)
{

    if (root == nullptr)
    {
        cout << "Nothing to remove in the BST! \n";
        return;
    }

    root = removeNode(root, k);
}

// Function to find the maximum data in the BST
template <typename D, typename K>
D BST<D, K>::max_data()
{
    // Start at the root
    TreeNode *current = root;

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
        return nullptr;
    }
}

// Function to find the maximum key in the BST
template <typename D, typename K>
K BST<D, K>::max_key()
{
    // Start at the root
    TreeNode *current = root;

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
        return nullptr;
    }
}

// Function to find the minimum data in the BST
template <typename D, typename K>
D BST<D, K>::min_data()
{
    // Start at the root
    TreeNode *current = root;

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
        return nullptr;
    }
}

// Function to find the minimum key in the BST
template <typename D, typename K>
K BST<D, K>::min_key()
{
    // Start at the root
    TreeNode *current = root;

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
        return nullptr;
    }
}

// Function to find the successor key in the tree
template <typename D, typename K>
K BST<D, K>::successor(K key)
{
    // Start at the root
    TreeNode *current = root;
    TreeNode *successor = nullptr;

    if (current)
    {
        if (current->right)
        {
            return min_key()
        }
        successor = current->parent;
        while (successor && current == successor->right)
        {
            current = successor;
            successor = current->parent;
        }
    }
    return nullptr;
}

// Function to trim the BST to a specific range of keys
template <typename D, typename K>
void BST<D, K>::trim(K low, K high)
{
    TreeNode *current = root;
    root = trimHelper(current, low, high);
}

// Helper function for trimming the BST because trim was abstracted by me :)
template <typename D, typename K>
typename BST<D, K>::TreeNode *BST<D, K>::trimHelper(TreeNode *node, K low, K high)
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
