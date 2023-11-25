#include <iostream>
#include <cstring>
#include <memory>
#include <algorithm>

#include "SeqContainer.hpp"

using namespace std;

template <typename T>
SeqContainer<T>::SeqContainer(double factor): _factor{factor}
{
    _factor = _factor > 2 ? 2 : _factor;
    std::cout << "default constructor: " << this << std::endl;
}

template <typename T>
SeqContainer<T>::SeqContainer(double factor, size_t size, size_t cnt)
    : _factor{factor}, _size(size), _cnt(cnt)
        , ptr(_size > 0? new T [_size] : nullptr)
{
    _factor = _factor > 2 ? 2 : _factor;
    std::cout << "constructor: " << this << std::endl;
}

template <typename T>
SeqContainer<T>::SeqContainer(const SeqContainer & other)
    : SeqContainer(other._factor, other._size, other._cnt)
{

    uninitialized_copy(other.ptr, other.ptr + _cnt, ptr);
    // uninitialized_copy_n(other.ptr, _cnt, ptr);

    std::cout << "copy constructor: " << this << std::endl;
}

template <typename T>
void SeqContainer<T>::_swap(SeqContainer& other)
{
    swap(_factor, other._factor);
    swap(_size, other._size);
    swap(_cnt, other._cnt);
    swap(ptr, other.ptr);
}

template <typename T>
SeqContainer<T>& SeqContainer<T>::operator=(SeqContainer other)
{
    _swap(other);

    std::cout << "operator=: " << this << std::endl;
    return *this;
}


template <typename T>
SeqContainer<T>::SeqContainer(SeqContainer && other)
{
    _swap(other);

    other.ptr = nullptr;
    other._factor = other._size = other._cnt = 0;
    std::cout << "move constructor: " << this << std::endl;
}

template <typename T>
SeqContainer<T>::~SeqContainer()
{
    delete[] ptr;
    std::cout << "destructor: " << this << std::endl;
}


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