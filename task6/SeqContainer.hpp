#pragma once

using const_iterator = size_t;

template <typename T>
class SeqContainer
{
public:

explicit
    SeqContainer(double factor=0.5): _factor{factor}
    {
        _factor = _factor > 2 ? 2 : _factor;
    }

   ~SeqContainer()
    {
        delete[] ptr;
    }

    void push_back(const T& val);

    size_t size() const
    {
        return _cnt;
    }
    T& operator[] (size_t n) const
    {
        return ptr[n];
    }
    void erase (const_iterator first);

    void insert (const_iterator position, const T& val);

    void print() const;

private:
    double _factor{0.5};
    T* ptr{};
    size_t _size{};
    size_t _cnt{};
    void resize();
};

#include "SeqContainer.cpp"
