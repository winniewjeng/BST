//
//  bstPrivateFxns.hpp
//  Tree
//
//  Created by Winnie Jeng on 5/7/19.
//  Copyright © 2019 Winnie Jeng. All rights reserved.
//

#ifndef bstFxns_hpp
#define bstFxns_hpp

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include "node.hpp"


template <typename T>
class bstfxns {
public:
    
    bstfxns(){}
    ~bstfxns(){}
    
    int nodeCount(node<T>* root);
    int totalDataCount(node<T>* root);
    
    int height(node<T>* root);
    int balanceFactor(node<T>* root);
//    void balance();
    
    void insert(node<T>*& root, const T& data, int count = 1);
    void remove(node<T>*& root, const T& data, int count = 1);

    
};

// count the number of real nodes in the tree
template <typename T>
int bstfxns<T>::nodeCount(node<T>* root) {
    if (!root)
        return 0;
    
    int count = 1;
    if (root->_left)
        count = count + totalDataCount(root->_left);
    if (root->_right)
        count = count + totalDataCount(root->_right);
    return count;
}


// count the number of total data inside the tree
template <typename T>
int bstfxns<T>::totalDataCount(node<T>* root) {

    if (!root)
        return 0;
    
    int count = root->getCount();
    if (root->_left)
        count = count + totalDataCount(root->_left);
    if (root->_right)
        count = count + totalDataCount(root->_right);
    return count;
}

// add a data
template<typename T>
void bstfxns<T>::insert(node<T>*& root, const T& data, int count) {
    
    if (!root) {
        root = new node<T>(data, count);
    } else if (*root == data) {
        root += count;
    } else if (*root > data) {
        insert(root->_left, data, count);
    } else if (*root < data) {
        insert(root->_right, data, count);
    }
    
//    std::cout << totalDataCount(root) << std::endl;

}

template<typename T>
int bstfxns<T>::height(node<T>* root) {
    if (!root)
        return 0;
    
    return 1 + std::max(height(root->_left), height(root->_right));
}

template<typename T>
int bstfxns<T>::balanceFactor(node<T>* root) {
    
    return 0;
}

//template<typename T>
//void balance() {
//
//}

template<typename T>
void bstfxns<T>::remove(node<T>*& root, const T& data, int count) {
    
}




#endif /* bstPrivateFxns_hpp */
