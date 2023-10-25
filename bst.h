


using namespace std;

#ifndef NODE_H
#define NODE_H

template <typename Data, typename Key>
class Node {

    private:
        Data data;
        Key key;
        
        Node*left;
        Node*right;
        Node*parent;

        //Node(const Data &d, const Key &k, Node*p): data(d), key(k), right(nullptr), left(nullptr), parent(p){}


};

template <typename Data, typename Key>

class BST{

    private:

        Node<Data, Key>*root;

 
    public:

        BST();
        ~BST();

        bool empty() const;

        void insert(const Data &d, const Key &k);

        Data get(const Key &k);

        void remove(const Key &k);

        Node<data, key>* max_data();

        Node<data, key>* max_key();

        Node<data, key>* min_data();

        Node<data, key>* min_key();

        Node<data, key>* successor(const Key &k);

        string in_order();

        void trim(const Key&low, const Key& high);






};
















#endif // NODE_H