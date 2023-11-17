#include <iostream>

using const_iterator = size_t;

template <typename T>
class Container
{
private:
    T ptr{};
    size_t _size{};
    size_t _iter{};
public:
    Container() = 0;
    virtual ~Container() = 0;
    virtual void pushback(T&) = 0;
    virtual size_t size() const
    {
        return _size;
    }
    virtual T& operator[] (size_t n)
    {
        return &ptr[n];
    }
    virtual void insert (const_iterator position, const T& val) = 0;
    virtual void erase (const_iterator first, const_iterator last);
};


int main()
{
return 0;
}
