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
        bstfxns<T>::balance(root);
    }
    
    void remove(const T& data, int count = 1) {
        node<T>* target = nullptr; // reset target
        target = search(data);
        bstfxns<T>::remove(root, target, count);
        bstfxns<T>::balance(root);
    }
    
    node<T>* search(const T& data) {
        return bstfxns<T>::search(root, data);
    }
    
    void print() {
        bstfxns<T>::print(root);
        std::cout << std::endl;
    }
    
};


#endif // BINARYTREE_H
