//
//  binaryTree.hpp
//  BinaryTree
//
//  Created by Winnie Jeng on 5/7/19.
//  Copyright © 2019 Winnie Jeng. All rights reserved.
//

#ifndef binaryTree_hpp
#define binaryTree_hpp

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include "node.h"

enum BINARY_TREE_ERRORS {EMPTY, FULL, NOT_FOUND};

enum BINARY_TREE_TRAVERSAL {PRE_ORDER, IN_ORDER, POST_ORDER};

template<typename T>
class binaryTree
{
public:
    binaryTree();
    binaryTree(const T &data, unsigned int c = 1);
    ~binaryTree();
    binaryTree(const binaryTree<T> &other);
    binaryTree<T>& operator=(const binaryTree<T> &other);
    
    bool empty() const;
    T smallestNode() const;
    T largestNode() const;
    unsigned int totalDataCount();
    unsigned int dataCount(const T &d) const;
    unsigned int nodeCount() const;
    unsigned int depth() const;
    bool balanced();
    void rebalance();
    void clear();
    void setTraversal(BINARY_TREE_TRAVERSAL t);
    BINARY_TREE_TRAVERSAL getTraversal();
    binaryTree<T>& operator<<(const T &data);
    void insert(const T& data, unsigned int c = 1);
    bool remove(const T &data, unsigned int c = 1);
    bool removeAll(const T & data);
    bool find(const T & data) const;
    
    template<typename S>
    friend std::ostream& operator<<(std::ostream &out, const binaryTree<S> &tree);
    
    
    template<typename S>
    friend std::istream& operator>>(std::istream &in, binaryTree<S> &tree);
    
private:
    std::vector< node<T> * > theTree;
    BINARY_TREE_TRAVERSAL method;
    //    int validNodeCount;
    
    void copy(const binaryTree<T>& other);
    void deleteAll();
    node<T>& nodeNumbered(int nodeNumber) const;
    void addLevel();
    unsigned int largestNodeNumber() const;
    unsigned int depth(unsigned int nodeNumber);
    unsigned int nodeCount(unsigned int currentNode) const;
    unsigned int totalDataCount(unsigned int currentNode);
    void moveSubTree(unsigned int from, unsigned int to);
    int max(int x, int y);
    void print(std::ostream &out, unsigned int root) const;
    unsigned int findWhereToAttachLessThanSubtree(unsigned int child);
    void removeLastLevel();
    void trimTree();
    std::vector< node<T> * > shrunkTree;
    int nodeCounts;
    
};

#endif /* binaryTree_hpp */
