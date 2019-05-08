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
//    ~bstfxns(){}
    
    int nodeCount(node<T>* root);
    int totalDataCount(node<T>* root);
    
    
    void insert(node<T>* root, const T& data, int count = 1);
    void remove(node<T>* root, const T& data, unsigned int c = 1);
    
   
//    bool operator<(const node<T>* n) { return x < n._data; }
    
    
};

// count the number of real nodes in the tree
template <typename T>
int bstfxns<T>::nodeCount(node<T>* root) {
    node<T>* walker = root;
    if (!walker)
        return 0;
    
    int count = 1;
    if (walker->_left)
        count = count + totalDataCount(walker->_left);
    if (walker->_right)
        count = count + totalDataCount(walker->_right);
    return count;
}


// count the number of total data inside the tree
template <typename T>
int bstfxns<T>::totalDataCount(node<T>* root) {
    node<T>* walker = root;
    if (!walker)
        return 0;
    
    int count = walker->getCount();
    if (walker->_left)
        count = count + totalDataCount(walker->_left);
    if (walker->_right)
        count = count + totalDataCount(walker->_right);
    return count;
}

// add a data
template<typename T>
void bstfxns<T>::insert(node<T>* root, const T& data, int count) {
    
    if (!root) {
        root = new node<T>(data, count);
    } else if (root->getData() == data) {
        root += count;
    } else if (*root > data) {
        insert(root->_left, data, count);
    } else if (*root < data) {
        insert(root->_right, data, count);
    }
//    std::cout << nodeCount(root) << std::endl;
//    std::cout << totalDataCount(root) << std::endl;
}

template<typename T>
void bstfxns<T>::remove(node<T>* root, const T& data, unsigned int c) {
    
}




#endif /* bstPrivateFxns_hpp */
