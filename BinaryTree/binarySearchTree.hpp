#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "bstFxns.hpp"
#include "node.hpp"

template <typename T>
class bst : public bstfxns<T> {
    
private:
    node<T>* root;
public:
    
    bst() {
        root = nullptr;
    }
    
    ~bst() {}
    bst(const bst<T>& other) {}
    bst<T>& operator=(const bst<T>& other);
    
    void insert(const T& data, int count = 1) {
        bstfxns<T>::insert(root, data, count);
    }
    
    void remove(const T& data, int count = 1) {
        bstfxns<T>::remove(root, data, count);
    }
    
    bool search(const T& data) {
//        return::
    }
    
};


#endif // BINARYTREE_H
