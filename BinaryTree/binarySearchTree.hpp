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
//        std::cout << root->_data << std::endl;
//         std::cout << bstfxns<T>::totalDataCount(root) << std::endl;
//        std::cout << "counts " << bstfxns<T>::nodeCount(root) << std::endl;
    }
    
    void remove(const T& data, int count = 1) {
        node<T>* target = search(data);
//        std::cout << "target data " << target->_data << std::endl;
//        std::cout << "data " << data  << std::endl;
        bstfxns<T>::remove(root, target, count);
        bstfxns<T>::balance(root);
//        std::cout << "root " << root->_data << std::endl;
    }
    
    node<T>* search(const T& data) {
        return bstfxns<T>::search(root, data);
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
