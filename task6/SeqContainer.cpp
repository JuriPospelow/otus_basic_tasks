#include <iostream>
#include <cstring>

#include "SeqContainer.hpp"

using namespace std;

template <typename T>
void SeqContainer<T>::push_back(const T& val)
{
    ++_size;
    // ++_iter;
    T* new_region = new T [_size];
    memcpy(new_region, ptr, (_size-1)*sizeof(T));
    new_region[_size-1] = val;
    delete[] ptr;
    ptr = new_region;
}

template <typename T>
void SeqContainer<T>::erase (const_iterator first)
{
    for (size_t i {first}; i < _size; ++i){
        ptr[i] = ptr[i+1];
    }
    --_size;
}

template <typename T>
void SeqContainer<T>::insert (const_iterator position, const T& val)
{
    if (position == _size){
        push_back(val);
        return;
    }
    ++_size;
    T* new_region = new T [_size];
    new_region[position] = val;

    memcpy(new_region+position+1, ptr+position, (_size - position -1)*sizeof(T));

    if(position != 0) memcpy(new_region, ptr, (position)*sizeof(T));

    delete[] ptr;
    ptr = new_region;
}

template <typename T>
void SeqContainer<T>::print() const
{
    for (size_t i{}; i<_size; ++i) {
        cout << ptr[i]<< " ";
    }
    cout << endl;
}