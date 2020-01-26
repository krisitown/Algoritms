#include <iostream>
#include <queue>
#include <string>

using namespace std;

template <class T>
class Binary {
    T node;
    Binary<T>* leftChild = nullptr;
    Binary<T>* rightChild = nullptr;

public:
    Binary<T>(T node);
    T getNode();
    void insert(T el);
    void print();
    bool contains(T el);
    
    T getMax();
    T getMin();
};

template <class T>
T Binary<T>::getNode() {
    return node;
}

template <class T>
void Binary<T>::insert(T el){
    if(el < node){
        if(leftChild != nullptr){
            leftChild->insert(el);
        } else {
            leftChild = new Binary<T>(el);
        }
    } else {
        if(rightChild != nullptr){
            rightChild->insert(el);
        } else {
            this->rightChild = new Binary<T>(el);
        }
    }
}

template <class T>
void Binary<T>::print(){
    cout << node;
    if(leftChild != nullptr){
        leftChild->print();
    } else {
        cout << endl;
    }
    if(rightChild != nullptr){
        rightChild->print();
    } else {
        cout << endl;
    }
}

template <class T>
Binary<T>::Binary(T node) : node(node), leftChild(nullptr), rightChild(nullptr){
}

template <class T>
bool Binary<T>::contains(T el) {
    if(node == el){
        return true;
    }
    if(el < node){
        if(leftChild != nullptr && leftChild->contains(el)){
            return true;
        }
    } else {
        if(rightChild != nullptr && rightChild->contains(el)){
            return true;
        }
    }
    
    return false;
}

template <class T>
T Binary<T>::getMax() {
    if(rightChild == nullptr){
        return node;
    }
    return rightChild->getMax();
}

template <class T>
T Binary<T>::getMin() {
    if(leftChild == nullptr){
        return node;
    }
    return leftChild->getMin();
}
