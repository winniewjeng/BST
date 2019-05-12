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
    int _count;
    
    // essentials
    node(T data);
    node(T data = T(), int count = 0);
    node(T data = T(), node* left = nullptr, node* right = nullptr, int count = 0);
    ~node();
    node(const node<T>& other);
    node<T>& operator=(const node<T>& other);
    
    // getters
    T getData() const;
    int getCount() const;
    bool empty();
    
    // setters
    void set(const T& data, int count);
//    node<T>& operator-=(int count) { this->_count -= count; return *this; } // broke
//    node<T>& operator+=(int count) { this->_count += count; return *this; }  // broke
    
    // ios
    template<typename S>
    friend std::ostream& operator<<(std::ostream& out, const node<S> &n);
    template<typename S>
    friend std::istream& operator>>(std::istream& in, node<S> &n);
    
    
    //Nodes need to know how to interact with other nodes
    bool operator<(const T& x) { return _data < x; }
    bool operator>(const T& x) { return _data > x; }
    bool operator<=(const T& x) { return _data <= x; }
    bool operator>=(const T& x) { return _data >= x; }
    bool operator==(const T& x) { return _data == x; }
    
//    bool operator==(const node<T>*& n) { return _data == n->_data; }
    
    
    T& operator*() { return ptr->data; }
    T* operator->() { return &ptr->data; }
    
private:
    void copy(const node<T>& other);
    node<T>* ptr;
    
};

// essentials
template <typename T>
node<T>::node(T data) {
    std::cout << "node ctor\n";
    _data = data;
    _count = 0;
    _left = _right = nullptr;
}

template <typename T>
node<T>::node(T data, int count) {
    _data = data;
    _count = count;
    _left = _right = nullptr;
}

template <typename T>
node<T>::node(T data, node* left, node* right, int count)
: _data(data), _left(left), _right(right), _count(count) {
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

// getters
template<typename T>
T node<T>::getData() const {
    return _data;
}

template<typename T>
int node<T>::getCount() const {
    return _count;
}

template<typename T>
bool node<T>::empty() {
    return _count == 0;
}

// setters
template<typename T>
void node<T>::set(const T& data, int count) {
    _data = data;
    _count = count;
}

// ios
template<typename S>
std::ostream& operator<<(std::ostream& out, const node<S> &n) {
    out<<n.data<<" (" << n.count << ") ";
}

template<typename S>
std::istream& operator>>(std::istream& in, node<S> &n) {
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
