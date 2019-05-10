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
        //        balance(root->_left);
    } else if (*root < data) {
        insert(root->_right, data, count);
        //        balance(root->_right);
    }
    //    std::cout << totalDataCount(root) << std::endl;
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
void bstfxns<T>::balance(node<T>* root) {
    
    // left heavy
    if (root->_left)
        balance(root->_left);
    if (root->_right)
        balance(root->_right);
    
    // left-heavy
    if ( balanceFactor(root) > 1) {
        std::cout << root->_data << std::endl;
        std::cout <<  "balanceFactor " << balanceFactor(root) << std::endl;
        if( balanceFactor(root->_left) < 0) {
            std::cout <<  "left heavy zig\n";
            // zigzag
            std::cout << root->_left->_data << std::endl; // 20
            std::cout << root->_left->_right->_data << std::endl; // 40
            
            node<T>* temp = root->_left;
            root->_left = root->_left->_right;
            std::cout << root->_left->_data << std::endl; // 40
            std::cout << temp->_data << std::endl; // 20
            temp->_right = nullptr;
            std::cout << root->_left->_data << std::endl; // 40
            root->_left->_left = temp; // set
            std::cout << root->_left->_left->_data << std::endl; // nullptr
//            std::cout << temp->_right->_data << std::endl; // nullptr
//            if ( !(root->_left)->_right->_left && !(root->_left)->_right->_right) {
//                std::cout <<  "I'm ziggged\n";
//            }
            
//            ((root->_left)->_right)->_left = root->_left;  // set left of 40 is 20
            
//            if ( !(root->_left)->_right->_left && !(root->_left)->_right->_right) {
//                std::cout <<  "I'm ziggged\n";
//            }
//            std::cout << ((root->_left)->_right)->_left->_data  << std::endl; // 20
//            std::cout << ((root->_left))->_data  << std::endl; // 20
//            root->_left = (root->_left)->_right; // set left of 50 to 40
//            std::cout << ((root->_left))->_data  << std::endl; // left of 50 is now 40
//            std::cout << ((root->_left))->_left->_data  << std::endl;
//            (root->_left)->_left = nullptr;
//            if (!((root->_left))->_left)
//                std::cout << "null!" << std::endl; // original left of 50 is 20
//            if (!((root->_right)))
//                std::cout << "null!" << std::endl; // original left of 50 is 20
//            if (!((root->_left)->_right))
//                std::cout << "null!" << std::endl; // original left of 50 is 20
        }
////        std::cout << root->_data << std::endl;
//        std::cout << root->_left->_data << std::endl;
//        std::cout << root->_left->_left->_data << std::endl;
        if( balanceFactor(root->_left) > 0 ) {
            std::cout <<  "left heavy \n";
            root->_left->_left->_right = root->_left;
            root->_left = (root->_left)->_left;
            (root->_left)->_left = nullptr;
        }
    }
    else if ( balanceFactor(root) < -1) {
        //                    std::cout <<  "balanceFactor " << balanceFactor(root) << std::endl;
        if(balanceFactor(root->_left) > 0) {
            std::cout <<  "right heavy zig\n";
        } else {
            std::cout <<  "right heavy\n";
            
        }
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
