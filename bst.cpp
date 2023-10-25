#include<iostream>


#include "bst.h"

using namespace std;


template <typename Data, typename Key>

class Node{

    private:
        Data data;
        Key key;
        Node *left = nullptr;
        Node *right = nullptr;
        Node *parent;

    public:

        Node(const Data &d, const Key &k, Node*p = nullptr)
        : data(d), key(k), left(nullptr), right(nullptr), parent(p) {}



    


};
template <typename Data, typename Key>
BST<Data, Key>::BST(): root(nullptr){}


template <typename Data, typename Key>
BST<Data, Key>::~BST(){
        // destructor
    }

template <typename Data, typename Key>
bool BST<Data, Key>::empty() const{

    if(root == nullptr){
        cout<<"the bst is empty "<<" \n";
        return true;
    }
    else{
        cout<<"the bst is NOT empty "<<" \n";
        return false;
    }


}
template <typename Data, typename Key>

void BST<Data, Key>::insert(const Data &d, const Key &k){
    
    Node<Data, Key>* newNode = new Node<Data Key>(d, k);
   
    if(root == nullptr){ //if BST is empty

        root = newNode;
    }
    Node<Data, Key>*current = root; //start from root
    Node<Data, key>*parentt = nullptr;

    while(current != nullptr){

        parentt = current;
        if(k < current->key){
            current = current->left;
        }
        else if{
            current = current->right;
        }
        else{
            // duplicate key
            delete newNode;
            return;
        }
    }
    newNode->parent = parentt;
        if(k < parent->key){
            parent->left = newNode;

        }
        else{
            parent->right = newNode;

        }

}



template <typename Data, typename Key>
Data BST<Data, Key>::get(const Key &k){
    
    
    Node<Data, Key>*current = root; //start from root
    while (current!=nullptr){

        //checking each node from root if key matches
        if(k == current->key){
            return current->data;
        }
        else if(k < current->key){
            current = current->left;
        }
        else{
            current = current->right;
        }


    }
    // key not found
    throw runtime_error("Key not Found");


}
template <typename Data, typename Key>
void BST<Data, Key>::remove(const Key &k){

    if(root == nullptr){
        cout<<"Nothing to remove in the BST! \n";
        return;
    }

    root = removeNode(root, k);




}


   




