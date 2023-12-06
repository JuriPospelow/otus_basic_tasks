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
#ifdef DEBUG
    std::cout << "default constructor: " << this << std::endl;
#endif
}

template <typename T>
SeqContainer<T>::SeqContainer(double factor, size_t size, size_t cnt)
    : _factor{factor}, _size(size), _cnt(cnt)
        , ptr(_size > 0? new T [_size] : nullptr)
{
    _factor = _factor > 2 ? 2 : _factor;
#ifdef DEBUG
    std::cout << "constructor: " << this << std::endl;
#endif
}

template <typename T>
SeqContainer<T>::SeqContainer(const SeqContainer & other)
    : SeqContainer(other._factor, other._size, other._cnt)
{

    uninitialized_copy(other.ptr, other.ptr + _cnt, ptr);
    // uninitialized_copy_n(other.ptr, _cnt, ptr);
#ifdef DEBUG
    std::cout << "copy constructor: " << this << std::endl;
#endif
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
#ifdef DEBUG
    std::cout << "operator=: " << this << std::endl;
#endif
    return *this;
}


template <typename T>
SeqContainer<T>::SeqContainer(SeqContainer && other)
{
    _swap(other);

    other.ptr = nullptr;
    other._factor = other._size = other._cnt = 0;
#ifdef DEBUG
    std::cout << "move constructor: " << this << std::endl;
#endif
}

template <typename T>
SeqContainer<T>::~SeqContainer()
{
    delete[] ptr;
#ifdef DEBUG
    std::cout << "destructor: " << this << std::endl;
#endif
}


template <typename T>
void SeqContainer<T>::resize(size_t tmp_size)
{
    T* new_region = new T [tmp_size];
    uninitialized_copy(ptr, ptr + _cnt, new_region);
    swap(ptr, new_region);
    _size = tmp_size;
    delete [] new_region;
}

template <typename T>
void SeqContainer<T>::push_back(const T& val)
{
    size_t tmp{_size};
    if (_size < 2 || _factor <= 0) {
        ++tmp;
        resize(tmp);
    } else if (_cnt+1 >= _size) {
        tmp += tmp*_factor;
        resize(tmp);
    }
    ptr[_cnt] = val;
    ++_cnt;
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

    size_t tmp{_size};
    if (_size < 2 || _factor <= 0) {
        ++tmp;
    } else if (_cnt+1 >= _size) {
        tmp += tmp*_factor;
    }
    T* new_region = new T [tmp];
    new_region[position] = val;

    uninitialized_copy(ptr+position, ptr + _cnt+1, new_region+position+1);
    if(position != 0) uninitialized_copy(ptr, ptr+position, new_region);

    swap(ptr, new_region);
    ++_cnt;
    _size = tmp;
    delete [] new_region;
}

template <typename T>
void SeqContainer<T>::print() const
{
    for (size_t i{}; i<_cnt; ++i) {
        cout << ptr[i]<< " ";
    }
    cout << endl;
}