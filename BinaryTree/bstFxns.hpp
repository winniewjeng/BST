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
    void balance(node<T>*& root);
    
    void insert(node<T>*& root, const T& data, int count = 1);
    void remove(node<T>*& root, const T& data, int count = 1);
    
    void print(node<T>* root);
    
    
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
        root->_count += count;
    } else if (*root > data) {
        insert(root->_left, data, count);
    } else if (*root < data) {
        insert(root->_right, data, count);
    }
}

template<typename T>
int bstfxns<T>::height(node<T>* root) {
    if (!root)
        return 0;
    return ( 1 + std::max( height(root->_left), height(root->_right) ) );
}

template<typename T>
int bstfxns<T>::balanceFactor(node<T>* root) {
    
    if(!root)
        return 0;
    return ( height(root->_left) - height(root->_right) );
}

template<typename T>
void bstfxns<T>::balance(node<T>*& root) {
    
    // left heavy
    if (root->_left)
        balance(root->_left);
    if (root->_right)
        balance(root->_right);
    
    if ( balanceFactor(root) > 1 && balanceFactor(root->_left) < 0) {
        std::cout << "left heavy & zigged" << std::endl;
        node<T>* temp = root->_left;
        root->_left = temp->_right;
        temp->_right = nullptr;
        root->_left->_left = temp;
    }
    if ( balanceFactor(root) > 1 && balanceFactor(root->_left) > 0 ) {
        std::cout << "left heavy" << std::endl;
        node<T>* temp = root;
        root = root->_left;
        temp->_left = nullptr;
        root->_right = temp;
    }
    if (balanceFactor(root) < -1 && balanceFactor(root->_left) > 0) {
        std::cout << "right heavy & zigged" << std::endl;
        node<T>* temp = root->_right;
        root->_right = temp->_left;
        temp->_left = nullptr;
        root->_right->_right = temp;
        
    }
    if (balanceFactor(root) < -1 && balanceFactor(root->_left) < 0 ) {
        std::cout << "right heavy" << std::endl;
        node<T>* temp = root;
        root = root->_right;
        temp->_right = nullptr;
        root->_left = temp;
        
    }
}

template<typename T>
void bstfxns<T>::remove(node<T>*& root, const T& data, int count) {
    
}

template<typename T>
void bstfxns<T>::print(node<T>* root) {
    // in-order traversal for printing
    if (root) {
        if (root->_left)
            print(root->_left);
        std::cout << " | " << root->_data << " | " << std::endl;
        if (root->_right)
            print(root->_right);
        
    }
}




#endif /* bstPrivateFxns_hpp */
