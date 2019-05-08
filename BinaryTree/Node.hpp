#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>

template <typename T>
struct node {
    
    T _data;
    node<T>* _left;
    node<T>* _right;
    int _depth;
    unsigned int _count;

    node(T data = T(), unsigned int count = 0);
    node(T data = T(), node* left = nullptr, node* right = nullptr, int count = 0);
    ~node();
    node(const node<T>& other);
    node<T>& operator=(const node<T>& other);
    
    void update_depth();
    T getData() const;
    unsigned int getCount() const;
    bool empty();
    void set(const T& d, unsigned int c);
    node<T>& operator-=(unsigned int c);
    node<T>& operator+=(unsigned int c);
    
    
    bool operator<(const T& other_data) { return _data < other_data; }
    bool operator<=(const T& other_data) { return _data <= other_data; }
    bool operator>(const T& other_data) { return _data > other_data; }
    bool operator>=(const T& other_data) { return _data >= other_data; }
//    template<typename S>
//    friend bool operator<(const S& x, const node<S>& n) { return x < n._data; }

//    // tester fxn - to be deleted
//    node<T>* setLeft(node<T>* root, node<T>* left);
//
//    //Nodes need to know how to interact with other nodes
//    template<typename S>
//    friend bool operator<(const node<S>& x, const node<S>& y);
//
//    template<typename S>
//    friend bool operator<=(const node<S>& x, const node<S>& y);
//
//    template<typename S>
//    friend bool operator>(const node<S>& x, const node<S>& y);
//
//    template<typename S>
//    friend bool operator>=(const node<S>& x, const node<S>& y);
//    //This is for matching data only
//    template<typename S>
//    friend bool operator==(const node<S>& x, const node<S>& y);
//    //This is for an EXACT match (data and count)
//    template<typename S>
//    friend bool operator&=(const node<S>& x, const node<S>& y);
//
//    template<typename S>
//    friend bool operator!=(const node<S>& x, const node<S>& y);
//
//    //Nodes need to know how to interact with data that is
//    //not contained in a node
//    template<typename S>
//    friend bool operator<(const S &x, const node<S> &y);
//
//    template<typename S>
//    friend bool operator<=(const S &x, const node<S> &y);
//
//    template<typename S>
//    friend bool operator>(const S &x, const node<S> &y);
//
//    template<typename S>
//    friend bool operator>=(const S &x, const node<S> &y);
//
//    template<typename S>
//    friend bool operator==(const S &x, const node<S> &y);
//
//    template<typename S>
//    friend bool operator!=(const S &x, const node<S> &y);
//
//    template<typename S>
//    friend bool operator<(const node<S> &x, const S &y);
//
//    template<typename S>
//    friend bool operator<=(const node<S> &x, const S &y);
//
//    template<typename S>
//    friend bool operator>(const node<S> &x, const S &y);
//
//    template<typename S>
//    friend bool operator>=(const node<S> &x, const S &y);
//
//    template<typename S>
//    friend bool operator==(const node<S> &x, const S &y);
//
//    template<typename S>
//    friend bool operator!=(const node<S> &x, const S &y);
//
//    template<typename S>
//    friend bool operator-=(const node<S> &x, unsigned int c);
//
//    template<typename S>
//    friend bool operator+=(const node<S> &x, unsigned int c);
//
//    template<typename S>
//    friend std::ostream& operator<<(std::ostream& out, const node<S> &n);
//
//    template<typename S>
//    friend std::istream& operator>>(std::istream& in, node<S> &n);
    
private:
    void copy(const node<T>& other);
    
};

//template <typename T>
//node<T>* node<T>::setLeft(node<T>* root, node<T>* left) {
//    root->left = left;
//    return root;
//}

template <typename T>
node<T>::node(T data, unsigned int c) {
    _data = data;
    _count = c;
    _left = _right = nullptr;
}

template <typename T>
node<T>::node(T data, node* left, node* right, int count)
: _data(data), _left(left), _right(right), _count(count) {
    update_depth();
}

template<typename T>
node<T>::~node()
{
    set(T(), 0);
}


template<typename T>
node<T>::node(const node<T>& other)
{
    copy(other);
}

template<typename T>
node<T>& node<T>::operator=(const node<T>& other)
{
    if(this != &other)
        copy(other);
    return *this;
}

template<typename T>
void node<T>::copy(const node<T>& other)
{
    set(other.data, other.count);
}

template<typename T>
void node<T>::set(const T& d, unsigned int c)
{
    _data = d;
    _count = c;
}

template<typename T>
T node<T>::getData() const {
    return _data;
}

template<typename T>
unsigned int node<T>::getCount() const {
    return _count;
}


template<typename T>
bool node<T>::empty()
{
    return _count == 0;
}

//template<typename T>
//node<T>& node<T>::operator-=(unsigned int c)
//{
//    _count = c >= _count ? 0 : _count - c;
//    return *this;
//}
//
//
//template<typename T>
//node<T>& node<T>::operator+=(unsigned int c)
//{
//    _count += c;
//    return *this;
//}
//
////Nodes need to know how to interact with other nodes hence the friend fxns
//
//template<typename S>
//bool operator<(const node<S>& x, const node<S>& y)
//{
//    return !(x >= y);
//}
//
//template<typename S>
//bool operator<=(const node<S>& x, const node<S>& y)
//{
//    return x.data <= y.data;
//}
//
//template<typename S>
//bool operator>(const node<S>& x, const node<S>& y)
//{
//    return !(x <= y);
//}
//
//template<typename S>
//bool operator>=(const node<S>& x, const node<S>& y)
//{
//    return x.data >= y.data;
//}
//
//template<typename S>
//bool operator==(const node<S>& x, const node<S>& y)
//{
//    return x.data == y.data;
//}
//
////This is for an EXACT match (data and count)
//template<typename S>
//bool operator&=(const node<S>& x, const node<S>& y)
//{
//    return (x == y) && (x.count == y.count);
//}
//
//template<typename S>
//bool operator!=(const node<S>& x, const node<S>& y)
//{
//    return !(x == y);
//}
//
////Nodes need to know how to interact with data that is
////not contained in a node
//template<typename S>
//bool operator<(const S& x, const node<S>& y)
//{
//    return x < y.data;
//}

//template<typename S>
//bool operator<=(const S& x, const node<S>& y)
//{
//    return x <= y.data;
//}
//
//template<typename S>
//bool operator>(const S& x, const node<S>& y)
//{
//    return !(x >= y.data);
//}

//template<typename S>
//bool operator>=(const S& x, const node<S>& y)
//{
//    return !(x < y.data);
//}
//
//template<typename S>
//bool operator==(const S& x, const node<S>& y)
//{
//    return x == y.data;
//}
//
//template<typename S>
//bool operator!=(const S& x, const node<S>& y)
//{
//    return !(x == y);
//}
//
////Nodes need to know how to interact with other nodes
//template<typename S>
//bool operator<(const node<S>& x, const S& y)
//{
//    return x.data < y;
//}
//
//template<typename S>
//bool operator<=(const node<S>& x, const S& y)
//{
//    return x.data <= y;
//}
//
//template<typename S>
//bool operator>(const node<S>& x, const S& y)
//{
//    return !(x.data <= y);
//}
//
//template<typename S>
//bool operator>=(const node<S>& x, const S& y)
//{
//    return !(x.data < y);
//}
//
//template<typename S>
//bool operator==(const node<S>& x, const S& y)
//{
//    return x.data == y;
//}
//
//template<typename S>
//bool operator!=(const node<S>& x, const S& y)
//{
//    return !(x.data == y);
//}

template<typename S>
std::ostream& operator<<(std::ostream& out, const node<S> &n)
{
    out<<n.data<<" (" << n.count << ") ";
}

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


#endif // NODE_H
