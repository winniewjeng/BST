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
        std::cout << bstfxns<T>::totalDataCount(root) << std::endl;
        bstfxns<T>::balance(root);
//        std::cout << bstfxns<T>::height(root) << std::endl;
    }
    
    void remove(const T& data, int count = 1) {
        bstfxns<T>::remove(root, data, count);
    }
    
    void print() {
        bstfxns<T>::print(root);
    }
    
    
//    void balance() {
//        
//        std::cout << balanceFactor(root) << std::endl;
//    }
//    
//    int balanceFactor(node<T>* root) {
//        
//    }
    //    int totalDataCount(node<T>* root);
};

//// count the number of total data inside the tree
//template <typename T>
//int bst<T>::totalDataCount(node<T>* root) {
//    if (!root)
//        return 0;
//    
//    int count = root->getCount();
//    if (root->_left)
//        count = count + totalDataCount(root->_left);
//    if (root->_right)
//        count = count + totalDataCount(root->_right);
//    return count;
//}


#endif // BINARYTREE_H
