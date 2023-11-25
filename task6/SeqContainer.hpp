#pragma once

using const_iterator = size_t;

template <typename T>
class SeqContainer
{
public:

explicit
    SeqContainer(double factor=0.5);
    SeqContainer(double factor, size_t size, size_t cnt = size);
    SeqContainer(const SeqContainer&);
    SeqContainer(SeqContainer&&);
    // SeqContainer & operator=(SeqContainer && other); -> теперь его функцию выполняет обычный operator=
    SeqContainer & operator=(SeqContainer other);
   ~SeqContainer();

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
    size_t _size{};
    size_t _cnt{};
    T* ptr{};

    void _swap(SeqContainer&);
    void resize();
};

#include "SeqContainer.cpp"
