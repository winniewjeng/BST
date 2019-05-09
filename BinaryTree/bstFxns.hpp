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
    void balance(node<T>* root);
    
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
//        balance(root); //??????????????
    } else if (*root == data) {
        root->_count += count;
//        root->_count = root->_count + count;
    } else if (*root > data) {
        insert(root->_left, data, count);
//        balance(root->left);
    } else if (*root < data) {
        insert(root->_right, data, count);
//        balance(root->left);
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
    
    if(!root)
        return 0;
    return height(root->_left) - height(root->_right);
}

template<typename T>
void bstfxns<T>::balance(node<T>* root) {
    
    if( abs(balanceFactor(root)) <= 1 ) {
        std::cout << "Tree is balanced!\n";
    }
    
    else if ( balanceFactor(root) > 1) {
        if( balanceFactor(root->_left) -  balanceFactor(root->_right) < 0) {
            node<T>* temp = root->_left;
            root->_left = (root->_left)->_right;
            (root->_left)->_left = temp;
        }
        node<T>* temp = root;
        root =  root->_left;
        root->_right = temp;
    }  else {
        if (balanceFactor(root->_left) -  balanceFactor(root->_right) > 0) {
            node<T>* temp = root->_right;
            root->_right = (root->_right)->_right;
            (root->_right)->_right = temp;
        }
        node<T>* temp = root;
        root = root->_right;
        root->_left = temp;
    }
    

}

template<typename T>
void bstfxns<T>::remove(node<T>*& root, const T& data, int count) {
    
}

template<typename T>
void bstfxns<T>::print(node<T>* root) {
    // post order traversal for printing
    if (root) {
        if (root->_left)
            print(root->_left);
        if (root->_right)
            print(root->_right);
        std::cout << " | " << root->_data << " | " << std::endl;
    }
}




#endif /* bstPrivateFxns_hpp */
