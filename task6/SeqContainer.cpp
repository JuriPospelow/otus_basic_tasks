#include <iostream>
#include <cstring>

#include "SeqContainer.hpp"

using namespace std;

template <typename T>
void SeqContainer<T>::resize()
{
    T* new_region = new T [_size];
    memcpy(new_region, ptr, (_cnt-1)*sizeof(T));
    delete[] ptr;
    ptr = new_region;
}

template <typename T>
void SeqContainer<T>::push_back(const T& val)
{
    ++_cnt;
    if (_size < 2 || _factor <= 0) {
        ++_size;
        resize();
    } else if (_cnt >= _size) {
        _size += _size*_factor;
        resize();
    }
    ptr[_cnt-1] = val;

}

template <typename T>
void SeqContainer<T>::erase (const_iterator first)
{
    if(first >= _cnt) return;
    for (size_t i {first}; i < _cnt; ++i){
        ptr[i] = ptr[i+1];
    }
    --_cnt;
}

template <typename T>
void SeqContainer<T>::insert (const_iterator position, const T& val)
{
    if(position > _cnt) return;
    if (position == _cnt){
        push_back(val);
        return;
    }
    ++_cnt;
    if (_size < 2 || _factor <= 0) {
        ++_size;
        resize();
    } else if (_cnt >= _size) {
        _size += _size*_factor;
        resize();
    }

    T* new_region = new T [_size];
    new_region[position] = val;

    memcpy(new_region+position+1, ptr+position, (_cnt - position -1)*sizeof(T));

    if(position != 0) memcpy(new_region, ptr, (position)*sizeof(T));

    delete[] ptr;
    ptr = new_region;
}

template <typename T>
void SeqContainer<T>::print() const
{
    for (size_t i{}; i<_cnt; ++i) {
        cout << ptr[i]<< " ";
    }
    cout << endl;
}