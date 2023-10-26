#ifndef NODE_H
#define NODE_H

template <typename Data, typename Key>
class Node
{

public:
    Data data;
    Key key;
    Node *left;
    Node *right;
    Node *parent;
    Node(const Data &d, const Key &k, Node *p = nullptr);
};

template <typename Data, typename Key>

class BST
{

private:
    Node<Data, Key> *root;

public:
    BST();
    ~BST();

    bool empty() const;

    void insert(const Data &d, const Key &k);

    Data get(const Key &k);

    void remove(const Key &k);

    Data max_data();

    Key max_key();

    Data min_data();

    Key min_key();

    Key successor(const Key &k);

    std::string in_order();

    void trim(const Key &low, const Key &high);

    std::string inOrderHelper(Node<Data, Key> *node);

    Node<Data, Key> trimHelper(Node<Data, Key> *node, const Key &low, const Key &high);

    Node<Data, Key> removeHelper(Node<Data, Key> *node, const Key &key);
};

#endif // NODE_H