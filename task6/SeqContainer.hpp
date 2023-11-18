#pragma once

using const_iterator = size_t;

template <typename T>
class SeqContainer
{
public:

   ~SeqContainer()
    {
        delete[] ptr;
    }

    void push_back(const T& val);

    size_t size() const
    {
        return _size;
    }
    T& operator[] (size_t n) const
    {
        return ptr[n];
    }
    void erase (const_iterator first);

    void insert (const_iterator position, const T& val);

    void print() const;

private:
    T* ptr{};
    size_t _size{};
    size_t _iter{};
};

#include "SeqContainer.cpp"
