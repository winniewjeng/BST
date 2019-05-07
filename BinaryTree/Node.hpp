//
//  Node.hpp
//  BinaryTree
//
//  Created by Winnie Jeng on 5/7/19.
//  Copyright © 2019 Winnie Jeng. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#define lessThanChild(x) (2*x + 1)
#define greaterThanChild(x) (2*x + 2)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>

template<typename T>
struct node
{
    T data;
    unsigned int count;
    
    node(const T &d = T(), int c = 0);
    ~node();
    node(const node<T>& other);
    node<T>& operator=(const node<T> &other);
    //This is a "swap" function for nodes to change values.
    node<T>& operator^=(node<T> &other);
    //This function will "zero out the values" of a node
    void zeroOut();
    //Quick check function to see if a node is empty
    bool empty();
    node<T>& operator-=(unsigned int c);
    node<T>& operator+=(unsigned int c);
    void set(const T& d, unsigned int c);
    
    //Nodes need to know how to interact with other nodes
    template<typename S>
    friend bool operator<(const node<S> &x, const node<S> &y);
    
    template<typename S>
    friend bool operator<=(const node<S> &x, const node<S> &y);
    
    template<typename S>
    friend bool operator>(const node<S> &x, const node<S> &y);
    
    template<typename S>
    friend bool operator>=(const node<S> &x, const node<S> &y);
    //This is for matching data only
    template<typename S>
    friend bool operator==(const node<S> &x, const node<S> &y);
    //This is for an EXACT match (data and count)
    template<typename S>
    friend bool operator&=(const node<S> &x, const node<S> &y);
    
    template<typename S>
    friend bool operator!=(const node<S> &x, const node<S> &y);
    
    //Nodes need to know how to interact with data that is
    //not contained in a node
    template<typename S>
    friend bool operator<(const S &x, const node<S> &y);
    
    template<typename S>
    friend bool operator<=(const S &x, const node<S> &y);
    
    template<typename S>
    friend bool operator>(const S &x, const node<S> &y);
    
    template<typename S>
    friend bool operator>=(const S &x, const node<S> &y);
    
    template<typename S>
    friend bool operator==(const S &x, const node<S> &y);
    
    template<typename S>
    friend bool operator!=(const S &x, const node<S> &y);
    
    template<typename S>
    friend bool operator<(const node<S> &x, const S &y);
    
    template<typename S>
    friend bool operator<=(const node<S> &x, const S &y);
    
    template<typename S>
    friend bool operator>(const node<S> &x, const S &y);
    
    template<typename S>
    friend bool operator>=(const node<S> &x, const S &y);
    
    template<typename S>
    friend bool operator==(const node<S> &x, const S &y);
    
    template<typename S>
    friend bool operator!=(const node<S> &x, const S &y);
    
    template<typename S>
    friend bool operator-=(const node<S> &x, unsigned int c);
    
    template<typename S>
    friend bool operator+=(const node<S> &x, unsigned int c);
    
    template<typename S>
    friend std::ostream& operator<<(std::ostream& out, const node<S> &n);
    
    template<typename S>
    friend std::istream& operator>>(std::istream& in, node<S> &n);
    
private:
    void copy(const node<T>& other);
};


template<typename T>
node<T>::node(const T &d, int c)
{
    set(d,c);
}

template<typename T>
node<T>::~node()
{
    zeroOut();
}

template<typename T>
node<T>::node(const node<T> &other)
{
    copy(other);
}

template<typename T>
node<T>& node<T>::operator=(const node<T> &other)
{
    if(this != &other)
        copy(other);
    return *this;
}

template<typename T>
void node<T>::copy(const node<T> &other)
{
    set(other.data, other.count);
}

//This is a "swap" function for nodes to change values.
template<typename T>
node<T>& node<T>::operator^=(node<T> &other)
{
    T temp = data;
    data = other.data;
    other.data = temp;
    //This is the XOR Swap. Works very, very fast on ints
    //with no additional memory allocations
    other.count ^= count ^= other.count ^= count;
    return *this;
}

//This function will "zero out the values" of a node
template<typename T>
void node<T>::zeroOut()
{
    set(T(),0);
}

template<typename T>
void node<T>::set(const T& d, unsigned int c)
{
    data = d;
    count = c;
}


template<typename T>
bool node<T>::empty()
{
    return count == 0;
}

template<typename T>
node<T>& node<T>::operator-=(unsigned int c)
{
    count = c >= count ? 0 : count - c;
    return *this;
}


template<typename T>
node<T>& node<T>::operator+=(unsigned int c)
{
    count += c;
    return *this;
}

//Nodes need to know how to interact with other nodes

template<typename S>
bool operator<(const node<S> &x, const node<S> &y)
{
    return !(x >= y);
}

template<typename S>
bool operator<=(const node<S> &x, const node<S> &y)
{
    return x.data <= y.data;
}

template<typename S>
bool operator>(const node<S> &x, const node<S> &y)
{
    return !(x <= y);
}

template<typename S>
bool operator>=(const node<S> &x, const node<S> &y)
{
    return x.data >= y.data;
}

template<typename S>
bool operator==(const node<S> &x, const node<S> &y)
{
    return x.data == y.data;
}

//This is for an EXACT match (data and count)
template<typename S>
bool operator&=(const node<S> &x, const node<S> &y)
{
    return (x == y) &&(x.count == y.count);
}

template<typename S>
bool operator!=(const node<S> &x, const node<S> &y)
{
    return !(x == y);
}

//Nodes need to know how to interact with data that is
//not contained in a node
template<typename S>
bool operator<(const S &x, const node<S> &y)
{
    return x < y.data;
}

template<typename S>
bool operator<=(const S &x, const node<S> &y)
{
    return x <= y.data;
}

template<typename S>
bool operator>(const S &x, const node<S> &y)
{
    return !(x >= y.data);
}

template<typename S>
bool operator>=(const S &x, const node<S> &y)
{
    return !(x < y.data);
}

template<typename S>
bool operator==(const S &x, const node<S> &y)
{
    return x == y.data;
}

template<typename S>
bool operator!=(const S &x, const node<S> &y)
{
    return !(x == y);
}

//Nodes need to know how to interact with other nodes
template<typename S>
bool operator<(const node<S> &x, const S &y)
{
    return x.data < y;
}

template<typename S>
bool operator<=(const node<S> &x, const S &y)
{
    return x.data <= y;
}

template<typename S>
bool operator>(const node<S> &x, const S &y)
{
    return !(x.data <= y);
}

template<typename S>
bool operator>=(const node<S> &x, const S &y)
{
    return !(x.data < y);
}

template<typename S>
bool operator==(const node<S> &x, const S &y)
{
    return x.data == y;
}

template<typename S>
bool operator!=(const node<S> &x, const S &y)
{
    return !(x.data == y);
}




template<typename S>
std::ostream& operator<<(std::ostream& out, const node<S> &n)
{
    out<<n.data<<" ("<<n.count<<") ";
}

//Need to SPECIALIZE the template to handle strings!!!
//Dropbox has lots of documents, and examples, on how
//to specialize templates.
//template<std::string S >
/*
 std::istream& operator>>(std::istream& in, node<S> &n)
 {
 std::string line;
 char junk;
 if(&in == &std::cin)
 {
 std::cout<<"Data: ";
 std::cin>>n.data;
 std::cout<<"Frequency (press enter for 1): ";
 getline(in,line);
 n.count = line.empty() ? 1 : stoi(line);
 fflush(stdin);
 }
 else
 in>>n.data>>junk>>n.count>>junk;
 }
 */

template<typename S>
std::istream& operator>>(std::istream& in, node<S> &n)
{
    std::string line;
    char junk;
    if(&in == &std::cin)
    {
        std::cout<<"Data: ";
        std::cin>>n.data;
        std::cout<<"Frequency (press enter for 1): ";
        getline(in,line);
        n.count = line.empty() ? 1 : stoi(line);
        fflush(stdin);
    }
    else
        in>>n.data>>junk>>n.count>>junk;
}



#endif /* Node_hpp */
