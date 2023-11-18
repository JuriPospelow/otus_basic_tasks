#include <iostream>
#include <cstring>

#include "List.hpp"

using namespace std;

template <typename T>
void List<T>::push_back(const T& val)
{
    ++_size;
    // ++_iter;
    Node* new_region = new Node [_size];
    memcpy(new_region, list, (_size-1)*sizeof(Node));
    new_region[_size-1].data = val;
    delete[] list;
    list = new_region;
    update();
}

template <typename T>
void List<T>::erase(const_iterator first)
{
    for (size_t i {first}; i < _size; ++i){
        list[i] = list[i+1];
    }
    --_size;
    update();
}

template <typename T>
void List<T>::insert(const_iterator position, const T& val)
{
    if (position == _size){
        push_back(val);
        return;
    }
    ++_size;
    Node* new_region = new Node [_size];
    new_region[position].data = val;

    memcpy(new_region+position+1, list+position, (_size - position -1)*sizeof(Node));

    if(position != 0) memcpy(new_region, list, (position)*sizeof(Node));

    delete[] list;
    list = new_region;
    update();
}

template <typename T>
void List<T>::print() const
{
    cout << "memory struct: \n";
    for (size_t i{}; i<_size; ++i) {
        // cout << list[i].data<< " ";
        cout << "node: " << i << ", data: " << list[i].data << ", ";
        cout << "addr: " << &list[i] << ", ";
        cout << "addr next node: " << (list[i].next) << ", ";
        cout << "addr prev node: " << (list[i].prev) << "\n";

    }
    cout << endl;
}

template <typename T>
void List<T>::update()
{
    for (size_t i{0}; i < _size; ++i) {
        list[i].prev = (i==0? nullptr : &list[i-1]);
        list[i].next = nullptr;
        if ( i > 0) list[i-1].next = &list[i];
    }
}
