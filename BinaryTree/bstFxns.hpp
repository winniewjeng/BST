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
    void remove(node<T>*& root, node<T>*& target, int count = 1);
    node<T>* search(node<T>*& root, const T& data);
    
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
    return (height(root->_left) - height(root->_right));
}

template<typename T>
void bstfxns<T>::balance(node<T>*& root) {
    
    // left heavy
    if (root->_left)
        balance(root->_left);
    if (root->_right)
        balance(root->_right);

//    std::cout << "balance factor for " <<  root->_data << "is " << balanceFactor(root) << std::endl;
    if ( balanceFactor(root) > 1 && balanceFactor(root->_left) < 0) {
//        std::cout << "in here?"<< root->_data << std::endl;
//        std::cout << "left heavy & zigged" << std::endl;
        node<T>* temp = root->_left;
        root->_left = temp->_right;
        temp->_right = nullptr;
        root->_left->_left = temp;
    }
    if ( balanceFactor(root) > 1 && balanceFactor(root->_left) > 0 ) {
//        std::cout << "in here??"<< root->_data << std::endl;
//        std::cout << "left heavy" << std::endl;
        node<T>* temp = root;
        root = root->_left;
        temp->_left = nullptr;
        root->_right = temp;
    }
    if (balanceFactor(root) < -1 && balanceFactor(root->_right) > 0) {
//        std::cout << "in here???"<< root->_data << std::endl;
//        std::cout << "right heavy & zigged" << std::endl;
        node<T>* temp = root->_right;
        root->_right = temp->_left;
        temp->_left = nullptr;
        root->_right->_right = temp;
        
    }
    if (balanceFactor(root) < -1 && balanceFactor(root->_right) < 0 ) {
//        std::cout << "in here????"<< root->_data << std::endl;
//        std::cout << "right heavy" << std::endl;
        node<T>* temp = root;
        root = root->_right;
        temp->_right = nullptr;
        root->_left = temp;
        
    }
}

template<typename T>
void bstfxns<T>::remove(node<T>*& root, node<T>*& target, int count) {
    
    if (!target)
        std::cout << "cannot remove nonexistent data" << std::endl;
    else if (target->_count - count > 0)
        target->_count -= count;
    else {
//        std::cout << "delete target node w/data " << target->_data  << std::endl;
        if (!target->_left && !target->_right) {
//            std::cout << "i " << target->_data << " am a leaf node\n";
        }
//        // delete target
//        if (target->_right) {
//            node<T>* successor = target->_right;
//            if (successor->_left) {
//                node<T>* walker = successor; // set a default successor
//                while (walker->_left->_left)
//                    walker = walker->_left;
//                successor = walker->_left; // update the successor
//                // prime(prepare) the successor
//                walker->_left = successor->_right; // whether it be a node or nullptr
//                successor->_left = target->_left;
//                successor->_right = target->_right;
//            } else {
//                // prime(prepare) the successor
//                successor->_left = target->_left;
//            }
//            // replace target with successor
//            target = successor;
//        } else {
//            // target does not have a right child
//            if (target->_left)
//                target = target->_left;
//            else {
//                std::cout << "i should be here\n";
//                delete target; // target is a leaf node
//
//            }
//        }
//        node<T>* successor = nullptr;
//        node<T>* walker = nullptr;
//        // does target have a right child?
//        if(target->_right) {
//            walker = target->_right;
//            // does target's r.child have l.(grand)child?
//            if(walker->_left) {
//                while (walker->_left->_left)
//                    walker = walker->_left;
//
//                successor = walker->_left;
//
//                // does successor have a r.child?
//                if (successor->_right) {
//                    node<T>* temp = successor->_right;
//                    delete successor->_right;
//                    walker->_left = temp;
//                }
//            } else {
//                //target's r.child does not have any l.child
//                successor = target->_right;
//            }
//            target = successor;
//            // unlikely but exception handling is important
//            if (successor)
//                delete successor;
//            else
//                std::cout << "error: cannot delete successor because it was unassigned\n";
//        } else {
//            // target does not have r.child
//            if (target->_left) {
//                // but has a l.child
//                successor = target->_left;
//                // or target->data = successor->data, target->count = successor->count, but it seems okay
//                target = successor;
//                delete successor;
//            } else {
//                // target is a leaf node: has no l.child or r.child
//                delete target;
//            }
//        }
    }

}

template<typename T>
node<T>* bstfxns<T>::search(node<T>*& root, const T& data) {

    if (!root)
        std::cout <<"the tree is empty!\n";
        
    if (root->_data == data) {
//        std::cout << "fonud target data " << root->_data << std::endl;
        return root;
    } else if (root->_data > data && root->_left) {
//        std::cout << "look left of " << root->_data << std::endl;
        return search(root->_left, data);
    } else if (root->_data < data && root->_right) {
//        std::cout << "look right of " << root->_data << std::endl;
        return search(root->_right, data);
    }
//    else
//        std::cout << data << " is not in the tree\n";
    
    return nullptr;
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
