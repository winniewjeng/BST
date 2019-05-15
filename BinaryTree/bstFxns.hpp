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
#include <algorithm>

using namespace std;
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
    void clear(node<T>* root);
    
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
    if (!root || root->_count == 0)
        return 0;
    return ( 1 + std::max( height(root->_left), height(root->_right) ) );
}

template<typename T>
int bstfxns<T>::balanceFactor(node<T>* root) {
    if(!root || root->_count == 0)
        return 0;
    return (height(root->_left) - height(root->_right));
}

template<typename T>
void bstfxns<T>::balance(node<T>*& root) {
//    std::cout << "balance root "<< root->_data << std::endl;
    if (!root || root->_count == 0)
        return ;
    // left heavy
    if (root->_left)
        balance(root->_left);
    if (root->_right)
        balance(root->_right);
    
    //    std::cout << "balance factor for " <<  root->_data << " is " << balanceFactor(root) << std::endl;
    if ( balanceFactor(root) > 1 && balanceFactor(root->_left) < 0) {
        //        std::cout << "left heavy & zigged" << std::endl;
        node<T>* hold = root->_left;
        root->_left = hold->_right;
        hold->_right = root->_left->_left;
        root->_left->_left = hold;
        
    }
    if ( balanceFactor(root) > 1 && balanceFactor(root->_left) > 0 ) {
        //        std::cout << "left heavy" << std::endl;
        node<T>* temp = new node<T>(root->_data, root->_count);
        node<T>* hold = root->_left;
        temp->_left = hold->_right;
        temp->_right = root->_right;
        // hold->_left = nullptr;
        root->_right = root->_left = nullptr;
        delete root;
        hold->_right = temp;
        root = hold;
        
    }
    if (balanceFactor(root) < -1 && balanceFactor(root->_right) > 0) {
        //        std::cout << "right heavy & zigged" << std::endl;
        node<T>* hold = root->_right;
        root->_right = hold->_left;
        hold->_left = root->_right->_right;
        root->_right->_right = hold;
    }
    if (balanceFactor(root) < -1 && balanceFactor(root->_right) < 0 ) {
        //        std::cout << "right heavy" << std::endl;
        node<T>* temp = new node<T>(root->_data, root->_count);
        node<T>* hold = root->_right;
        temp->_right = hold->_left;
        temp->_left = root->_left;
        root->_left = root->_right = nullptr;
        delete root;
        hold->_left = temp;
        root = hold;
    }
}

template<typename T>
void bstfxns<T>::remove(node<T>*& root, node<T>*& target, int count) {
//    std::cout << "target data in remove " << target << std::endl;
    if (!target)
        std::cout << "cannot remove nonexistent data" << std::endl;
    else if (target->_count - count > 0)
        target->_count -= count;
    else {
        if (!target->_left && !target->_right) {
            delete target;
            target = nullptr;
        }
        else if (target->_right) {

            if (target->_right->_left) {
//                node<T>* walker = target->_right;
//                while (walker->_left->_left)
//                    walker = walker->_left;
//                successor = walker->_left;
//                walker->_left = successor->_right;
//                successor->_left = target->_left;
//                successor->_right = target->_right;
//
//                std::swap(target, successor);
//                cout << target->_data <<endl;
            }
        }
        //        if (target->_right) {
        //            node<T>* successor;
        //            if (target->_right->_left) {
        //                node<T>* walker = target->_right;
        //                while (walker->_left->_left)
        //                    walker = walker->_left;
        //                successor = new node<T>(walker->_left->_data, walker->_left->_count);
        //                walker->_left = successor->_right;
        //            } else {
        //                successor = new node<T>(target->_right->_data, target->_left->_count);
        //            }
        //            cout << "target is " << target->_data << "\n";
        //            cout << "successor is " << successor->_data << endl;
        //            cout << "target left is " << target->_left->_data << endl;
        //             cout << "target left is " << target->_right->_data << endl;
        //            successor->_right = target->_right;
        //            successor->_left = target->_left;
        //            cout << "successor left is " << successor->_left->_data << endl;
        //             cout << "target left left is " << target->_left->_left->_data << endl;
        //             cout << "successor left left is " << successor->_left->_left->_data << endl;
        ////            if (root == target)
        ////                root = successor;
        //
        //            target->_left = target->_right = nullptr;
        //            delete target;
        
        //            std::swap(target, successor);
        //            cout << "successor is " << successor->_data << endl;
        //            cout << "successor left left is " << successor->_left->_left->_data << endl;
        //            cout << "successor right rifght is " << successor->_right->_right->_data << endl;
    }
    
    //
    //        // delete target and find successor
    //        if (target->_right) {
    //
    //            // if target has a right child node
    //            node<T>* successor = new node<T>(target->_right->_data, target->_left->_count);
    //            if (target->_right->_left) {
    //                // if target's right node has left grand(child) node
    //                node<T>* walker = target->_right;
    //                while (walker->_left->_left)
    //                    walker = walker->_left;
    //                successor = walker->_left; // update successor
    //                walker->_left = successor->_right; // update tree struct
    //            }
    //            successor->_right = target->_right;
    //            successor->_left = target->_left;
    //            if (root == target)
    //                root = successor;
    //            target->_left = target->_right = nullptr;
    //            delete target;
    //            target = successor;
    //        } else {
    //            if (target->_left) {
    //                // if target has not right child but has a left child node
    //                node<T>* successor = new node<T>(target->_left->_data, target->_left->_count);
    //                if (root == target)
    //                    root = successor;
    //                target->_left = nullptr;
    //                delete target;
    //                target = successor;
    //            } else {
    //                // no successor
    //                delete target;
    //                target = nullptr;
    //            }
    //        }
    ////         std::cout << "target " << target->_data << std::endl;

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
    
    return root;
}

template<typename T>
void bstfxns<T>::print(node<T>* root) {
    // in-order traversal for printing
    if (!root || root->_count == 0)
        return ;
    if (root) {
        if (root->_left)
            print(root->_left);
        std::cout << " | " << root->_data << " | " << std::endl;
        if (root->_right)
            print(root->_right);
    }
}

template<typename T>
void bstfxns<T>::clear(node<T>* root) {
    if (!root)
        return ;
    if (root->right != nullptr)
        clear(root->right);
    
    if (root->left != nullptr)
        clear(root->left);
    
    if (!root->left && !root->right) {
        delete root;
        root = nullptr;
    }
}




#endif /* bstPrivateFxns_hpp */
